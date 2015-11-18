//
// Created by martin on 18/11/2015.
//

#ifndef SARACE_TREE_H
#define SARACE_TREE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parametres.h"


typedef struct _node
{
    char word[40];
    struct _node *left;
    struct _node *right;

} _node;

// tells us if the second string parameter is the beginning of the first string parameter
int _startsWith(const char*, const char*);


_node* newNode(char*);

void addNode(_node **tree, char* word);

int searchNode(_node *tree, char* word);

void printTree(_node *tree);

void clearTree(_node **tree);


#endif //SARACE_TREE_H
