#include"bst.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

Tree * newTree()
{
	Tree *bst = malloc(sizeof(Tree));
	bst->root = NULL;

	//Init function pointes
	bst->insert = insert;
	bst->search = search;
	bst->sort = sort;
	bst->compare = compare;
	bst->clone = clone;
	bst->delete = delete;
	bst->removeData = removeData;

	return bst;
}

Node * newNode(Data data, Node * parent)
{
	Node *node = malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->data = data;
	//node->data.value = data.value;

	return node;
}

//Recursive function for inserting the node in the tree
Data * insertNode(Node *node, Data data)
{
	Data *dataPtr = NULL;
	//Check if the same node is being inserted twice and return null
	if(node->data.value == data.value)
	{
		dataPtr = NULL;
	}//Check if the node to be inserted has a value less than the current node
	else if(node->data.value > data.value)
	{
		//If the left child of the current node is null then insert a new node as a leaf node
		if(node->left == NULL)
		{
			node->left = newNode(data, node);
			dataPtr = &(node->left->data);
		}//If the current node has children, recusively iterate the left sub tree
		else
		{
			dataPtr = insertNode(node->left, data);
		}
	}//Check if the node to be inserted has a value greater than the current node
	else if(node->data.value < data.value)
	{
		//If the right child of the current node is null then insert a new node as a leaf node
		if(node->right == NULL)
		{
			node->right = newNode(data, node);
			dataPtr = &(node->right->data);
		}
		else//If the current node has children, recusively iterate the left sub tree
		{
			dataPtr = insertNode(node->right, data);
		}
	}
	//Return pointer to the data
	return dataPtr;
}

Data * insert(Tree *bst, Data data)
{
	Data *dataPtr = NULL;

	//If the tree is empty, create a root node
	if(bst->root == NULL)
	{
		bst->root = newNode(data, NULL);
		dataPtr = &(bst->root->data);
	}//Recursively iterate the tree for inserting data
	else
	{
		//Recursive function for inserting data into the BST
		dataPtr = insertNode(bst->root, data);
	}
	return dataPtr;
}

//Recursive function for searching the node in the tree
Node * searchNode(Node *node, Data data)
{
	Node *nodePtr = NULL;
	//Check if the value of the current node is same as the value being searched
	if(node->data.value == data.value)
	{
		//Return the pointer to the node
		nodePtr = node;
	}
	//Check if the value of the node being searched is less than the value of current node and traverse the left sub tree
	else if(node->data.value > data.value && node->left != NULL)
	{
		nodePtr = searchNode(node->left, data);
	}
	//Check if the value of the node being searched is greater than the value of current node and traverse the right sub tree
	else if(node->data.value < data.value && node->right != NULL)
	{
		nodePtr = searchNode(node->right, data);
	}
	return nodePtr;
}

Data * search(Tree * bst, Data data)
{
	Node *nodePtr = NULL;
	//If the tree is empty, return NULL
	if(bst->root == NULL)
	{
		return NULL;
	}//Recursively iterate the tree for inserting data
	else
	{
		//Recursive function for inserting data into the BST
		nodePtr = searchNode(bst->root, data);
		return &(nodePtr->data);
	}
}

void sortTree(Node *node, Data *data, int *index)
{
	//Check if the node is not null
	if(node != NULL)
	{
		//Traversing the left sub tree
		sortTree(node->left, data, index);

		//Inserting the data in the array and incrementing the index
		data[*index] = node->data;
		(*index)++;

		//Traversing the right sub tree
		sortTree(node->right, data, index);
	}
}

void sort(Tree *bst, Data *data)
{
	//Index variable for inserting element in the array
	int index = 0;
	//Check if the root is not null
	if(bst->root != NULL)
	{
		sortTree(bst->root, data, &index);
	}
}

//This function creates a preorder traversed array of the given tree
void performPreorderTraversal(Node *node, Data *data, int *index)
{
	//Check if the node is not null
	if(node != NULL)
	{
		//Inserting the data in the array and incrementing the index
		data[*index] = node->data;
		(*index)++;

		//Traversing the left sub tree
		performPreorderTraversal(node->left, data, index);

		//Traversing the right sub tree
		performPreorderTraversal(node->right, data, index);
	}
}

int compare(Tree *tree, Tree *treeCopy)
{
	int isEqual = 0;

	//If the trees are not empty create a preorder traversed array of both the trees and compare the arrays
	if(tree != NULL && treeCopy != NULL)
	{
		//Data arrays
		Data array1[13];
		Data array2[13];

		//Init data array to -1
		for(int i = 0; i < 13; i++)
		{
			array1[i] = array2[i] = (Data) {-1};
		}


		//Index variables
		int index1, index2;
		index1 = index2 = 0;

		//Function call for generating preorder trees
		performPreorderTraversal(tree->root, array1, &index1);
		performPreorderTraversal(treeCopy->root, array2, &index2);

		//Setting the equality to true
		isEqual = 1;

		//Checking the trees for equality
		for(int i = 0; i < 13; i++)
		{
			//If the element is not equal then set the variable to false and break the loop
			if(array1[i].value != array2[i].value)
			{
				isEqual = 0;
				break;
			}
		}
	}
	return isEqual;
}

