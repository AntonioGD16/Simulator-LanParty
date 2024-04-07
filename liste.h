#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void addTeamAtBeginning(Node** , Echipa );
void addTeamAtEnd(Node** ,  Echipa );
float tPoints(Echipa , int );
int deleteTeam(Node **, Echipa , int , int);