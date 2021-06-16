//this code is completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
};
void insert(node *&head,int data){
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    return;
}
void print(node *head){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void reverese_linkedlist(node *&head){
    node *previous=NULL,*current=head,*next;
    while(current->next!=NULL){
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    current->next=previous;
    head=current;
    return;
}
void reverse(node *&head){
    static node *previous=NULL;
    static node *current=head;
    static node *next=NULL;
    if(current->next==NULL){
        current->next=previous;
        head=current;
        return;
    }
    else{
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
        reverse(head);
    }
}
int main(){
    node *head=NULL;
    insert(head,12);
    insert(head,13);
    insert(head,124);
    insert(head,333);
    print(head);
    reverese_linkedlist(head);
    print(head);
    reverse(head);
    print(head);
    return 0;
}
