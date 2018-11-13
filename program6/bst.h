#ifndef BST_H
#define BST_H
typedef struct Data
{
	int value;
} Data;

typedef struct Node
{
	Data data;
	struct Node *parent, *left, *right;
} Node;

typedef struct  Tree
{
        Node *root;
	Data * (*insert)(struct Tree *bst, Data data);
	Data * (*search)(struct Tree * bst, Data data);
	void (*sort)(struct Tree *bst, Data *data);
	int (*compare)(struct Tree *tree,struct Tree *treeCopy);
	struct Tree * (*clone)(struct Tree *tree);
	void (*delete)(struct Tree * bst);
	void (*removeData)(struct Tree * bst, Data value);
} Tree;

Data * insert(Tree *bst, Data data);
Data * search(Tree * bst, Data value);
void sort(Tree *bst, Data *data);
int compare(Tree *tree, Tree *treeCopy);
Tree * clone(Tree *tree);
void delete(Tree * bst);
void removeData(Tree * bst, Data data);

Tree * newTree();
Node * newNode(Data data, Node * parent);

Data * insertNode(Node *node, Data data);
Node * searchNode(Node *node, Data data);
void sortTree(Node *node, Data *data, int *index);
void performPreorderTraversal(Node *node, Data *data, int *index);
Node * cloneNode(Node *originalNode, Node *cloneNode1, Node *parentNode);
void removeLeaf(Node * leaf);
void shortCircuit(Node *node);
Node * searchMin(Node *node);
void promotion(Node *node);
void deleteTree(Node *node);


#endif
