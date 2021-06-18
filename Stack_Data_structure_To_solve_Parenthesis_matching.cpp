//this is completely written by T.santhosh Dheeraj
#include <iostream>
using namespace std;
class node{
    private :
        int data;
        node *next;
    public :
        friend class stack;
};
class stack{
    private :
        node *head;
        int *arr;
        int top;
    public :
        stack();                // constructot to initialize top=-1
        int size();             // To know the size of the stack
        void push(int data);    // To push a data into the stack by LIFO order
        void pop();             // To pop the last element as LIFO principle
        void peek();            // To print the element at the top of stack
        void print();           // To print the whole stack in the order top->bottom
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
    head=head->next;
}
void checkIfParenthesisAreMatched(){
    stack mystack;
    string name;
    int tracker=0;
    cout<<"enter the string :"<<endl;
    cin>>name;
    for(int i=0;i<name.size();i++){
        if(name[i]=='{'||name[i]=='('){
            mystack.push(name[i]);
        }
        if(name[i]=='}'||name[i]==')'){
            if(mystack.size()==0){
                break;
            }
            else{
                mystack.pop();
            }
        }
        tracker++;
    }
    if(mystack.size()==0&&tracker==name.size()){
        cout<<"the parenthesis are matched "<<endl;
        return ;
    }
    else{
        cout<<"the parenthesis are not balanced "<<endl;
    }
}
int main(){
    int testCases;
    cin>>testCases;
    for(int i=0;i<testCases;i++){
        checkIfParenthesisAreMatched();
    }
}
