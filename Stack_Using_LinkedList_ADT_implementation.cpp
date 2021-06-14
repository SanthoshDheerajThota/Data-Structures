// done by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class node{
    protected :
        int data;
        node *next;
    public :
        friend class stack;          //declaring stack class as a friend inorder to access the data and complete linked list
};
class stack{
    private :
        node *head;
        int *arr;
        int top;
    public :
        stack();                //constructot to initialixe top=-1
        int size();             //To know the size of the stack
        void push(int data);    //To push a data into the stack by LIFO order
        void pop();             //To pop the last element as LIFO principle
        void peek();            //To print the element at the top of stack
        void print();           //To print the whole stack in the order top->bottom
};
stack::stack(){
    top=-1;                
}
void stack::push(int data){
    if(top==-1){
        top++;
        head=new node;
        head->data=data;
        head->next=NULL;
        return;
    }
    node *newnode=new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    top++;
    return;
}
int stack::size(){                   //this is just to know the size of the linked list 
    return (this->top+1);
}
void stack::print(){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void stack::peek(){
    cout<<head->data<<endl;
}
void stack::pop(){
    top--;
    this->peek();
    head=head->next;
}
int main(){
    stack *head=new stack;
    head->push(29);
    head->push(74);
    head->push(36);
    head->push(64);
    head->push(63);
    head->push(333);
    head->print();
    cout<<head->size()<<endl;
    head->pop();
    head->print();
    cout<<head->size()<<endl;
}
