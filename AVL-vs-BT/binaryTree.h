typedef struct binary_tree BINARY_TREE;

BINARY_TREE* create_empty_binary_tree();

BINARY_TREE* create_binary_tree(int valor, BINARY_TREE *esquerdo, BINARY_TREE *direito);

BINARY_TREE* add_bt(BINARY_TREE *bt, int valor);

BINARY_TREE* buscaBT(BINARY_TREE *bt, int valor, int *comp);

int is_empty(BINARY_TREE *raiz);

void printPreOrder_bt(BINARY_TREE *raiz);