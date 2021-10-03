/*
    This code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> array;
class node{
    public :
        int data;
        node *left;
        node *right;
};
class BST{
    public :   
        node *root=NULL;
        int h=0;
    public :
        void insert(int data);
        void printarray();
        void search(int key);
        void print();
        void size();
};
void print(node *head,int level){
    if(head==NULL){
        return ;
    }
    else if(level==1){
        cout<<head->data<<"   ";
    }
    else{
        print(head->left,level-1);
        print(head->right,level-1);
    }
}
void checkBST(){
    
}
void BST::insert(int data){
    if(root==NULL){
        root=new node;
        root->data=data;
        root->left=root->right=NULL;
        h++;
        return ;
    }
    else{
        node *temp=this->root;
        node *prev=NULL;
        int k=1;
        while(temp!=NULL){ 
            k++;
            prev=temp;
            if(temp->data==data){
                return ;
            }
            else if(temp->data<data){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
           
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
        if(k>h){
            h++;
        }
    }
}
void makearray(node *root,int level){
    if(level==1){
        array.push_back(root->data);
    }
    else if(root==NULL){
        return ;
    }
    else{
        makearray(root->left,level-1);
        makearray(root->right,level-1);
    }
}
void BST::printarray(){
    for(int i=1;i<=h;i++){
        ::makearray(this->root,i);
    }
    sort(array.begin(),array.end());
    for(int i=0;i<array.size();i++){
        cout<<array.at(i)<<"   ";
    }
    cout<<endl;
}
void BST::search(int key){
    node *temp=this->root;
    while(temp!=NULL){
        if(temp->data==key){
            cout<<"found"<<endl;
        }
        else if(temp->data<key){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    cout<<"not found "<<endl;
}
void BST::print(){
    for(int i=1;i<=h;i++){
        ::print(this->root,i);
        cout<<endl;
    }
    cout<<endl;
}
void BST::size(){
    cout<<h<<endl;
}
void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"   ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"   ";
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<"   ";
    inorder(root->right);
}
int main(){
    /*
                     15
              7               19
         3        9       17      33
       2   4    8   10  16  18  22  99
    */
    BST santhosh;
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        santhosh.insert(temp);
    }
    santhosh.print();
    cout<<"the inorder traversal is :"<<endl;
    inorder(santhosh.root);
    cout<<endl;
    cout<<"the preorder traversal is :"<<endl;
    preorder(santhosh.root);
    cout<<endl;
    cout<<"the postorder traversal is :"<<endl;
    postorder(santhosh.root);
    cout<<endl;
    return 0;
}
