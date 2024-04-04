#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"



int main(int argc, char* argv[]){
    FILE* fin, *fout;
    fin = fopen(argv[2], "rb");
    if(fin == NULL){
        exit(1);
    }
    fout = fopen(argv[3], "wb");
    if(fout == NULL){
        exit(1);
    }

    Node* head;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    int nr_echipe;
    fscanf(fin, "%d", &nr_echipe);
   // printf("%d", nr_echipe);

    Echipa* teams;
    int i, j;
    teams = (Echipa*)malloc(nr_echipe * sizeof(Echipa));
     for (i = 0; i < nr_echipe; i++) {
        fscanf(fin, "%d", &teams[i].nr_part);
        getc(fin);
        fgets(teams[i].nume_echipa, 50, fin);
        teams[i].jucator = (player*)malloc(teams[i].nr_part * sizeof(player));
            for(j = 0; j<teams[i].nr_part; j++){
                fscanf(fin, "%s", teams[i].jucator[j].nume);
                fscanf(fin, "%s", teams[i].jucator[j].prenume);
                fscanf(fin, "%d", &teams[i].jucator[j].points);
            }

        addTeamAtBeginning(&head, teams[i]);
    }


    Node* hc;
    int k = 0;
    for(hc = head; hc != NULL; hc = hc->next){
            fputs(hc->val.nume_echipa, fout);
            k++;
    }


    //  for (i = 0; i < nr_echipe; i++) {
    //     printf("Team %d\n", i + 1);
    //     printf("Number of participants: %d\n", teams[i].nr_part);
    //     printf("Team name: %s", teams[i].nume_echipa);
    //         for(j = 0; j<teams[i].nr_part; j++){
    //             printf("Player: %s %s, Points: %d\n", teams[i].jucator[j].nume, teams[i].jucator[j].prenume, teams[i].jucator[j].points);
    //         }
    // }

    return 0;
}