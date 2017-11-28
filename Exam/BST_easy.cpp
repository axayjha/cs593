#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct Tree Tree;
struct Tree{
	int value;
	Tree *left, *right;
};

class tree{
public:	
	Tree *root;
	tree(){root = NULL;}
	void Insert(int data);
	void inorder();
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

void tree::Insert(int data)
{
	this->root = insert(this->root, newNode(data));
}

void tree::inorder()
{
	applyinorder(this->root);
}

int main()
{
	tree treep;
	treep.Insert(4);
	treep.Insert(3);
	treep.Insert(1);
	treep.inorder();
}
