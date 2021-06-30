//this is completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
template <class T>
class node{
    public:
        T data;
        node <T> *next;
};
template<class T>
void insert(node <T> *&head,T data){
    node <T> *newnode=new node<T>;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    return;
}
template <class T>
void print(node <T> *head){
    while(head->next!=NULL){
        cout<<head->data<<"   ";
        head=head->next;
    }
    cout<<head->data<<endl;
   return;
}
template <class T>
void deleteAt(node<T> *head,int index){
    if (index==0){
        head=head->next;
        return ;
    }
    node<T> *previous=head;
    node<T> *next=NULL;
    for(int i=0;i<index;i++){
        previous=head;
        head=head->next;
        next=head->next;
    }
    previous->next=next;
    return ;
}
int main(){
    node <string> *head=NULL;
    for(int i=0;i<5;i++){
        string temp;
        cin>>temp;
        insert(head,temp);
    }
    print<string>(head);
    return 0;
}
