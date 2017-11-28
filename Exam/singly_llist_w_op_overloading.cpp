#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *getNode(int data);

class List{	
	Node *head;
public:
	List() { head = NULL; }
	Node *getHead()  { return this->head; }
	int length();
	void display();
	void push_front(int data);
	void push_back(int data);
	void pop_front();
	void pop_back();
	void remove(int data);
	int getItem(int pos);

	List operator+(int data); /* inserts at end */
	friend List operator+(int data, List list); /* inserts at front */
	List operator+=(int data) { return operator+(data); }; /* inserts at end */

	List operator-(int data); /* removes the item */
	friend List operator-(int data, List list){ return list.operator-(data); } 
	List operator-=(int data) { return operator-(data); }
	
};



int main(){
	List l1;		
	l1.push_back(7);
	l1.push_front(6);
	l1.push_back(5);
	l1  = l1+3;
	l1 = 100 + l1;
	l1 += 3;
	l1 -= 3;
	l1 -= 3;	
	l1.display();
	cout << "Item at pos 3: " << l1.getItem(3) << endl;
	return 0;
}

List List :: operator+(int data){
	this->push_back(data);
	return *this;
}

List operator+(int data, List list){
	list.push_front(data);
	return list;
}


List List :: operator-(int data){
	this->remove(data);
	return *this;
}

Node *getNode(int data){
	Node *node = (Node *)malloc(sizeof(Node *));
	node->data = data;
	node->next = NULL;
	return node;	
}

int List :: length(){
	int len=0; Node *temp = this->head;
	while(temp && ++len )
		temp = temp->next;
	return len;
}

void List :: push_front(int data){
	Node *newnode = getNode(data);
	newnode->next = this->head;
	this->head = newnode;
}

void List :: pop_front(){
	this->head = this->head->next;
}

void List :: push_back(int data){  /* appends in the end*/
	Node** temp = &(this->head);   /* to traverse the list */
	Node* head_cpy = this->head;   /* to restore head */

	if(!this->head){			   /* If list is empty */
		this->head = getNode(data);	
		return;
	}
	while (*temp && (*temp)->next)
		*temp = (*temp)->next;
	(*temp)->next = getNode(data);
	this->head = head_cpy;
}

void List :: display(){
	Node *node = this->head;
	while (node and cout << node->data << " ") /* while node!=NULL, print data */
		node = node->next;
	cout << endl;
}

void List :: remove(int data){	 /* removes the node with the provided data */
	Node *temp = this->head, *prev = this->head;
	if(temp->data == data) {		/* If element is first item*/
		this->head = temp->next;
		delete (temp);
		return;
	}
	while ((temp) && (temp->data != data)){
		prev = temp;
		temp = temp->next;
		if(!temp) return;  	/* If not found in the list, DO NOTHING and return*/
	}
	delete prev->next;
	prev->next = prev->next->next; 
}

int List :: getItem(int pos){
	int index=0; Node *node = this->head;
	assert (pos < length() and pos >= 0);
	while(node && index++ < pos)
		node = node->next;
	return node->data;
} 