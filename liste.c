#include "liste.h"


void addTeamAtBeginning(Node** head, Echipa v){
	Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->val.nume_echipa ,v.nume_echipa);
    newNode->next = *head;
    *head = newNode;
}


void addTeamAtEnd(Node** head, Echipa v){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	strcpy(newNode->val.nume_echipa ,v.nume_echipa);
	if (*head == NULL) addTeamAtBeginning(head, v);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}

// void deleteNode(Node **head, Echipa v){	
// 	if (*head==NULL) return; 
// 	Node *headcopy = *head;
// 	if (headcopy->val == v){
// 		*head = (*head)->next;
// 		free(headcopy);
// 		return; 
// 	}
// 	Node *prev = *head;
// 	while (headcopy!=NULL){
// 		if(headcopy->val!=v){
// 			prev = headcopy;
// 			headcopy = headcopy->next;
// 		}else{
// 			prev->next = headcopy->next;
// 			free(headcopy); 
// 			return; 
// 		} 
// 	}
// }
