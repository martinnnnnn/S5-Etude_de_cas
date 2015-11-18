//
// Created by martin on 16/11/2015.
//



#include "Tree.h"


int _startsWith(const char* str, const char* pre)
{
    if (strlen(pre) < strlen(str))
    {
        if(strncmp(str, pre, strlen(pre)) == 0) return 1;
    }

    return 0;
}


/***************************************************************************/

_node* newNode(char* word)
{
    _node* node = (_node*) malloc(sizeof(_node));
    strcpy(node->word,word);
    node->left = NULL;
    node->right = NULL;

    return node;
}


/***************************************************************************/

void addNode(_node **tree, char* word)
{
    _node *tmpNode;
    _node *tmpTree = *tree;

    _node *elem = newNode(word);

    if(tmpTree)
        do
        {
            tmpNode = tmpTree;
            if(strcmp(word,tmpTree->word) > 0)
            {
                tmpTree = tmpTree->right;
                if(!tmpTree) tmpNode->right = elem;
            }
            else
            {
                tmpTree = tmpTree->left;
                if(!tmpTree) tmpNode->left = elem;
            }
        }
        while(tmpTree);
    else  *tree = elem;
}

/***************************************************************************/

int searchNode(_node *tree, char* word)
{
    while(tree)
    {
        if(strcmp(word,tree->word) == 0) return 1;

        if(strcmp(word,tree->word) > 0)
        {
            if (!tree->right && _startsWith(tree->word,word)) return 0;
            tree = tree->right;
        }
        else
        {
            if (!tree->left && _startsWith(tree->word,word)) return 0;
            tree = tree->left;
        }
    }
    return -1;
}

/***************************************************************************/

void printTree(_node *tree)
{
    if(!tree) return;

    if(tree->left)  printTree(tree->left);

    printf("Mot : %s\n", tree->word);

    if(tree->right) printTree(tree->right);
}

/***************************************************************************/

void clearTree(_node **tree)
{
    _node *tmpTree = *tree;

    if(!tree) return;

    if(tmpTree->left)  clearTree(&tmpTree->left);

    if(tmpTree->right) clearTree(&tmpTree->right);

    free(tmpTree);

    *tree = NULL;
}