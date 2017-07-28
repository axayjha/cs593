/*
link.h header file
Linked List functions implementations

Akshay
CSE, 4th sem

Implementations will keep getting updates and added. 
*/


#ifndef LINK_H_
#define LINK_H_

#include <iostream>
using namespace std;
#define epsilon 0.001 // accuracy for mathematical calculations
#define PREC 2 // precision for std out

double dabs(double);

class Node
{
    double data;
    Node *next;
    public:
    Node() {next = NULL; };  
    void setData(double data){
        this->data = data;
    }
    void setNext(Node *next){
        this->next = next;
    }
    Node *getNext(){
        return next;
    }
    double getData(){
        return this->data;
    }

};

class List{
    Node *head;
    public:
        List() {head = NULL;};
        void push(double data);   /*adds to the start*/
        void append(double data); /*adds to the end*/
        void remove(double data); /*deletes the first instance of data*/
        void display();
        double pop(); /*pops first element in the list*/    
        int len(); /*length of the list*/   
        void removeAt(int index);
        void insert(double data, int index);
        bool is_in(double data);
        int index(double data);
        double sum();
        void sort();
        double data_at(int index);
        void replace(int index, double data);
};

void List::push(double data)
{
    if(this->head == NULL)
    {
        this->head = new Node();
        (this->head)->setData(data);
    }
    else
    {
        Node *newnode = new Node();
        newnode->setData(data);
        newnode->setNext(this->head);
        this->head = newnode;
    }
}

void List::remove(double data)
{
    Node *temp = new Node();
    temp = this->head;
    if((this->head)==NULL)
    {        
        std::cout << "Empty list" << endl;
        return;
    }
    if(dabs((this->head)->getData() - data) <= epsilon )
    {
        (this->head)= (this->head)->getNext();
        return;

    }
    while((this->head)->getNext() != NULL)
    {
        if(dabs(((this->head)->getNext())->getData() - data) <= epsilon)
        {
           (this->head)->setNext(((this->head)->getNext())->getNext());
           this->head = temp;
           return;           

        }
        this->head = (this->head)->getNext();

    }
    this->head = temp;
    
    std::cout << "Element - "<<  data <<" - not found." << endl;

}



void List::display()
{
    std::cout.precision(PREC);
    Node *temp=new Node();
    temp = this->head;
    std::cout << "{ ";
    while(this->head!=NULL)
    {        
        std::cout << fixed << this->head->getData() << ", " ;
        this->head = this->head->getNext();
    }
    this->head = temp;
    std::cout << "}" << endl;
}

double List::pop()
{
    /*
        Deletes the first element from the list and returns it
    */
    Node *temp = new Node;
    temp = this->head;

    if(this->head == NULL)
    {
        std::cout << "List empty" << endl;
        return -999999;
    }
    else 
    {
        double data = this->head->getData();
        this->head = this->head->getNext();
        return data;
    }
    
}

void List::append(double data)
{
    Node *temp = new Node();
    temp = this->head;
    if(this->head == NULL)
    {
        this->head = new Node();
        this->head->setData(data);
        return;
    }
    else if(this->head->getNext() == NULL)
    {
        Node *newnode = new Node();
        newnode->setData(data);
        this->head->setNext(newnode);
        this->head = temp;
        return;
    }
    else
    {
        while(this->head->getNext() != NULL)
            this->head = this->head->getNext();

        Node *newnode = new Node();
        newnode->setData(data);
        this->head->setNext(newnode);
        this->head = temp;
        return;  

    }
}

