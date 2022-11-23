#include "binaryTree.h"

BINARY_TREE* create_empty_binary_tree()
{
    return NULL;
}

BINARY_TREE* create_binary_tree(int valor, BINARY_TREE *esquerdo, BINARY_TREE *direito)
{
    BINARY_TREE *new_binary_tree = (BINARY_TREE*) malloc(sizeof(BINARY_TREE));
    
    new_binary_tree->valor = valor;
    new_binary_tree->esquerdo = NULL;
    new_binary_tree->direito = NULL;

    return new_binary_tree;
}

BINARY_TREE* add_bt(BINARY_TREE *bt, int valor)
{
    if(bt == NULL)
    {
        bt = create_binary_tree(valor, NULL, NULL);
    }
    if(bt->valor > valor)
    {
        bt->esquerdo = add_bt(bt->esquerdo, valor);
    }
    else if(bt->valor < valor)
    {
        bt->direito = add_bt(bt->direito, valor);
    }

    return bt;
}

BINARY_TREE* buscaBT(BINARY_TREE *bt, int valor, int *comp)
{
    *comp += 1;

    if(bt == NULL)
    {
        return 0;
    }
    else{
        if(bt->valor == valor){
            return 1;
        }

        else if(valor < bt->valor){
            buscaBT(bt->esquerdo, valor, comp);
        }
        else{
            buscaBT(bt->direito, valor, comp);
        }
    }
}

int is_empty(BINARY_TREE *raiz){
    return (raiz==NULL)
}

void printPreOrder_bt(BINARY_TREE *raiz)
{
    if(!is_empty(raiz))
    {
        printf(" %d ", raiz->valor);
        printPreOrder(raiz->esquerdo);
        printPreOrder(raiz->direito);
    }
}