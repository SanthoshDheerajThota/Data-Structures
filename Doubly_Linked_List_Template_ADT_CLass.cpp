/*
    This code is completely written by T.Santhosh Dheeraj
    This is the usage of container Templaate class as a private member of a list class that has member functions following ADT
*/
#include <iostream>
using namespace std;
template <class T>
class list{
    private :
        template <class Y>
        class node{
            public :
                Y data;
                node *previous,*next;
        };
        node <T> *head=NULL;
        node <T> *last=NULL;
        int _size=0;
    public :
        void insert(T data);
        void print();
        void printrev();
        void insert_at(T data,int index);
        void delete_at(int index);
        int size();
};
template<class T>
void  list<T>:: insert(T data){
    _size++;
    if(this->head==NULL){
        this->head=new node <T>;
        this->head->data=data;
        this->head->previous=this->head->next=NULL;
        this->last=this->head;
        return ;
    }
    node <T> *newnode= new node<T>;
    newnode->data=data;
    newnode->next=head;
    newnode->previous=NULL;
    head->previous=newnode;
    head=newnode;
    return ;
}
template<class T>
void  list<T>:: print(){
    node<T> *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return ;
}
template<class T>
void  list<T>:: printrev(){
    node<T> *temp=this->last;
    while(temp->previous!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->previous;
    }
    cout<<temp->data<<endl;
    return ;
}
template<class T>
void  list<T>:: insert_at(T data,int index){
    if(_size<index){
        return ;
    }
    _size++;
    node<T> *temp=this->head;
    node<T> *previous=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
    }
    node <T> *newnode=new node<T>;
    newnode->data=data;
    newnode->next=temp;
    temp->previous=newnode;
    previous->next=newnode;
    newnode->previous=previous;
    return ;
}
template<class T>
void  list<T>:: delete_at(int index){
    if(_size<index){
        return ;
    }
    _size--;
    node <T> *temp=this->head;
    node <T> *previous=NULL;
    node <T> *next=NULL;
    for(int i=0;i<index;i++){
        previous=temp;
        temp=temp->next;
        next=temp->next;
    }
    previous->next=next;
    next->previous=previous;
    return ;
}
template<class T>
int  list<T>:: size(){
    return _size;
}
int main(){
    list<string> santhosh;
    for(int i=0;i<10;i++){
        string temp;
        cin>>temp;
        santhosh.insert(temp);
    }
    santhosh.print();
    santhosh.printrev();
    cout<<santhosh.size()<<endl;
    santhosh.delete_at(3);
    santhosh.print();
    santhosh.printrev();
    return 0;
}
