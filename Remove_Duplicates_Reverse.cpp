/*
    1602-20-735-158  T.Santhosh Dheeraj
    Sir the asignment had two problems that to

    1)Create member function to reverse Singly Linked List
        Sir,to achieve so I used three nodes of which one node is to store current node and 
        other two to store previous and next nodes so I can use the method
                next = current->next;
                current->next=previous;
                previous = current;
                current = next;
            By doing this untill current!=NULL we can reverse the singky linked list

    2)Create member function to remove duplicates 
        Sir,to achieve this I created another linked list and used a integer list to keep
        the record if the data element has appeared previously.I started iterating through
        the linked list  and checked if data repeated before if not inserted in answer list
        and at last made 
                        this->head=answer.head
    
    Sir I implemented ADT 
*/
#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
};
class linked_list{
    private :
        node *head;
    public :
        linked_list();
        void insert(int data);
        void print();
        void reverse();
        void delete_duplicates();
};
linked_list:: linked_list(){
    head=NULL;
}
void linked_list::insert(int data){
    if(head==NULL){
        head=new node;
        head->data=data;
        head->next=NULL;
        return ;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    return ;
}
void linked_list::print(){
    node *temp=this->head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    delete temp;
    cout<<endl;
    return ;
}
void linked_list::reverse(){
    node *temp=this->head;
    node *previous=NULL;
    node *next=NULL;
    while(temp->next!=NULL){
        next=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next;
    }
    temp->next=previous;
    head=temp;
    return ;
}
void linked_list::delete_duplicates(){
    int list[20]={0},size=0;
    node *temp=head;
    linked_list answer;
    while(temp!=NULL){
        int key=temp->data;
        int isThere=0;
        for(int i=0;i<size;i++){
            if(list[i]==key){
                isThere++;
                break;
            }   
        }
        if(isThere==0){
            answer.insert(key);
            list[size]=key;
            size++;
        }
        temp=temp->next;
    }
    this->head=answer.head;
}
int main(){
    linked_list santhosh;
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        int buff;
        cin>>buff;
        santhosh.insert(buff);
    }
    cout<<"the entered linked list is :"<<endl;
    santhosh.print();
    santhosh.reverse();
    cout<<"the reverse of linked list is :"<<endl;
    santhosh.print();
    santhosh.delete_duplicates();
    cout<<"the linked list after removing duplicates is :"<<endl;
    santhosh.print();
    return 0;
}
