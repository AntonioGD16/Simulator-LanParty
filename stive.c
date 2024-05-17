#include "struct.h"


void createStack(Stack* stack){
    stack->top = NULL;
}

int isStackEmpty(Stack stack){
	return stack.top == NULL;
}
	
void deleteStack(Node** top){
	Node* temp;
	while((*top)!=NULL){
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}	

Echipa pop(Stack* stack){
	Echipa aux;
	if (isStackEmpty(*stack)){
		aux.jucator = NULL;
		aux.nr_part = 0;
		aux.nume_echipa = NULL;
		aux.teamPoints = 0.0;
		return aux;
	}	 
	Node* temp = stack->top;  		
	aux.nume_echipa = strdup(temp->val.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    aux.nr_part = temp->val.nr_part;
    aux.teamPoints = temp->val.teamPoints;
    aux.jucator = (player*)malloc(aux.nr_part * sizeof(player));
    for(int i = 0; i < aux.nr_part; i++){
        aux.jucator[i].nume = strdup(temp->val.jucator[i].nume);
        aux.jucator[i].prenume = strdup(temp->val.jucator[i].prenume);
        aux.jucator[i].points = temp->val.jucator[i].points;
    }			
	stack->top = stack->top->next;      		
	free(temp);
	return aux;
}

void push(Stack* stack, Echipa v){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val.nume_echipa = strdup(v.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    newNode->val.nr_part = v.nr_part;
    newNode->val.teamPoints = v.teamPoints;
    newNode->val.jucator = (player*)malloc(v.nr_part * sizeof(player));
    for(int i = 0; i < v.nr_part; i++){
        newNode->val.jucator[i].nume = strdup(v.jucator[i].nume);
        newNode->val.jucator[i].prenume = strdup(v.jucator[i].prenume);
        newNode->val.jucator[i].points = v.jucator[i].points;
    }
	newNode->next = stack->top;
	stack->top = newNode;
}

void printStack(Stack stack, FILE* fout){
    Node* current = stack.top;  // Pointer catre varful stivei

    // Parcurgem stiva si afisam fiecare element în fisierul de iesire
    while (current != NULL) {
        fprintf(fout, "%-33s -  %.2f\n", current->val.nume_echipa, current->val.teamPoints);
        current = current->next;
    }
}

void copyStack(Stack source, Stack* destination) {
    // Verificăm dacă stiva sursă este goală
    if (isStackEmpty(source)) {
        printf("Source stack is empty.\n");
        return;
    }

    // Parcurgem stiva sursă și adăugăm elementele în stiva destinație
    Node* current = source.top;
    while (current != NULL) {
        push(destination, current->val);
        current = current->next;
    }
}
