/*
    this code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
template <typename T>
class queue{
    private :
        template <class Y>
        class node {
            public :
                Y data;
                node<Y> *next;
                node<Y> *previous;
        };
        node <T> *head=NULL;
        node <T> *tail=NULL;
        int _size=0;
    public :
        void enqueue(T data){
            _size++;
            if(head==NULL){
                head=new node<T>;
                head->data=data;
                head->next=head->previous=NULL;
                tail=head;
                return;
            }
            else{
                node <T> *newnode=new node<T>;
                newnode->data=data;
                newnode->next=head;
                newnode->previous=NULL;
                head->previous=newnode;
                head=newnode;
                return ;
            }
        }
        void dequeue(){
            tail=tail->previous;
            tail->next=NULL;
            return ;
        }
        void print(){
            node <T> *temp=head;
            while(temp->next!=NULL){
                cout<<temp->data<<"   ";
                temp=temp->next;
            }
            cout<<temp->data<<endl;
            return ;
        }
        void printrev(){
            node <T> *temp=tail;
            while(temp->previous!=NULL){
                cout<<temp->data<<"   ";
                temp=temp->previous;
            }
            cout<<temp->data<<endl;
            return ;
        }
};
int main(){
    queue <string> santhosh;
    santhosh.enqueue("santhosh");
    santhosh.enqueue("is");
    santhosh.enqueue("a");
    santhosh.enqueue("very");
    santhosh.enqueue("Topper");
    santhosh.print();
    santhosh.printrev();
    santhosh.dequeue();
    santhosh.print();
    santhosh.enqueue("santhosh");
    santhosh.print();
    return 0;
}
