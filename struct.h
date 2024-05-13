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