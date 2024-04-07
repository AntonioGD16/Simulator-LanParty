#include "liste.h"
#include <limits.h>
#include <math.h>
#define MAX_NUME 50
#define MAX_NR_FILE 15


int main(int argc, char* argv[]){
    // FILE* fin, *fout;
    // fin = fopen(argv[2], "rb");
    // if(fin == NULL){
    //     exit(1);
    // }
    // fout = fopen(argv[3], "wb");
    // if(fout == NULL){
    //     exit(1);
    // }

    int filenr;
    for(filenr = 1; filenr<=MAX_NR_FILE; filenr++){
            switch (filenr){
            // Task 1
            case 1:
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
                head = (Node*)malloc(sizeof(Node)); //alocam memorie pt capul listei si verificam daca alocarea a reusit
                if(head == NULL){
                    exit(1);
                }
                head->next = NULL;

                Echipa* teams;
                int nr_echipe;
                fscanf(fin, "%d", &nr_echipe);
                teams = (Echipa*)malloc(nr_echipe * sizeof(Echipa));
                if(teams == NULL){
                    exit(1);
                }

                int i, j;
                for (i = 0; i < nr_echipe; i++) {
                    fscanf(fin, "%d", &teams[i].nr_part);
                    getc(fin); //luam enter-ul dintre numarul participantilor din echipa si numele echipei
                    teams[i].nume_echipa = (char*)malloc(MAX_NUME * sizeof(char));
                    if(teams[i].nume_echipa == NULL){
                        exit(1);
                    }
                    fgets(teams[i].nume_echipa, MAX_NUME, fin);
                    teams[i].jucator = (player*)malloc(teams[i].nr_part * sizeof(player));
                        for(j = 0; j<teams[i].nr_part; j++){
                            teams[i].jucator[j].nume = (char*)malloc(MAX_NUME * sizeof(char));
                            if(teams[i].jucator[j].nume == NULL){
                                exit(1);
                            }
                            teams[i].jucator[j].prenume = (char*)malloc(MAX_NUME * sizeof(char));
                            if(teams[i].jucator[j].prenume == NULL){
                                exit(1);
                            }
                            fscanf(fin, "%s", teams[i].jucator[j].nume);
                            fscanf(fin, "%s", teams[i].jucator[j].prenume);
                            fscanf(fin, "%d", &teams[i].jucator[j].points);
                        }

                        teams[i].teamPoints = tPoints(teams[i], teams[i].nr_part);
                    addTeamAtBeginning(&head, teams[i]);
                }


                Node* hc;
                for(hc = head; hc != NULL; hc = hc->next){
                        if (hc->val.nume_echipa != NULL){
                        fputs(hc->val.nume_echipa, fout);
                        }
                }
                break;
            
            // Task 2
            case 2:
            fin = fopen(argv[2], "rb");
            if(fin == NULL){
                exit(1);
            }
            fout = fopen(argv[3], "wb");
            if(fout == NULL){
                exit(1);
            }

            int n; //nr de echipe dupa eliminarea echipelor cu punctaj mic
            n = nr_echipe;
            // n trebuie sa fie maxim si sa fie o putere a lui 2
            while(n > pow(2, (nr_echipe / (int)sqrt(nr_echipe)) - 1)){
                n--;
            }
            
            int nr_min_points = INT_MAX;

            // aflam nr minim de puncte al unei echipe, stergem echipele care au nr minim de puncte si parcurgem iar lista pana cand nr de echipe devine cel dorit adica n
            while(nr_echipe > n){
            for(hc = head; hc != NULL; hc = hc->next){
                        if (hc->val.teamPoints <= nr_min_points){
                        nr_min_points = hc->val.teamPoints;
                        }
                }

            for(hc = head; hc != NULL; hc = hc->next){
                        if (hc->val.teamPoints == nr_min_points){
                        nr_echipe = deleteTeam(&hc, hc->val, nr_echipe, nr_min_points);
                        }
                }  
            }  






            break;

            // case 3:

            // break;
            // case 4:

            // break;
            // case 5:

            // break;
            // case 6:

            // break;
            // case 7:

            // break;
            // case 8:

            // break;
            // case 9:

            // break;
            // case 10:

            // break;
            // case 11:

            // break;
            // case 12:

            // break;
            // case 13:

            // break;
            // case 14:

            // break;
            // case 15:

            // break;
            }

        }
        
    


    return 0;
}