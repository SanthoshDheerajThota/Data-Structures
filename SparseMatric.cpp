//this code is comoletely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class nodehere{
    public :
        int row;
        int coulumn;
        int value;
        nodehere *next;
};
int main(){
    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    nodehere *head=NULL;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(sparseMatrix[i][j]!=0){
                if(head==NULL){
                    head=new nodehere();
                    head->row=i;
                    head->coulumn=j;
                    head->value=sparseMatrix[i][j];
                    head->next=NULL;
                }
                else{
                    nodehere *newnode=new nodehere();
                    newnode->value=sparseMatrix[i][j];
                    newnode->row=i;
                    newnode->coulumn=j;
                    newnode->next=head;
                    head=newnode;
                }
            }
        }
    }
    nodehere *temp=head;
    while(temp->next!=NULL){
        cout<<temp->row<<"->"<<temp->coulumn<<"->"<<temp->value<<endl;
        temp=temp->next;
    }
    cout<<temp->row<<"->"<<temp->coulumn<<"->"<<temp->value<<endl;
    cout<<endl;
}
