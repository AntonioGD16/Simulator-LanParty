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
    if(aux.nume_echipa == NULL){
    	exit(1);
    }
    aux.nr_part = temp->val.nr_part;
    aux.teamPoints = temp->val.teamPoints;
    aux.jucator = (player*)malloc(aux.nr_part * sizeof(player));
    if(aux.jucator == NULL){
    	exit(1);
    }
    for(int i = 0; i < aux.nr_part; i++){
        aux.jucator[i].nume = strdup(temp->val.jucator[i].nume);
        if(aux.jucator[i].nume == NULL){
    	exit(1);
        }
        aux.jucator[i].prenume = strdup(temp->val.jucator[i].prenume);
        if(aux.jucator[i].prenume == NULL){
    	exit(1);
        }
        aux.jucator[i].points = temp->val.jucator[i].points;
    }			
	stack->top = stack->top->next;      		
	free(temp);
	return aux;
}

void push(Stack* stack, Echipa team){
	Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        exit(1);
    }
	newNode->val.nume_echipa = strdup(team.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    if(newNode->val.nume_echipa == NULL){
        exit(1);
    }
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
        if(newNode->val.jucator[i].prenume == NULL){
        exit(1);
        }
        newNode->val.jucator[i].points = team.jucator[i].points;
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
