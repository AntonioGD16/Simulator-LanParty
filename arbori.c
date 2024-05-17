#include "struct.h"


int isTreeEmpty(Tree* root){
    return (root==NULL);
}

int isInterior(Tree* n){
    return (n->left != NULL && n->right != NULL);
}

int isLeaf(Tree* n){
    return (n->left == NULL && n->right == NULL);
}

Tree* newNode(Echipa v){
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->val.nume_echipa = strdup(v.nume_echipa); //folosim functia strdup pt a aloca memorie si pt a copia continutul
    node->val.nr_part = v.nr_part;
    node->val.teamPoints = v.teamPoints;
    node->val.jucator = (player*)malloc(v.nr_part * sizeof(player));
    for(int i = 0; i < v.nr_part; i++){
        node->val.jucator[i].nume = strdup(v.jucator[i].nume);
        node->val.jucator[i].prenume = strdup(v.jucator[i].prenume);
        node->val.jucator[i].points = v.jucator[i].points;
    }
    node->left = node->right = NULL;
    return node;
}
Tree* insert(Tree* node, Echipa v){
    // daca (sub)arborele este gol, creaza nod
    if(node == NULL)
        return newNode(v);
    // altfel, coboara la stanga sau dreapta
    if (v.teamPoints > node->val.teamPoints){
        node->left = insert(node->left, v);
    }
    else if (v.teamPoints < node->val.teamPoints){
        node->right = insert(node->right, v);
    }
    else if (v.teamPoints == node->val.teamPoints){
        if(strcmp(v.nume_echipa, node->val.nume_echipa) < 0){
        node->right = insert(node->right, v);
        }
        else
             node->left = insert(node->left, v);
    }
    // !pointerul node se intoarce nemodificat pe acest return
    return node;
 }

 void inordine(Tree* root, FILE* fout){
    if(root == NULL){
        return;                // conditie de iesire din recursivitate
    }
    
    inordine(root->left, fout);
    fprintf(fout, "%-33s -  %.2f\n", root->val.nume_echipa, root->val.teamPoints);
    inordine(root->right, fout);
 }