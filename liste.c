#include "liste.h"


float tPoints(Echipa team, int nr_part){
	float points;
	int k = 0;
	int i;
	for(i = 0; i<nr_part; i++){
		k = team.jucator[i].points + k;
	}
	points = k/nr_part;
	return points;
}

void addTeamAtBeginning(Node** head, Echipa v){
	Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val.nume_echipa = strdup(v.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    newNode->next = *head;
    *head = newNode;
}


void addTeamAtEnd(Node** head, Echipa v){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	newNode->val.nume_echipa = strdup(v.nume_echipa);
	if (*head == NULL) addTeamAtBeginning(head, v);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}

int deleteTeam(Node **head, Echipa v, int nr_echipe, int nr_min_points){	
	if (*head==NULL){
	nr_echipe--;
	return nr_echipe;
	} 
	Node *headcopy = *head;
	if (headcopy->val.teamPoints == v.teamPoints){
		*head = (*head)->next;
		free(headcopy);
		nr_echipe--;
		return nr_echipe; 
	}
	Node *prev = *head;
	while (headcopy!=NULL){
		if(headcopy->val.teamPoints != nr_min_points){
			prev = headcopy;
			headcopy = headcopy->next;
		}else if(headcopy->val.teamPoints == nr_min_points){
			prev->next = headcopy->next;
			free(headcopy); 
			nr_echipe--;
			return nr_echipe; 
		} 
	}
	return nr_echipe;
}