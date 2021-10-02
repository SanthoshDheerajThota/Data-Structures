#include <iostream>
using namespace std;
class BST;
class node{
    int data;
    node *left;
    node *right;
    friend class BST;
    friend void print_level(node *root,int n);
};
class BST{
    private :
        node *root=NULL;
        int h=0;
    public :
        void insert(int data);
        void print();
        void search(int data);
        void size();
};
void print_level(node *root,int n){
    if(root==NULL){
        return ;
    }
    else if(n==1){
        cout<<root->data<<"   ";
    }
    else {
        print_level(root->left,n-1);
        print_level(root->right,n-1);
    }
}
void BST::insert(int data){
    if(this->root==NULL){
        h++;
        root=new node;
        root->data=data;
        root->left=root->right=NULL;
        return ;
    }
    else{
        node *temp=this->root;
        node *prev=NULL;
        int t=0;
        while(temp!=NULL){
            prev=temp;
            if(temp->data<data){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
            t++;
        }
        t++;
        if(h<t){
            this->h++;
        }
        node *newnode=new node;
        newnode->data=data;
        newnode->left=newnode->right=NULL;
        if(prev->data<data){
            prev->right=newnode;
        }
        else{
            prev->left=newnode;
        }
        return ;
    }
}
void BST::print(){
    for(int i=1;i<=this->h;i++){
        print_level(this->root,i);
        cout<<endl;
    }
}
void BST::search(int data){

}
void BST::size(){
    cout<<h<<endl;
}
int main(){
    BST santhosh;
    /*
                12
            5         17
         3    7    15    33
    */
    santhosh.insert(12);
    santhosh.insert(5);
    santhosh.insert(17);
    santhosh.insert(3);
    santhosh.insert(7);
    santhosh.insert(15);
    santhosh.insert(33);
    santhosh.size();
    santhosh.print();
    return 0;
}
