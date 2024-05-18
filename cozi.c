#include "struct.h"


Queue* createQueue(){
	Queue* q;
	q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL){
		exit(1);
	}	
	q->front = q->rear = NULL;
	return q;	
}

void enQueue(Queue *q, Echipa team){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        exit(1);
    }
    newNode->val.nume_echipa = strdup(team.nume_echipa);  //folosim functia strdup pt a aloca memorie si pt a copia continutul
	newNode->val.nr_part = team.nr_part;
	newNode->val.teamPoints = team.teamPoints;
	newNode->val.jucator = (player*)malloc(team.nr_part * sizeof(player));
	 if(newNode->val.jucator == NULL){
        exit(1);
     }
    for(int i = 0; i < team.nr_part; i++){
        newNode->val.jucator[i].nume = strdup(team.jucator[i].nume);
		if(newNode->val.jucator[i].nume == NULL){
    	exit(1);
    	}
        newNode->val.jucator[i].prenume = strdup(team.jucator[i].prenume);
		if(newNode->val.jucator[i].nume == NULL){
    	exit(1);
    	}
        newNode->val.jucator[i].points = team.jucator[i].points;
    }
    newNode->next = NULL;

    if(isQueueEmpty(q)){
        q->front = q->rear = newNode;
    } 
	else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
 
Echipa deQueue(Queue* q){  
	Node* aux;
	Echipa team;
	Echipa emptyTeam;
	emptyTeam.teamPoints = 0.0;
	emptyTeam.nr_part = 0;
	emptyTeam.nume_echipa = NULL;
	emptyTeam.jucator = NULL;
	if(isQueueEmpty(q)) 
		return emptyTeam;
	
	aux = q->front; 
	team.teamPoints = aux->val.teamPoints;
	team.nr_part = aux->val.nr_part;
	team.nume_echipa = strdup(aux->val.nume_echipa);
	if(team.nume_echipa == NULL){
    	exit(1);
    }
    team.jucator = malloc(team.nr_part * sizeof(player));
	if(team.jucator == NULL){
    	exit(1);
    }
	for(int i = 0; i < team.nr_part; i++){
        team.jucator[i].nume = strdup(aux->val.jucator[i].nume);
		if(team.jucator[i].nume == NULL){
    	exit(1);
    	}
		team.jucator[i].prenume = strdup(aux->val.jucator[i].prenume);
		if(team.jucator[i].prenume == NULL){
    	exit(1);
    	}
        team.jucator[i].points = aux->val.jucator[i].points;
    }

	q->front = (q->front)->next;
	free(aux);
	return team;  	
} 

int isQueueEmpty(Queue* q){
	return (q->front == NULL);
}

void deleteQueue(Queue* q){
	Node* aux;
	while(!isQueueEmpty(q)){
		aux = q->front;
		q->front = q->front->next;
		free(aux);
	}
	free(q);
}
