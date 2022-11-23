#include<stdio.h>
#include<stdlib.h>

typedef struct avl AVL;

struct avl
{
    int valor;
    int h;
    AVL* esquerdo;
    AVL* direito;
};

AVL* create_empty_avl();

AVL* create_avl(int valor, AVL *esquerdo, AVL *direito);

AVL* rotate_left(AVL *avl);

AVL* rotate_right(AVL *avl);

AVL* inserir(AVL **root, AVL *avl, int valor);

AVL* search_avl(AVL *avl, int valor, int *comp);

int h(AVL *avl);

int balance_factor(AVL *avl);

int AVLvazia(AVL *avl);

int max(int a, int b);

void print_pre_order_avl(AVL *avl);

void printRaizAVL(AVL *avl);