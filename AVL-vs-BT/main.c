#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "AVL.h"

int main()
{
    AVL* avl = create_empty_avl();
    BINARY_TREE* bt = create_empty_binary_tree();

    int range, q_sorted,num, i;

    range = 60000;
    q_sorted = 10000;

    FILE *out = fopen("out.txt", "w+b");

    for (i = 0; i < q_sorted; i++)
	{
        num = rand() % range;
        avl = inserir(0, avl, num);
        bt = add_bt(bt, num);

    }

    int find_bt, find_avl, n_comp_avl = 0, n_comp_bt = 0;
    for (i = 0; i < q_sorted; i++)
    {
        find_bt = 0;
        find_avl = 0;
        num = rand() % range;

        n_comp_avl = search_avl(avl, num, &find_avl);
        n_comp_bt = buscaBT(bt, num, &find_bt);

        if (n_comp_avl != -1 && n_comp_bt != -1)
            fprintf(out, "%d %d %d\n", num, find_avl, find_bt);

    }

    fclose(out);
    
    return 0;
}