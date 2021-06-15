#include <iostream>
#include "santhosh.h"
using namespace std;
class linkedlist{
    private:
        node *head;
        int sizer;
    public :
        linkedlist();
        void insertBegin(int data);
        void insertENd(int data);
        void insertAT(int data , int index);
        void print();
        int size();
        void deleteAt(int index);
};
linkedlist::linkedlist(){
    sizer=0;
    head=NULL;
}
void linkedlist:: insertBegin(int data){
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    sizer++;
    return;
}
void linkedlist:: insertENd(int data){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=NULL;
    temp->next=newnode;
}
void linkedlist:: insertAT(int data , int index){
    node *temp=head;
    node *previous=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=temp;
    previous->next=newnode;
    return;
}
void linkedlist:: print(){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int linkedlist:: size(){
    return sizer;
}
void linkedlist::deleteAt(int index){
    if(index==0){
        head=head->next;
    }
    node *temp=head;
    node*previous=NULL;
    node *nextnode=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        nextnode=temp->next->next;
    }
    previous->next=nextnode;
    return;
}
int main(){
    linkedlist san;
    san.insertBegin(12);
    san.insertBegin(29);
    san.insertBegin(73);
    san.insertBegin(43);
    san.insertBegin(333);
    san.print();
    san.insertENd(99);
    san.print();
    san.insertAT(999,3);
    san.print();
    san.deleteAt(3);
    san.print();
    return 0;
}
