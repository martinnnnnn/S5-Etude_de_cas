//
// Created by martin on 18/11/2015.
//

#ifndef SARACE_GRIDUTILS_H
#define SARACE_GRIDUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#include "DictionaryUtils.h"
#include "Parametres.h"


/********************************************************/

typedef struct position
{
    int x;
    int y;
} position;

typedef struct stack
{
    position* array[SIZE_MAX_STACK];
    int current;

} stack;


stack* stackNew (void);

void stackPush (stack*,struct position*);

void stackPop (stack*);

position* stackTop (stack*);

int stackFind (stack*,position*);

void stackClear (stack*);

void stackPrint (stack*);

/********************************************************/
/********************************************************/

//TODO change list to hashtable
typedef struct table
{
    char* words[SIZE_MAX_TABLE];
    int current;

} table;

table* tableNew (void);

void tableAdd (table*,char*);

char* tableGet (table*,int);

int tableSize (table*);

int tableFind (table*,char*);

void tableClear (table*);

void tablePrint (table*);

/********************************************************/
/********************************************************/

typedef struct neighbors
{
    position* positions[SIZE_MAX_NEIGH];
    int current;

} neighbors;

neighbors* neighNew (void);

void neighAdd (neighbors*, position*);

int neighSize (neighbors*);

void neighClear (neighbors*);

void neighPrint (neighbors*);

/********************************************************/
/********************************************************/

int max(int,int);
int min(int,int);

neighbors* getNeighbors (position*);

void looking (_node**, char**, char*, stack*, table*);

table* findAllWords (_node**, char**);


#endif //SARACE_GRIDUTILS_H
