#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tree Tree;
struct Tree{
	int value;
	Tree *left, *right;
};

Tree *insert(Tree *treep, Tree *newp)
{
	int cmp;
	if(treep == NULL)
		return newp;
	cmp = newp->value - treep->value;	
	if(cmp<=0)
		treep->left = insert(treep->left, newp);
	else
		treep->right = insert(treep->right, newp);
	return treep;
}

void applyinorder(Tree *treep)
{
	if(treep == NULL)
		return;
	applyinorder(treep->left);
	printf("%d\n", treep->value);
	applyinorder(treep->right);
}


void applypostorder(Tree *treep)
{
	if(treep == NULL)
		return;
	applypostorder(treep->left);	
	applypostorder(treep->right);
	printf("%d\n",treep->value);
}

Tree *newNode(int val)
{
	Tree *newp = (Tree*)malloc(sizeof(Tree));	
	newp->value = val;
	newp->left =newp->right= NULL;
	return newp;
}


int main()
{
	Tree *treep;
	Tree *n1= newNode(2);
	Tree *n2= newNode(1);
	Tree *n3= newNode(1);
	Tree *n4 = newNode(3);
	treep = insert(treep, n1);
	treep = insert(treep, n2);
	treep = insert(treep, n3);
	treep = insert(treep, n4);
	applyinorder(treep);
}