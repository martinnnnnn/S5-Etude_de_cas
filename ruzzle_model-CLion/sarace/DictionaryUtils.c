//
// Created by martin on 16/11/2015.
//

#include "DictionaryUtils.h"


int fileToArray (const char* PATH, word** dictionary)
{

    if (DEBUG) printf ("FONCTION D'AJOUT D'UN FICHIER DICTIONNAIRE VERS UNE LISTE DE MOTS : \n");

    FILE * fp;
    word* newWord;
    int dicLength = 0;

    if (DEBUG) printf ("> Ouverture du fichier\n");
    // ouverture fichier
    fp = fopen(PATH, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    char buf[256];

    if (DEBUG) printf ("> Lecture de chaque mot\n");
    while (fgets (buf, sizeof(buf), fp)) {
        strtok(buf,"\n");
        newWord = malloc(sizeof(word));
        strcpy(newWord->letters,buf);
        newWord->index = dicLength;
        newWord->next = dicLength;

        dictionary[dicLength] = newWord;

        ++dicLength;
    }

    // fermeture fichier
    fclose(fp);

    if (DEBUG) printf ("FIN DE LA LECTURE\n\n");

    return ++dicLength;
}


/***************************************************************************/

_node* arrayToTree(word **array, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    _node* root = newNode(array[mid]->letters);

    root->left = arrayToTree(array, start, mid - 1);
    root->right = arrayToTree(array, mid + 1, end);
    return root;
}


/***************************************************************************/

int searchDictionary (_node** tree, char* word)
{
    return searchNode(*tree,word);
}


/***************************************************************************/

void printArrayDictionary (word** dictionary, int dicLength)
{
    if (DEBUG) printf ("AFFICHAGE DE LA LISTE DE MOT REPRESENTANT LE DICTIONNAIRE... \n");

    int i = 0;

    for (i; i <= dicLength; i++)
    {
        printf ("%s : %i %i \n",dictionary[i]->letters,dictionary[i]->index,dictionary[i]->next);
    }

    if (DEBUG) printf ("FIN DE L'AFFICHAGE\n\n");
}
