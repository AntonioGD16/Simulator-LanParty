#include "struct.h"
#define MAX_NUME 50


float tPoints(Echipa team, int nr_part){
	float points;
	int k = 0;
	int i;
	for(i = 0; i < nr_part; i++){
		k = team.jucator[i].points + k;
	}
	points = (float)k/nr_part;
	return points;
}

void addTeamAtBeginning(Node** head, Echipa v){
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
    newNode->next = *head;
    *head = newNode;
}


Node* createTeamList(FILE* fin, FILE* fout, int* nr_echipe){
	Node* head;
	head = (Node*)malloc(sizeof(Node)); //alocam memorie pt capul listei si verificam daca alocarea a reusit
    if(head == NULL){
    	exit(1);
    }
    head->next = NULL;

    Echipa* teams;
    fscanf(fin, "%d", nr_echipe);
    teams = (Echipa*)malloc(*nr_echipe * sizeof(Echipa));
    if(teams == NULL){
        exit(1);
    }

    int i, j;
    char buff[100];
    for(i = 0; i < *nr_echipe; i++){
        fscanf(fin, "%d", &teams[i].nr_part);
        getc(fin); //luam enter-ul dintre numarul participantilor din echipa si numele echipei
        //Punem intr-un buffer numele echipei fara sa luam si \n de la fina;
        fscanf(fin, "%[^\n]", buff);
         int len = strlen(buff);
        buff[len - 1] = '\0'; // adagugam \0 la finalul stringului
        if(buff[len - 2] == ' ')
            buff[len - 2] = '\0'; // adagugam \0 la finalul stringului care are spatiu alb
        teams[i].nume_echipa = strdup(buff); // alocam memorie si copiem ce e in buff in teams[i].nume_echipa
        teams[i].jucator = (player*)malloc(teams[i].nr_part * sizeof(player));
        for(j = 0; j < teams[i].nr_part; j++){
            teams[i].jucator[j].nume = (char*)malloc(MAX_NUME * sizeof(char));
            if(teams[i].jucator[j].nume == NULL){
                exit(1);
            }
            teams[i].jucator[j].prenume = (char*)malloc(MAX_NUME * sizeof(char));
            if(teams[i].jucator[j].prenume == NULL){
                exit(1);
            }
            fscanf(fin, "%s", teams[i].jucator[j].nume);
            fscanf(fin, "%s", teams[i].jucator[j].prenume);
            fscanf(fin, "%d", &teams[i].jucator[j].points);
        }

        teams[i].teamPoints = tPoints(teams[i], teams[i].nr_part);
        addTeamAtBeginning(&head, teams[i]);
}
	return head;
}


int deleteTeam(Node** head, int nr_echipe, float nr_min_points) {
    Node* current = *head;
    Node* prev = NULL;
    Node* next_node;

    // Parcurgem lista și eliminăm echipele cu punctajul minim
    while(current != NULL){
        if(current->val.teamPoints == nr_min_points){
            next_node = current->next;
            if(prev == NULL){
                *head = next_node;
            }
            else{
                prev->next = next_node;
            }

            free(current);
            nr_echipe--;
            current = NULL;
            break;
        }
        else{
            prev = current;
            current = current->next;
        }
}
    return nr_echipe;
}
