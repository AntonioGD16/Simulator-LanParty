#include "struct.h"


BSTNode* newNodeBST(Echipa team){
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if(node == NULL){
        exit(1);
    }
    node->val.nume_echipa = strdup(team.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    if(node->val.nume_echipa == NULL){
        exit(1);
    }
    node->val.nr_part = team.nr_part;
    node->val.teamPoints = team.teamPoints;
    node->val.jucator = (player*)malloc(team.nr_part * sizeof(player));
    if(node->val.jucator == NULL){
        exit(1);
    }
    for(int i = 0; i < team.nr_part; i++){
        node->val.jucator[i].nume = strdup(team.jucator[i].nume);
        if(node->val.jucator[i].nume == NULL){
        exit(1);
        }
        node->val.jucator[i].prenume = strdup(team.jucator[i].prenume);
        if(node->val.jucator[i].prenume == NULL){
        exit(1);
        }
        node->val.jucator[i].points = team.jucator[i].points;
    }
    node->left = node->right = NULL;
    return node;
}

AVLNode* newNodeAVL(Echipa team){
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    if(node == NULL){
        exit(1);
    }
    node->val.nume_echipa = strdup(team.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    if(node->val.nume_echipa == NULL){
        exit(1);
    }
    node->val.nr_part = team.nr_part;
    node->val.teamPoints = team.teamPoints;
    node->val.jucator = (player*)malloc(team.nr_part * sizeof(player));
    if(node->val.jucator == NULL){
        exit(1);
    }
    for(int i = 0; i < team.nr_part; i++){
        node->val.jucator[i].nume = strdup(team.jucator[i].nume);
        if(node->val.jucator[i].nume == NULL){
        exit(1);
        }
        node->val.jucator[i].prenume = strdup(team.jucator[i].prenume);
        if(node->val.jucator[i].prenume == NULL){
        exit(1);
        }
        node->val.jucator[i].points = team.jucator[i].points;
    }
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

int getHeight(AVLNode* node){
    if (node == NULL)
        return 0;
    return node->height;
}

// Functie pentru a obtine factorul de balanta al unui nod
int getBalance(AVLNode* node){
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

AVLNode* rightRotate(AVLNode* y){
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Functie pentru rotirea la stanga
AVLNode* leftRotate(AVLNode* x){
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

BSTNode* insertBST(BSTNode* node, Echipa team){
    // daca (sub)arborele este gol, creaza nod
    if(node == NULL)
        return newNodeBST(team);
    // altfel, coboara la stanga sau dreapta
    if (team.teamPoints > node->val.teamPoints){
        node->left = insertBST(node->left, team);
    }
    else if (team.teamPoints < node->val.teamPoints){
        node->right = insertBST(node->right, team);
    }
    else if (team.teamPoints == node->val.teamPoints){
        if(strcmp(team.nume_echipa, node->val.nume_echipa) < 0){
        node->right = insertBST(node->right, team);
        }
        else
             node->left = insertBST(node->left, team);
    }
    // !pointerul node se intoarce nemodificat pe acest return
    return node;
 }

AVLNode* insertAVL(AVLNode* node, Echipa team){
    if (node == NULL)
        return newNodeAVL(team);

    if (team.teamPoints > node->val.teamPoints)
        node->left = insertAVL(node->left, team);
    else if (team.teamPoints < node->val.teamPoints)
        node->right = insertAVL(node->right, team);
    else if (team.teamPoints == node->val.teamPoints){
        if(strcmp(team.nume_echipa, node->val.nume_echipa) < 0){
        node->right = insertAVL(node->right, team);
        }
        else
             node->left = insertAVL(node->left, team);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);
    
    // Cazul Stanga-Stanga
    if (balance > 1 && (team.teamPoints > node->left->val.teamPoints || 
        (team.teamPoints == node->left->val.teamPoints && strcmp(team.nume_echipa, node->left->val.nume_echipa) > 0))){
        return rightRotate(node);
    }

    // Cazul Dreapta-Dreapta
    if (balance < -1 && (team.teamPoints < node->right->val.teamPoints || 
        (team.teamPoints == node->right->val.teamPoints && strcmp(team.nume_echipa, node->right->val.nume_echipa) <= 0))){
        return leftRotate(node);
    }

    // Cazul Stanga-Dreapta
    if (balance > 1 && (team.teamPoints < node->left->val.teamPoints || 
        (team.teamPoints == node->left->val.teamPoints && strcmp(team.nume_echipa, node->left->val.nume_echipa) <= 0))){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Cazul Dreapta-Stanga
    if (balance < -1 && (team.teamPoints > node->right->val.teamPoints || 
        (team.teamPoints == node->right->val.teamPoints && strcmp(team.nume_echipa, node->right->val.nume_echipa) > 0))){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

// Functie pentru a parcurge arborele si de a umple vectorul de echipe in inordine
void inordineTraversal(BSTNode* root, Echipa* array, int* index){
    if (root != NULL) {
        inordineTraversal(root->left, array, index);
        array[(*index)++] = root->val;
        inordineTraversal(root->right, array, index);
    }
}

// Functie care transforma array in arbore AVL echilibrat
AVLNode* sortedArrayToAVL(Echipa* array, int start, int end){
    if (start > end)
        return NULL;

    int mid = (start + end)/2;
    AVLNode* node = newNodeAVL(array[mid]);

    node->left = sortedArrayToAVL(array, start, mid - 1);
    node->right = sortedArrayToAVL(array, mid + 1, end);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    return node;
}

// Functie in care fac conversia din BST in AVL
void convertBSTtoAVL(BSTree* bst, AVLTree* avl, int nr_echipe){
    Echipa* nodes = (Echipa*)malloc(nr_echipe * sizeof(Echipa));
    if(nodes == NULL){
        exit(1);
    }
    int index = 0;

    inordineTraversal(bst->root, nodes, &index);

    avl->root = sortedArrayToAVL(nodes, 0, index - 1);

    free(nodes);
}

// Functie pentru a afisa nivelul corespunzator
void printLevel(AVLNode* root, int level, FILE* fout){
    if (root == NULL)
        return;
    if (level == 0)
        fprintf(fout, "%s\n", root->val.nume_echipa);
    else if (level > 0) {
        printLevel(root->left, level - 1, fout);
        printLevel(root->right, level - 1, fout);
    }
}

// Functie pentru a afisa nodurile arborelui in ordine descrescatoare
void inordinePrint(BSTNode* root, FILE* fout){
    if(root == NULL){
        return;                // conditie de iesire din recursivitate
    }
    
    inordinePrint(root->left, fout);
    fprintf(fout, "%-33s -  %.2f\n", root->val.nume_echipa, root->val.teamPoints);
    inordinePrint(root->right, fout);

 }

 void freeBST(BSTNode* root){
    if (root == NULL) {
        return;
    }

    // Eliberam mai intai subarborii stang si drept
    freeBST(root->left);
    freeBST(root->right);

    // Apoi eliberam nodul curent
    free(root);
}

void freeAVL(AVLNode* root){
    if (root == NULL) {
        return;
    }

    // Eliberam mai intai subarborii stang si drept
    freeAVL(root->left);
    freeAVL(root->right);

    // Apoi eliberam nodul curent
    free(root);
}
