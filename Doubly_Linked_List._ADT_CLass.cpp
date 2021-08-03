/*
  this code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
class list{
    private :
        class node{
            public :
                int data;
                node *previous,*next;
        };
        node *head=NULL;
        int _size=0;
    public :
        void insert(int data);
        void insert_at(int data,int index);
        void print();
        void printrev();
        void delete_at(int index);
        int size();
};
void list:: insert(int data){
    _size++;
    if(this->head==NULL){
        head=new node;
        head->data=data;
        head->previous=head->next=NULL;
        return ;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->previous=NULL;
    head->previous=newnode;
    newnode->next=head;
    head=newnode;
    return ;
}
void list:: insert_at(int data,int index){
    _size++;
    node *previous=NULL;
    node *temp=head;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=temp;
    temp->previous=newnode;
    newnode->previous=previous;
    previous->next=newnode;
    return;
}
void list:: print(){
    node *temp=this->head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return ;
}
void list:: printrev(){
    node *temp=this->head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp->previous!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->previous;
    }
    cout<<temp->data<<endl;
    return ;
}
void list:: delete_at(int index){
    _size--;
    node *previous=NULL;
    node *next=NULL;
    node *temp=this->head;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        next=temp->next;
    }
    previous->next=next;
    next->previous=previous;
    return ;
}
int list:: size(){
    return _size;
}
int main(){
    list santhosh;
    santhosh.insert(12);
    santhosh.insert(122);
    santhosh.insert(12);
    santhosh.insert(322);
    santhosh.insert(1622);
    santhosh.insert(1432);
    santhosh.insert(1242);
    santhosh.insert(1272);
    santhosh.insert(1252);
    santhosh.insert(333);
    santhosh.print();
    santhosh.printrev();
    santhosh.insert_at(999,3);
    santhosh.print();
    santhosh.printrev();
    santhosh.delete_at(3);
    santhosh.print();
    santhosh.printrev();
    cout<<santhosh.size()<<endl;
    return 0;
}
