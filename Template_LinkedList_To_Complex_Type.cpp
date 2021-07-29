#include <iostream>
using namespace std;
template <class T>
class linked_list{
    template <class Y>
    class node{
        public :
            Y data;
            node *next;  
    };
    private:
        node<T> *head=NULL;
        int _size=0;
    public :
        void insert(T data);
        void print();
        void reverse();
};
template <class T>
void linked_list<T>::insert(T data){
    node <T> *newnode=new node<T>;
    newnode->data=data;
    newnode->next=this->head;
    head=newnode;
    return;
}
template <class T>
void linked_list<T>::print(){
    node<T> *temp=this->head;
    while(temp->next!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    return ;
}
template <class T>
void linked_list<T>::reverse(){
    node <T> *temp=head;
    node<T> *previous=NULL;
    node<T> *next=NULL;
    while(temp->next!=NULL){
        next=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next;
    }
    temp->next=previous;
    this->head=temp;
    return ;
}
class Complex{
    private :
        int real;
        int imag;
    public :
        friend ostream &operator<<(ostream &output,Complex &c);
        friend istream &operator>>(istream &input,Complex &c);
};
ostream &operator<<(ostream &output,Complex &c){
    output<<c.real<<" + "<<c.imag<<" i "<<endl;
    return output;
}
istream &operator>>(istream &input,Complex &c){
    cout<<"enter the real and imaginary part of the complex number :"<<endl;
    input>>c.real>>c.imag;
    return input;
}
int main(){
    linked_list<Complex> myList;
    int number;
    cout<<"enter the number of the numberes you want :"<<endl;
    cin>>number;
    for(int i=0;i<number;i++){
        Complex c;
        cin>>c;
        myList.insert(c);
    }
    cout<<endl<<"the data collected is :"<<endl;
    myList.print();
    return 0;
}
