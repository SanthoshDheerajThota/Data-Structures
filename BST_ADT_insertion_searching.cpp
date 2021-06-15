#include <iostream>
using namespace std;
class noder{                // I declared data public to keep it simple but can be private and 
    public :               //  all functions can be declared friend but this is just an example of implementation
        int data;
        noder *left,*right;
};
class BST{
    private :
        noder *root;
        int numberOfElements;
    public :
        BST();
        void insert(int data);
        void search(int data);
        void printLevel(int level);
};
void createnode(noder *&p,int data){
    p=new noder;
    p->data=data;
    p->left=NULL;
    p->right=NULL;
}
void printGivenLevel(noder *root,int level){
    noder *head=root;
    if (head == NULL)
        return;
    if (level == 1)
        printf("%d ", head->data);
    else if (level > 1)
    {
        printGivenLevel(head->left, level-1);
        printGivenLevel(head->right, level-1);
    }
}
BST::BST(){
    numberOfElements=0;
    root = NULL;
}
void BST::insert(int data){
    if(root==NULL){
        root=new noder;
        createnode(root,data);
        return;
    }
    noder *temp=root;
    noder *previous=NULL;
    while(temp!=NULL){
        previous=temp;
        if(temp->data==data){
            cout<<"the element is already present "<<endl;
            return;
        }
        else if(data<temp->data){
            temp=temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    noder *newnoder=new noder;
    createnode(newnoder,data);
    if(data<previous->data){
        previous->left=newnoder;
    }
    else{
        previous->right=newnoder;
    }
    return;
}
void BST::search(int data){
    noder *temp=root;
    while(temp!=NULL){
        if(temp->data==data){
            cout<<"the data is found"<<endl;
            return;
        }
        else if(data<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    cout<<"the "<<data<<" is not present in the BST"<<endl;
}
void BST::printLevel(int level){
    printGivenLevel(root,level);
    cout<<endl;
}
int main(){
  BST myTree;
  myTree.insert(12);
  myTree.insert(10);
  myTree.insert(14);
  myTree.insert(11);
  myTree.insert(9);
  myTree.insert(13);
  myTree.insert(15);
  myTree.printLevel(1); 
  myTree.printLevel(2); 
  myTree.printLevel(3); 
}
