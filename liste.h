#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char nume[50];
        char prenume[50];
        int points;
}player;

typedef struct team{
        char nume_echipa[50];
        int nr_part;
        player* jucator;
}Echipa;

typedef struct Elem{
        Echipa val;
        struct Elem* next;
}Node;


void addTeamAtBeginning(Node** , Echipa );
// void addAtBeginning(Node**, Echipa v);
// void addAtEnd(Node**, Echipa);
// void deleteNode(Node **, Echipa);
