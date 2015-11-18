//
// Created by martin on 17/11/2015.
//

#include "GridUtils.h"





stack* stackNew (void)
{
    stack* s = (stack*) malloc(sizeof(stack));
    s->current = -1;

    return s;
}

/********************************************************/

void stackPush (stack* s,position* p)
{
    if (s->current < SIZE_MAX_STACK)
    {
        ++(s->current);
        s->array[s->current] = p;
    }
}

/********************************************************/

void stackPop (stack* s)
{
    if (s->current > -1) --(s->current);
}

/********************************************************/

position* stackTop (stack* s)
{
    if (s->current > -1) return s->array[s->current];
    printf ("!!! erreur dans la pile !!!");
    exit(3);
}

/********************************************************/

int stackFind (stack* s,position* p)
{
    if (s->current > -1)
    {
        int i = 0;
        for (i ;i <= s->current; ++i)
        {
            if ( (s->array[i]->x == p->x) && (s->array[i]->y == p->y) ) return 1;
        }
    }
    return 0;
}

/********************************************************/

void stackClear (stack* s)
{
    //TODO faire fonction stackClear
}

/********************************************************/

void stackPrint (stack* s)
{
    int i;
    for (i = 0; i < s->current; ++i)
    {
        printf("%i : %i/%i", i, s->array[i]->x,s->array[i]->y);
    }
}

/********************************************************/
/********************************************************/

table* tableNew (void)
{
    table* t = (table*) malloc(sizeof(table));
    t->current = -1;

    return t;
}

void tableAdd (table* t, char* s)
{
    if (t->current < SIZE_MAX_TABLE)
    {
        ++(t->current);
        strcpy(t->words[t->current],s);
    }
}

char* tableGet (table* t, int i)
{
    if (i > -1 && i <= t->current) return t->words[i];
    return "";
}

int tableSize (table* t)
{
    return t->current;
}

int tableFind (table* t, char* s)
{
    if (t->current > -1)
    {
        int i = 0;
        for (i ; i <= t->current; ++i)
        {
            if (strcmp(t->words[i],s) == 0) return 1;
        }
    }
    return 0;
}

void tableClear (table* t)
{

}

void tablePrint (table* t)
{
    int i;
    for (i = 0; i < t->current; ++i)
    {
        printf("%i : %s\n", i, t->words[i]);
    }
}


/********************************************************/
/********************************************************/


neighbors* neighNew (void)
{
    neighbors* n = (neighbors*) malloc(sizeof(neighbors));
    n->current = -1;

    return n;
}

void neighAdd (neighbors* n, position* p)
{
    if (n->current < SIZE_MAX_NEIGH)
    {
        ++(n->current);
        n->positions[n->current] = p;
    }
}

position* neighGet (neighbors* n, int i)
{
    if (i > -1 && i <= n->current) return n->positions[i];
    printf ("!!! mauvais index pour les voisins !!!");
    exit(3);
}


int neighSize (neighbors* n)
{
    return n->current + 1;
}

// TODO neight : clear
void neighClear (neighbors*);
// TODO neight : print
void neighPrint (neighbors*);


/********************************************************/
/********************************************************/

// TODO transformer en define
int max(int a,int b)
{
    return (a > b) ? a : b;
}


// TODO transformer en define
int min(int a, int b)
{
    return (a < b) ? a : b;
}

/********************************************************/

neighbors* getNeighbors (position* p)
{
    neighbors* positions = neighNew();

    int x_min = max(0,p->x-1);
    int x_max = min(4,p->x+1);
    int y_max = max(0,p->y-1);
    int y_min = min(4,p->y+1);

    int i = 0;
    int j = 0;
    int k = 0;

    for (i = x_min; i <= x_max; ++i)
    {
        for (j = y_min; j <= y_max; ++j)
        {
            position* p = malloc(sizeof(position));
            p->x = i;
            p->y = j;
            neighAdd(positions,p);

            ++k;
        }
    }

    return positions;
}



/********************************************************/

void looking (_node** tree, char** grid, char* string, stack* stack, table* allWords)
{
    int f = searchDictionary(tree,string);
    int i;

    if (f != -1)
    {
        if (f) tableAdd(allWords,string);
        stackPrint(stack);
        neighbors* n = getNeighbors (stackTop(stack));

        for (i = 0; i < neighSize(n); ++i)
        {
            position* newPos = neighGet(n,i);
            if (!stackFind(stack,newPos))
            {
                stackPush(stack,newPos);
                char newString[strlen(string)+1];
                strcpy(newString,string);
                strcat(newString,&(grid[newPos->x][newPos->y]));

                looking(tree,grid,newString,stack,allWords);
            }
        }
    }
}

/********************************************************/

table* findAllWords (_node** tree, char** grid)
{
    table* allWords = tableNew();

    int i;
    int j;
    for (i = 0; i < SIZE_MAX_GRID; ++i)
    {
        for (j = 0; j < SIZE_MAX_GRID; ++j)
        {
            if (DEBUG) tablePrint(allWords);
            position* p = malloc(sizeof(position));
            p->x = i;
            p->y = j;
            stack* s = stackNew();
            stackPush(s,p);
            looking (tree, grid, &(grid[i][j]), s, allWords);
        }
    }

}