#include "struct.h"


Queue* createQueue(){
	Queue* q;
	q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL) 
		return NULL;	
	q->front = q->rear = NULL;
	return q;	
}

void enQueue(Queue *q, Echipa team){
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
    }
    newNode->val.nume_echipa = strdup(team.nume_echipa);
	newNode->val.nr_part = team.nr_part;
	newNode->val.teamPoints = team.teamPoints;
	newNode->val.jucator = (player*)malloc(team.nr_part * sizeof(player));
    for(int i = 0; i < team.nr_part; i++){
        newNode->val.jucator[i].nume = strdup(team.jucator[i].nume);
        newNode->val.jucator[i].prenume = strdup(team.jucator[i].prenume);
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
	Echipa d;
	Echipa emptyTeam;
	emptyTeam.teamPoints = 0.0;
	emptyTeam.nr_part = 0;
	emptyTeam.nume_echipa = NULL;
	emptyTeam.jucator = NULL;
	if(isQueueEmpty(q)) 
		return emptyTeam;
	
	aux = q->front; 
	d.teamPoints = aux->val.teamPoints;
	d.nr_part = aux->val.nr_part;
	d.nume_echipa = strdup(aux->val.nume_echipa);
    d.jucator = malloc(d.nr_part * sizeof(player));
	for(int i = 0; i < d.nr_part; i++){
        d.jucator[i].nume = strdup(aux->val.jucator[i].nume);
		d.jucator[i].prenume = strdup(aux->val.jucator[i].prenume);
        d.jucator[i].points = aux->val.jucator[i].points;
    }

	q->front = (q->front)->next;
	free(aux);
	return d;  	
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