Node * cloneNode(Node *originalNode, Node *cloneNode1, Node *parentNode)
{
	//Link referred to : https://www.quora.com/How-can-I-create-a-copy-of-a-binary-tree
	Node *temp = NULL;
	//Check if the node in original tree is not null
	if(originalNode != NULL)
	{
		//Copy the value of the original node
		temp = newNode(originalNode->data, parentNode);

		//Recursively traverse the left sub tree
		if(originalNode->left != NULL)
		{
			temp->left = cloneNode(originalNode->left, temp->left, temp);
		}

		//Recursively traverse the right sub tree
		if(originalNode->right != NULL)
		{
			temp->right = cloneNode(originalNode->right, temp->right, temp);
		}
	}
	return temp;
}

Tree * clone(Tree *tree)
{
	Tree *clone = newTree();
	//Clone the tree
	clone->root = cloneNode(tree->root, clone->root, NULL);

	//Data test[13];
	//clone->sort(clone, test);

	return clone;
}

//Function for deleting leaf node
void removeLeaf(Node * leaf)
{
	if(leaf->parent != NULL)
	{
		//Set the parent->right to NULL if the leaf is the right child of the parent
		if(leaf->parent->right == leaf)
			leaf->parent->right = NULL;
		else//Set the parent->left to NULL if the leaf is the left child of the parent
			leaf->parent->left = NULL;
	}

	//Free the memory allocated to the leaf node
	free(leaf);
}

//Function for deleting a node with single child
void shortCircuit(Node *node)
{
	//Check if the node is the right child of the parent
	if(node->parent->right == node)
	{
		//Check if the node to be deleted has a left child
		if(node->right == NULL)
		{
			node->parent->right = node->left;
			node->left->parent = node->parent;
		}//Check if the node to be deleted has a right child
		else
		{
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
	}//Check if the node is the left child of the parent
	else if(node->parent->left == node)
	{
		//Check if the node to be deleted has a right child
		if(node->left == NULL)
		{
			node->parent->left = node->right;
			node->right->parent = node->parent;
		}//Check if the node to be deleted has a left child
		else
		{
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}
	}

	//Free the memory allocated to the node
	free(node);
}

//Function for searching the node with minimum value in the right sub tree
Node * searchMin(Node *node)
{
	while(node->left != NULL)
		node = node->left;
	return node;
}

//Function for deleting a node with two children
void promotion(Node *node)
{
	//Get the node with minimum value in the right sub tree
	Node *tempNode = searchMin(node->right);
	node->data = tempNode->data;

	//Check the number of children for the node to be promoted and process them accordingly
	if(tempNode->left == NULL && tempNode->right == NULL)
	{
		removeLeaf(tempNode);
	}
	else
	{
		shortCircuit(tempNode);
	}
}

void removeData(Tree * bst, Data data)
{
	//Searching for the node using searchNode function
	Node *node = NULL;
	node = searchNode(bst->root, data);

	if(node != NULL)
	{
		//Check if the node is a leaf node
		if(node->left == NULL && node->right == NULL)
		{
			//If the node to be deleted is also the root node
			if(bst->root == node)
			{
				free(node);
				bst->root = NULL;
			}
			else//If the node to be deleted is not the root node
			{
				removeLeaf(node);
			}
		}//Check if the node to be deleted has a single child
		else if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
		{
			//If the node to be deleted is also the root node
			if(bst->root == node)
			{
				if(node->left == NULL)
					bst->root = node->right;
				else
					bst->root = node->left;
				free(node);
			}
			else//If the node to be deleted is not the root node
			{
				shortCircuit(node);
			}
		}//Check if the node to be deleted has a two children
		else if(node->left != NULL && node->right != NULL)
		{
			promotion(node);
		}
	}
}

void deleteTree(Node *node)
{
	if(node != NULL)
	{
		//Traversing the left sub tree
		deleteTree(node->left);

		//Traversing the right sub tree
		deleteTree(node->right);

		//Free the node
		removeLeaf(node);
	}
}

void delete(Tree * bst)
{
	//If the root is not NULL, recursively delete in post order
	if(bst->root != NULL)
	{
		//Delete the nodes and free the tree
		deleteTree(bst->root);
		free(bst);
	}
	else
	{
		//Free the tree
		free(bst);
	}
}
