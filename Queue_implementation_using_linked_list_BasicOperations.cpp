//Created by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class node{                          //To maintain queue lined list
    public:
        int data;
        node *next;
        friend class queue;
};
class queue{
    private:
        node *head;
        int size;
    public :
        queue();
        void enqueue(int data);      //adds the data given at the top using FIFO principle
        void dequeue();              //deleted the last element or the element nod at bottom of the queue by FIFO method
        void print();                //This prints the queue in the order the elements are pushed into the queue
        int sizeOfQ();               //This just gives the current size of the queue
};
queue::queue(){
    head=NULL;
    size=0;
}
void queue::enqueue(int data){
    if(size==0){
        head=new node;
        head->data=data;
        head->next=NULL;
        size++;
        return;
    }
    node *nodehere;
    nodehere=new node;
    nodehere->data=data;
    nodehere->next=head;
    head=nodehere;
    size++;
    return;
}
void queue::dequeue(){
    node *temp=head;
    node *previous;
    while(head->next!=NULL){
        previous=head;
        head=head->next;
    }
    previous->next=NULL;
    head=NULL;
    head=temp;
    size--;
}
void queue::print(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
int queue::sizeOfQ(){                  
    return this->size;
}
int main(){
    queue myQ;
    myQ.enqueue(29);
    myQ.enqueue(9);
    myQ.enqueue(20);
    myQ.enqueue(30);
    myQ.enqueue(40);
    myQ.enqueue(333);
    myQ.print();
    myQ.dequeue();
    myQ.dequeue();
    myQ.dequeue();
    myQ.print();
    return 0;
}
