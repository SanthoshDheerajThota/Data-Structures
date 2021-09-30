/*
   This code is completely written by T.Santhosh Dheearj
*/
#include <iostream>
using namespace std;
class node{
    public :
        int data;
        node *next;
};
void insert_at_begin(node *&head,node *&tail,int data){
    if(head==NULL){
        head=new node;
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else{
        node *newnode=new node;
        newnode->data=data;
        newnode->next=head;
        head=newnode;
        tail->next=head;
        return ;
    }
}
void insert(node *&head,node *&tail,int data){
    if(head==NULL){
        head=new node;
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else{
        node *newnode=new node;
        newnode->data=data;
        newnode->next=head;
        head=newnode;
        tail->next=head;
        return ;
    }
}
void insert_at_end(node *&head,node *&tail,int data){
    if(head==NULL){
        head=new node;
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else{
        node *newnode=new node;
        newnode->data=data;
        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
    }
}
void print(node *&head){
    node *temp=head;
    while(temp->next!=head&&temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void delete_at_end(node *&head,node *&tail){
    node *temp=head;
    node *prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    tail=prev;
    return ;
}
void delete_at_begining(node *&head,node *&tail){
    head=head->next;
    tail->next=head;
    return;
}
int main(){
    node *head=NULL,*tail=NULL;
    insert(head,tail,12);
    insert(head,tail,142);
    insert(head,tail,1462);
    insert(head,tail,152);
    insert(head,tail,126);
    insert(head,tail,182);
    insert(head,tail,1256);
    insert(head,tail,333);
    print(head);
    delete_at_end(head,tail);
    print(head);
    delete_at_begining(head,tail);
    print(head);
    insert_at_begin(head,tail,9999);
    print(head);
    insert_at_end(head,tail,999);
    head=head->next->next->next;
    print(head);
    return 0;
}
