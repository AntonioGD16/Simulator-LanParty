#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


void addTeamAtBeginning(Node** , Echipa );
void addTeamAtEnd(Node** ,  Echipa );
float tPoints(Echipa , int );
int deleteTeam(Node **, int , float);
Node* createTeamList(FILE* , FILE*, int*);
void task1(FILE*, FILE*);
void task2(FILE*, FILE*);