//
// Created by martin on 16/11/2015.
//
// set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

#include "GridUtils.h"

int main (void)
{

    word* dictionary[320000];
    int length = 0;

    _node* root = NULL;
    _node** tree =&root;

    length = fileToArray ("C:\\Users\\martin\\Desktop\\dico.txt",dictionary);

    *tree = arrayToTree (dictionary,0,length);
    printf ("fin ajout dans arbre\n");

    char* grille[4];

    char* grille1 = "setr";
    char* grille2 = "snrs";
    char* grille3 = "vecu";
    char* grille4 = "mglu";

    grille[0] = grille1;
    grille[1] = grille2;
    grille[2] = grille3;
    grille[3] = grille4;


    table* t = findAllWords(tree,grille);

    tablePrint(t);




    return 0;
}