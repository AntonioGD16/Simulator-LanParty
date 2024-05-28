#include "struct.h"
#include <float.h> // pt ca am folosit FLT_MAX
#include <math.h> // pt ca am folosit log2 si pow


void playMatches(Queue* q, Stack* winnersStack, Stack* losersStack, FILE* fout, int i, int nr_runde, int *nr_echipe){
    while(!isQueueEmpty(q)){
        // Extrage primele doua echipe din coada pentru un meci
        Echipa echipa1 = deQueue(q);
        Echipa echipa2 = deQueue(q);

        // Simularea meciului si actualizarea punctajelor
        if(echipa1.teamPoints > echipa2.teamPoints){
            echipa1.teamPoints += 1;
            push(winnersStack, echipa1);
            push(losersStack, echipa2);
        } 
        else{
            echipa2.teamPoints += 1;
            push(winnersStack, echipa2);
            push(losersStack, echipa1);
        }
    }

    *nr_echipe = (*nr_echipe)/2;
    // Afisare echipa castigatoare
    fprintf(fout, "WINNERS OF ROUND NO:%d\n", i + 1);
        printStack(*winnersStack, fout);
    if((i + 1) != nr_runde) // i + 1 pt ca i e de la 0 si folosim acest if pt a nu adauga la finalul fisierului 2 linii noi
        fprintf(fout, "\n");
}

    
void task1(FILE* fin, FILE* fout){
	Node* head = NULL;
	int nr_echipe;
	head = createTeamList(fin, fout, &nr_echipe);
	Node* hc = head;

    while(hc != NULL){
        if (hc->val.nume_echipa != NULL){
            fputs(hc->val.nume_echipa, fout);
            fputs("\n", fout);
    }
    hc = hc->next;
    }

    while(head != NULL){
        free(head);                  // Eliberam memoria pentru lista
        head = head->next;
    }
    head = NULL;
    hc = NULL;
}

Node* task2(FILE* fin, FILE* fout){
    Node* head = NULL;
    int nr_echipe;
    head = createTeamList(fin, fout, &nr_echipe);
    int newNr_echipe; // nr de echipe dupa eliminarea echipelor cu punctaj mic
    newNr_echipe = nr_echipe;
    // newNr trebuie sa fie maxim si sa fie o putere a lui 2
    while(newNr_echipe > (int)pow(2, (int)log2(nr_echipe))){
        newNr_echipe--;
    }
    float nr_min_points = FLT_MAX;
    // aflam nr minim de puncte al unei echipe, stergem echipele care au nr minim de puncte si parcurgem iar lista pana cand nr de echipe devine cel dorit adica n
    while(nr_echipe >= newNr_echipe){
        nr_min_points = FLT_MAX;
        Node* hc = head;
        while(hc != NULL){
            if (hc->val.teamPoints < nr_min_points){
                nr_min_points = hc->val.teamPoints;
            }
            hc = hc->next;
        }
        nr_echipe = deleteTeam(&head, nr_echipe, nr_min_points);
    }

    // scrierea in fisier a numelor echipelor ramase în lista
    Node* hc = head;
    while(hc != NULL){
        if(hc->val.nume_echipa != NULL){
            fputs(hc->val.nume_echipa, fout);
            fputs("\n", fout);
        }
        hc = hc->next;
    }

    return head;
}

Stack task3(FILE* fin, FILE* fout){
    Node* head = task2(fin, fout);
    
    fprintf(fout, "\n");
    
    int nr_echipe = 0;
    Node* hc = head;
    while(hc != NULL){
        nr_echipe++;
        hc = hc->next;
    }
    int nr_runde = (int)log2(nr_echipe);
    
    Queue* q = createQueue();
    hc = head;
    while(hc != NULL){
       enQueue(q, hc->val);
       hc = hc->next;
    }
    
    Stack winnersStack;
    createStack(&winnersStack);
    Stack losersStack;
    createStack(&losersStack);
    Stack temp;
    createStack(&temp);
    for(int i = 0; i < nr_runde; i++){
        fprintf(fout, "--- ROUND NO:%d\n", i + 1);
        hc = q->front;
        while(hc != NULL){
            fprintf(fout, "%-32s - %32s\n", hc->val.nume_echipa, hc->next->val.nume_echipa);
            hc = hc->next->next;
        }

        fprintf(fout, "\n");
        playMatches(q, &winnersStack, &losersStack, fout, i,  nr_runde, &nr_echipe);      
    
        while(!isStackEmpty(losersStack)){
            pop(&losersStack);
        }
    
        while(!isStackEmpty(winnersStack)){
            if(nr_echipe == 8){
                Node* current = winnersStack.top;
                while(current != NULL){
                    push(&temp, current->val);
                    current = current->next;
                    break;
                }
            }
            Echipa aux = pop(&winnersStack);
            enQueue(q, aux);
        }
    }
    deleteQueue(q);
    q->front = q->rear = NULL;
    deleteStack(&winnersStack.top);  // eliberam memoria pentru coada si stive
    winnersStack.top = NULL;
    deleteStack(&losersStack.top);
    losersStack.top = NULL;
    while(head != NULL){
        free(head);                  // Eliberam memoria pentru lista
        head = head->next;
    }
    head = NULL;
    hc = NULL;

    return temp;
}

BSTree task4(FILE* fin, FILE* fout){
    Stack top_8;
    top_8 = task3(fin, fout);
    fprintf(fout, "\nTOP 8 TEAMS:\n");
    BSTree top8;
    top8.root = NULL;
    Node* current = top_8.top;
    while(current != NULL){
       top8.root = insertBST(top8.root, current->val);
       current = current->next;
    }
    inordinePrint(top8.root, fout);

    current = NULL;
    top_8.top = NULL;

    return top8;
}

void task5(FILE* fin, FILE* fout){
    BSTree top_8 = task4(fin, fout);
    fprintf(fout, "\nTHE LEVEL 2 TEAMS ARE: \n");
    AVLTree top8;
    top8.root = NULL;
    convertBSTtoAVL(&top_8, &top8, 8);  // numarul de echipe este 8 si stim asta de la taskul anterior
    printLevel(top8.root, 2, fout); // 2 reprezinta nivelul pe care se afla nodurile pe care le afisez

    freeAVL(top8.root);
    freeBST(top_8.root);

}
