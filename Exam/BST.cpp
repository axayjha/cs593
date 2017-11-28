/*
	Binary search tree implementation

	Akshay Anand
	CSE, 5th sem
	28/11/2017
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct node node;
struct node{
	int value;
	node *left, *right;
};

class tree{
public:	
	node *root;
	tree(){root = NULL;}
	void insert(int data);
	void inorder();
	void preorder();
	void postorder();
};

node *newNode(int val);
node* _insert(node *rootp, node *newp);

void applyinorder(node *rootp, 
	void(*fn)(node *, const char *), const char arg[]);

void applypostorder(node *rootp, 
	void(*fn)(node *, const char *), const char arg[]);

void applypreorder(node *rootp, 
	void(*fn)(node *, const char *), const char arg[]);


int main()
{
	tree tree1; int n;
	printf("Enter the number of elements to insert in BST: ");
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for(int i=0; i<n; i++)
	{
		int num;
		scanf("%d", &num);
		tree1.insert(num);
	}
	printf("Inorder traversal: \n");
	tree1.inorder();

	printf("Post-order traversal: \n");
	tree1.postorder();

	printf("Pre-order traversal: \n");
	tree1.preorder();
}


void tree::insert(int data){
	this->root = _insert(this->root, newNode(data));
}

void tree::inorder(){
	applyinorder(this->root, printn, "%d ");
	printf("\n");
}

void tree::postorder(){
	applypostorder(this->root, printn, "%d ");
	printf("\n");
}

void tree::preorder(){
	applypreorder(this->root, printn, "%d ");
	printf("\n");
}

node* _insert(node *rootp, node *newp)
{
	int cmp;
	if(rootp == NULL)
		return newp;
	cmp = newp->value - rootp->value;	
	if(cmp<=0)
		rootp->left = _insert(rootp->left, newp);
	else
		rootp->right = _insert(rootp->right, newp);
	return rootp;
}

void applyinorder(node *rootp, 
	void(*fn)(node *, const char *), const char arg[])
{
	if(rootp == NULL)
		return;
	applyinorder(rootp->left, fn, arg);
	(*fn)(rootp, arg);
	applyinorder(rootp->right, fn, arg);
}

void printn(node *rootp, const char arg[]){
	printf(arg, rootp->value);
}

void applypostorder(node *rootp,
	void(*fn)(node*, const char *), const char arg[])
{
	if(rootp == NULL)
		return;
	applypostorder(rootp->left, fn, arg);	
	applypostorder(rootp->right, fn, arg);
	(*fn)(rootp, arg);
}

void applypreorder(node *rootp, 
	void(*fn)(node *, const char *), const char arg[])
{
	if(rootp == NULL)
		return;
	(*fn)(rootp, arg);
	applypreorder(rootp->left, fn, arg);	
	applypreorder(rootp->right, fn, arg);
}

node *newNode(int val){
	node *newp = (node*)malloc(sizeof(node));	
	newp->value = val;
	newp->left =newp->right= NULL;
	return newp;
}