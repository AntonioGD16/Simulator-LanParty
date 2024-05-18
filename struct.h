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

typedef struct AVLNode{
        Echipa val;
        struct AVLNode* left;
        struct AVLNode* right;
        int height;
}AVLNode;

typedef struct BSTNode{
        Echipa val;
        struct BSTNode* left;
        struct BSTNode* right;
}BSTNode;

typedef struct AVLTree{
        AVLNode* root;
}AVLTree;

typedef struct BSTree{
        BSTNode* root;
}BSTree;

// Functiile taskurilor
void task1(FILE* , FILE*);
Node* task2(FILE* , FILE*);
Stack task3(FILE* , FILE*);
BSTree task4(FILE* , FILE*);
void task5(FILE* , FILE*);

// Functii pentru liste
void addTeamAtBeginning(Node** , Echipa ); // adaugam echipa la inceputul listei
float tPoints(Echipa , int ); // calculez punctele echipei
int deleteTeam(Node** , int , float); // stergem echipele respective
Node* createTeamList(FILE* , FILE* , int*); // punem echipele in lista

// Functii pentru cozi
Queue* createQueue();
void enQueue(Queue* , Echipa );
Echipa deQueue(Queue* );
int isQueueEmpty(Queue* );
void deleteQueue(Queue* );

// Functii pentru stive
void createStack(Stack* );
void playMatches(Queue* , Stack* , Stack* , FILE* , int , int , int*);
int isStackEmpty(Stack );
Echipa pop(Stack* );
void push(Stack* , Echipa );
void printStack(Stack , FILE*);
void deleteStack(Node** );

// Functii pentru arbori
BSTNode* insertBST(BSTNode* , Echipa );
BSTNode* newNodeBST(Echipa );
void inordinePrint(BSTNode* , FILE*);
AVLNode* newNodeAVL(Echipa );
int getHeight(AVLNode* );
int getBalance(AVLNode* );
int max(int , int );
AVLNode* rightRotate(AVLNode* );
AVLNode* leftRotate(AVLNode* );
AVLNode* insertAVL(AVLNode* , Echipa );
void inordineTraversal(BSTNode* , Echipa* , int* );
AVLNode* sortedArrayToAVL(Echipa* , int , int );
void convertBSTtoAVL(BSTree* , AVLTree* , int );
void printLevel(AVLNode* , int , FILE* );
void freeAVL(AVLNode* );
void freeBST(BSTNode* );
