//
// Created by martin on 18/11/2015.
//

#ifndef SARACE_DICTIONARYUTILS_H
#define SARACE_DICTIONARYUTILS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "Tree.h"
#include "Parametres.h"

typedef struct word
{
    char letters[40];
    int index;
    int next;
} word;


// read a file containing 1 word per line
// fills a array of Word with the words read
// returns dicLength, the length of the dictionary
int fileToArray (const char*,word**);

// iterates through an array containing words
// adds each words to a Binary Tree
_node* arrayToTree(word **, int, int);


// iterates through the dictionary
// if match found, returns 1
// if words start with, returns 0
// if word is impossible, returns -1
int searchDictionary (_node**, char*);


void printArrayDictionary (word**,int);




#endif //SARACE_DICTIONARYUTILS_H
