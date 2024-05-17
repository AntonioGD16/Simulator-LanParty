#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structurile pe care le folosesc
typedef struct{
        char* nume;
        char* prenume;
        int points;
}player;

typedef struct team{
        char* nume_echipa;
        int nr_part;
        float teamPoints;
        player* jucator;
}Echipa;

typedef struct Elem{
        Echipa val;
        struct Elem* next;
}Node;

typedef struct Q{
        Node* front;
        Node* rear;
}Queue;

typedef struct stiva{
        Node* top;
}Stack;

typedef struct arbore{
        Echipa val;
        struct arbore* left;
        struct arbore* right;
}Tree;

// Functiile taskurilor
void task1(FILE* , FILE*);
Node* task2(FILE* , FILE*);
Stack task3(FILE* , FILE*);
void task4(FILE* , FILE*);

// Functii pentru liste
void addTeamAtBeginning(Node** , Echipa );
void addTeamAtEnd(Node** ,  Echipa );
float tPoints(Echipa , int );
int deleteTeam(Node** , int , float);
Node* createTeamList(FILE* , FILE* , int*);

// Functii pentru cozi
Queue* createQueue();
void enQueue(Queue* , Echipa );
Echipa deQueue(Queue* );
int isQueueEmpty(Queue* );
void deleteQueue(Queue* );

// Functii pentru stive
void createStack();
void playMatches(Queue* , Stack* , Stack* , FILE* , int , int , int*);
int isStackEmpty(Stack );
Echipa pop(Stack* );
void push(Stack* , Echipa );
void printStack(Stack , FILE*);
void deleteStack(Node** );
void copyStack(Stack , Stack* );

// Functii pentru arbori
void initTree(Tree* );
Tree* insert(Tree* , Echipa );
Tree* newNode(Echipa );
void inordine(Tree* , FILE*);