int List::len()
{
    int count=0;
    Node *temp  = new Node();
    temp = this->head;
    while(this->head != NULL)
    {
        ++count;
        this->head = this->head->getNext();        
    } 
    this->head = temp;
    return count;
}
void List::removeAt(int index)
{
    int count=1;
    Node *temp = new Node();
    temp = this->head;
    Node *head = new Node();
    head = this->head;
    if(index >= (this)->len() || index<0)
    {
        std::cout <<  "Index out of range" << endl;
        return;
    }//works
    if(index==0)
    {
        this->head = temp->getNext();
        return;
    } //works
    else
    {
        while(temp->getNext() != NULL)
        {
            if(count == index)
            {                
                temp->setNext(temp->getNext()->getNext());
                this->head = head;
                return;
            }
            count++;
            temp = temp->getNext();

        }
    }//works. done!
}

void List::insert(double data, int index)
{
    int count=1;
    Node *temp = new Node();
    temp = this->head;
    Node *head = new Node();
    head = this->head;
    if(index >= (this)->len()+1 || index<0)
    {
        std::cout <<  "Index out of range" << endl;
        return;
    }//works
    else if(index==0)
    {
        Node* newnode = new Node();
        newnode->setData(data);
        newnode->setNext(temp);
        this->head = newnode;
        return;
    } //works
    else if(index == this->len())
    {
        while(temp->getNext()!= NULL)
            temp=temp->getNext();
        Node* newnode = new Node();
        newnode->setData(data);
        temp->setNext(newnode); 
        this->head = head;
        return;

    }
    else
    {
        while(temp->getNext() != NULL)
        {
            if(count == index)
            {  
                Node* newnode = new Node();
                newnode->setData(data);
                newnode->setNext(temp->getNext()); 
                temp->setNext(newnode);          
                
                this->head = head;
                return;
            }
            count++;
            temp = temp->getNext();

        }
    }
}

bool List::is_in(double data)
{
    Node* temp  = new Node();
    temp  = this->head;
    while(this->head!=NULL)
    {
        if((this->head->getData() - data)<epsilon)
        {
            this->head=temp;
            return true;
        }
        this->head = this->head->getNext();
    }
    this->head=temp;
    return false;
}

int List::index(double data)
{
    int count=0;
    Node* temp  = new Node();
    temp  = this->head;
    while(this->head!=NULL)
    {   
        
        if((this->head->getData() - data)<epsilon)
        {
            this->head=temp;
            return count;
        }
        this->head = this->head->getNext();
        count++;
    }
    this->head=temp;
    return -1;
}

double List::sum()
{
    double sum=0;
    Node* temp  = new Node();
    temp  = this->head;
    while(this->head!=NULL)
    {   
        sum += (this->head)->getData();        
        this->head = this->head->getNext();        
    }
    this->head=temp;
    return sum;
}

double List::data_at(int index)
{
    if(index < 0 || index >= this->len())
    {
        std::cout << "Index out of range" << endl;
        return -9999999;
    }
    int count=0;
    Node* temp  = new Node();
    temp  = this->head;
    while(this->head!=NULL)
    {
        if(count==index)
        {
            double data = this->head->getData();
            this->head  = temp;
            return data ;
        }
        this->head = this->head->getNext();  
        count++;
    }
    this->head=temp;
}

void List::replace(int index, double data)
{
    if(index < 0 || index > this->len())
    {
        std::cout << "Index out of range" << endl;
        return;
    }
    int count=0;
    Node* temp  = new Node();
    temp  = this->head;
    while(this->head!=NULL)
    {
        if(count==index)
        {
            this->head->setData(data);
            this->head  = temp;
            return;
        }
        this->head = this->head->getNext();  
        count++;
    }
    this->head=temp;
    
}

void List::sort()
{
    Node *temp =  new Node();
    temp = this->head;
    
    for(int i =0; i<this->len(); i++)
    {
        for(int j=0; j<this->len()-i-1; j++)
        {
            if(this->data_at(j) > this->data_at(j+1) )
            {
                double temp1 = this->data_at(j);
                double temp2 = this->data_at(j+1);
                this->replace(j, temp2);
                this->replace(j+1, temp1);
            }
        }
    }
    this->head=temp;
}

double dabs(double num)
{
    /* absoule of double */
    return num>=0 ? num : (-1*num);
}

#endif