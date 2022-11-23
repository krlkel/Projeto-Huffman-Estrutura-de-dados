#include<stdio.h>
#include<stdlib.h>
#include "AVL.h"

struct avl
{
    int valor;
    int h;
    AVL* esquerdo;
    AVL* direito;
};

int AVLvazia(AVL *avl)
{
    return (avl == NULL);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVL* create_empty_avl()
{
    return NULL;
}

AVL* create_avl(int valor, AVL *esquerdo, AVL *direito)
{
    AVL *new_avl = (AVL*) malloc(sizeof(AVL));
    
    new_avl->valor = valor;
    new_avl->esquerdo = esquerdo;
    new_avl->direito = direito;

    return new_avl;
}

int h(AVL *avl)
{
    if (AVLvazia(avl))
    {
        return -1;
    }
    else
    {
        return 1 + max(h(avl->esquerdo), h(avl->direito));
    }
}

int balance_factor(AVL *avl)
{
    if(AVLvazia(avl))
    {
        return 0;
    }
    else if(!AVLvazia(avl->esquerdo) && !AVLvazia(avl->direito))
    {
        return (avl->esquerdo->h - avl->direito->h);
    }
    else if(!AVLvazia(avl->esquerdo) && AVLvazia(avl->direito))
    {
        return (1 + avl->esquerdo->h);
    }
    else
    {
        return (-avl->direito->h - 1);
    }
}

AVL* rotate_left(AVL *avl)
{
    AVL *subtree_root = create_empty_avl();

    if(!AVLvazia(avl) && !AVLvazia(avl->direito))
    {
        subtree_root = avl->direito;
        avl->direito = subtree_root->esquerdo;
        subtree_root->esquerdo = avl;
    }

    subtree_root->h = h(subtree_root);
    avl->h = h(avl);

    return subtree_root;
}

AVL* rotate_right(AVL *avl)
{
    AVL *subtree_root = NULL;

    if(!AVLvazia(avl) && !AVLvazia(avl->esquerdo))
    {
        subtree_root = avl->esquerdo;
        avl->esquerdo = subtree_root->direito;
        subtree_root->direito = avl;
    }

    subtree_root->h = h(subtree_root);
    avl->h = h(avl);

    return subtree_root;
}

AVL* inserir(AVL **root, AVL *avl, int valor)
{
    if(AVLvazia(avl))
    {
        return create_avl(valor, NULL, NULL);
    }
    else if(avl->valor > valor)
    {
        avl->esquerdo = inserir(root, avl->esquerdo, valor);
    }
    else
    {
        avl->direito = inserir(root, avl->direito, valor);
    }

    avl->h = h(avl);
    AVL *child;

    if(balance_factor(avl) == 2 || balance_factor(avl) == -2)
    {
        if(balance_factor(avl) == 2)
        {
            child = avl->esquerdo;
            if (balance_factor(child) == -1)
            {
                avl->esquerdo = rotate_left(child);
            }
            avl = rotate_right(avl);
        }
        else if (balance_factor(avl) == -2)
        {
            child = avl->direito;
            if(balance_factor(child) == 1)
            {
                avl->direito = rotate_right(child);
            }
            avl = rotate_left(avl);
        }
    }
    
    return avl;
}

AVL* search_avl(AVL *avl, int valor, int *comp)
{
    *comp += 1;

    if(AVLvazia(avl) || (avl->valor == valor))
    {
        return avl;
    }
    else if(avl->valor > valor)
    {
        return search_avl(avl->esquerdo, valor, comp);
    }
    else
    {
        return search_avl(avl->direito, valor, comp);
    }
}

void print_pre_order_avl(AVL *avl)
{
    if(!AVLvazia(avl))
    {
        printf(" %d ", avl->valor);
        print_pre_order_avl(avl->esquerdo);
        print_pre_order_avl(avl->direito);
    }
}

void printRaizAVL(AVL *avl)
{
    if(!AVLvazia(avl))
        printf("%d\n", avl->valor);
}