/*
      this code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *previous,*next;
};
node *head=NULL;
void insert(int data){
    if(head==NULL){
        head=new node;
        head->data=data;
        head->previous=head->next=NULL;
    }
    node *newnode=new node;
    newnode->data=data;
    head->previous=newnode;
    newnode->previous=NULL;
    newnode->next=head;
    head=newnode;
}
void printer(){
    node *temp=head;
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
void print(){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return ;
}
void delete_at(int index){
    node *temp=head;
    node *previous=NULL;
    node *next=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        next=temp->next;
    }
    previous->next=next;
    next->previous=previous;
    return ;
}
void insert_at(int data,int index){
    node *temp=head;
    node *previous=NULL;
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
    return ;
}
int main(){
    insert(92);
    insert(93);
    insert(94);
    insert(95);
    insert(98);
    insert(333);
    print();
    delete_at(3);
    print();
    insert_at(9999,3);
    print();
    printer();
    return 0;
}
