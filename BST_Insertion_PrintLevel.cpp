//written by T.santhosh Dheeraj
#include <iostream>
using namespace std;
class node{                // I declared data public to keep it simple but can be private and 
    public :               //  all functions can be declared friend but this is just an example of implementation
        int data;
        node *left,*right;
};
void createnode(node *&p,int data){
    p=new node;
    p->data=data;
    p->left=NULL;
    p->right=NULL;
}
void insert(node *&head,int data){
    if(head==NULL){
        head->data=data;
        head->left=NULL;
        head->right=NULL;
        return;
    }
    node *root=head;
    node *previous=NULL;
    while(root!=NULL){
        previous=root;
        if(root->data==data){
            cout<<"the "<<data<<" is already present can\'t be insereted again"<<endl;
            return;
        }
        else if(data<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    node *thisnode;
    createnode(thisnode,data);
    if(data<previous->data){
        previous->left=thisnode;
    }
    else{
        previous->right=thisnode;
    }
    return;
}
void search(node *root,int data){
    node *temp=root;
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
void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int main(){
    node *root;
    createnode(root,10);
    /*
                    10                          This is the binary tree that
                /       \
             8           15                     I inserted and as input
           /   \      /      \
         4      9    12       18
        / \         /  \     /  \
       3   5       13  14   17  19
    */
    insert(root,8);
    insert(root,15);
    insert(root,4);
    insert(root,9);
    insert(root,12);
    insert(root,18);
    insert(root,3);
    insert(root,5);
    insert(root,13);
    insert(root,14);
    insert(root,17);
    insert(root,19);
    printGivenLevel(root,3);          // The output is 4 9 12 18
    return 0;
}
