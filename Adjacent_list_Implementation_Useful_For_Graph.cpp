/*
      This code is complete;y written by Thota Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
class node{
    public :
        int data;
        node *next;
};
void insert(node *&head,int data){
    if(head==NULL){
        head=new node();
        head->data=data;
        head->next=NULL;
    }
    else{
        node  *newnode=new node();
        newnode->data=data;
        newnode->next=NULL;
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
class noder{
    public :
    node *here=NULL;
    noder *next;
};
void insert(noder *&head){
    noder *temp=head;
    if(head==NULL){
        head=new noder();
        head->next=NULL;
        cout<<"enter the numner of elements :"<<endl;
        int tempNum;
        cin>>tempNum;
        for(int i=0;i<tempNum;i++){
            int temper;
            cin>>temper;
            insert(head->here,temper);
        }
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    noder *newnode=new noder();
    newnode->next=NULL;
    cout<<"enter the numner of elements :"<<endl;
    int tempNum;
    cin>>tempNum;
    for(int i=0;i<tempNum;i++){
        int temper;
        cin>>temper;
        insert(newnode->here,temper);
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return ;
}
void print(node *head,int a=1){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void print(noder *&head){
    noder *temp=head;
    while(temp!=NULL){
        node *temphere=temp->here;
        print(temphere);
        temp=temp->next;
    }
}
int main(){
    noder *head=NULL;
    int temp;
    cout<<"enter the numeber of nodes you have "<<endl;
    cin>>temp;
    for(int i=0;i<temp;i++){
        insert(head);
    }
    print(head);
    return 0;
}
