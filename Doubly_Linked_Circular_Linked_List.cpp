#include <iostream>
using namespace std;
class node{
    public :
        int data;
        node *prev,*next;
};
void insert(node *&head,node *&tail,int data){
    if(head==NULL){
        head=new node();
        head->data=data;
        head->prev=head->next=NULL;
        tail=head;
    }
    else{
        node *newnode=new node();
        newnode->data=data;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        head->prev=tail;
        tail->next=head;
        return ;
    }
}
void print(node *&head){
    node *temp=head;
    cout<<temp->data<<"   ";
    temp=temp->next;
    while(temp!=head){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node *head,*tail;
    head=tail=NULL;
    insert(head,tail,132);
    insert(head,tail,412);
    insert(head,tail,125);
    insert(head,tail,122);
    insert(head,tail,333);
    print(head);
}
