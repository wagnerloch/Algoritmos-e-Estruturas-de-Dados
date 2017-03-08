/*
**
**   ÁRVORE BINÁRIA
**   WAGNER LOCH
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode (TreeNodePtr *treePtr, int value);
void inOrder (TreeNodePtr treePtr);
void preOrder (TreeNodePtr treePtr);
void postOrder (TreeNodePtr treePtr);

int main()
{
    int i;
    int item;
    TreeNodePtr rootPrt = NULL;

    srand (time(NULL));
    printf ("Os numeros sendo colocados na arvore sao:\n");

    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf ("%3d", item);
        insertNode(&rootPrt, item);
    }

    printf ("\n\nA travessia na pre-ordem e:\n");
    preOrder(rootPrt);

    printf ("\n\nA travessia na ordem e:\n");
    inOrder(rootPrt);

    printf ("\n\nA travessia na pos-ordem e:\n");
    postOrder(rootPrt);
    return 0;
}

void insertNode (TreeNodePtr *treePtr, int value) {
    if (*treePtr == NULL) {
        *treePtr = malloc (sizeof (TreeNode));

        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf ("%d nao inserido. Sem memoria!\n\n", value);
        }
    }
    else {
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else {
            printf (" duplicado");
        }
    }
}
void inOrder (TreeNodePtr treePtr) {
    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf ("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}
void preOrder (TreeNodePtr treePtr) {
    if (treePtr != NULL) {
        printf ("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}
void postOrder (TreeNodePtr treePtr) {
    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}

/*

    OBRIGADO!!


*/
