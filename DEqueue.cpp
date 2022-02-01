#include <iostream>
using namespace std;
class queue{
    private :
        class node{
            public :
                int data;
                node *next,*prev;
        };
        node *head=NULL;
        node *tail=NULL;
    public :
        void enqueue(int data);
        void print();
        void printrev();
        int dequeue();
        int dequeue_last();
        void enqueue_front(int data);
};
int queue:: dequeue_last(){
    int temp=this->head->data;
    head=head->next;
    head->prev=NULL;
    return temp;
}
void queue:: enqueue_front(int data){
    node *newnode=new node();
    newnode->data=data;
    this->tail->next=newnode;
    newnode->prev=this->tail;
    newnode->next=NULL;
    this->tail=newnode;
}
void queue ::enqueue(int data){
    if(head==NULL){
        head=new node();
        head->data=data;
        head->next=head->prev=NULL;
        tail=this->head;
        return ;
    }
    else{
        node *newnode=new node();
        newnode->data=data;
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
        return ;
    }
}
void queue:: print(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
    return ;
}
void queue:: printrev(){
    node *temp=this->tail;
    while(temp->prev!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->prev;
    }
    cout<<temp->data<<endl;
}
int queue:: dequeue(){
    int temp=this->tail->data;
    this->tail=this->tail->prev;
    this->tail->next=NULL;
    return temp;
}
int main(){
    
}
