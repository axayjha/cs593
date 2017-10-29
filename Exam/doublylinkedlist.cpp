#include <iostream>
#include <cstdlib>
using namespace std;

#define epsilon 0.001 // accuracy for mathematical calculations
#define PREC 2        // precision for std out

template <typename whatever> class  Node
{
	Node <whatever> *prev;
	whatever 		 data;
	Node <whatever> *next;
public:
	Node(whatever data) {
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}

	whatever getData()				{return this->data;}
	void     setData(whatever data) {this->data = data;}
	Node*	 getPrev()				{return this->prev;}
	Node*	 getNext()				{return this->next;}
	void*	 setPrev(Node *prev)	{this->prev = prev;}
	void*	 setNext(Node *next)	{this->next = next;}
};

template <typename whatever> class List
{
	Node <whatever> *head;
	public:
		List() {this->head=NULL;}
		void push(whatever data);
		whatever pop();		
		int length();
		void display();
};

template <typename whatever> void List <whatever> :: push(whatever data)
{
	if(this->head == NULL)
    {
        this->head = new Node <whatever>(data);
    }
    else
    {
        Node <whatever> *newnode = new Node <whatever> (data);
        this->head->setPrev(newnode);
        newnode->setNext(this->head);
        this->head = newnode;
    }
}

template <typename whatever> whatever List <whatever> :: pop()
{
	Node <whatever> *temp = this->head;

    if(this->head == NULL)
    {
        std::cout << "List empty" << endl;
        exit(0);
    }
    else 
    {
        whatever data = this->head->getData();
        this->head = this->head->getNext();
        this->head->setPrev(NULL);
        return data;
    }
}

template <typename whatever> void List <whatever> :: display()
{	
	std::cout.precision(PREC);

    Node <whatever> *temp = this->head;
    std::cout << "{ ";
    while(this->head!=NULL)
    {        
        std::cout << fixed << this->head->getData() << ", " ;
        this->head = this->head->getNext();
    }
    this->head = temp;
    std::cout << "}" << endl;

}



int main()
{
	List <float> l1;
	l1.push(3);
	l1.push(45.44);
	l1.push(5.999);
	l1.display();
	l1.pop();
	l1.pop();//l1.pop();
	l1.display();
}