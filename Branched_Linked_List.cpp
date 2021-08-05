/*
      This code is completely written by T.Santhosh Dheeraj
*/
#include <iostream>
using namespace std;
class mainnode{
    public :
        string word;
        mainnode *next;
        mainnode(){
            next=NULL;
        }
};
class node{
    public :
        mainnode *head;
        node *next;
        node(){
            head=NULL;
        }
};
class myClass{
    private :
        node *header;
        int _size;
    public :
        myClass(){
            header=NULL;
            _size=0;
        }
        void insert(){
            int n;
            cout<<"enter the number of words :"<<endl;
            cin>>n;
            string s[n];
            for(int i=0;i<n;i++){
                cin>>s[i];
            }
            node *newone=new node;
            for(int i=0;i<n;i++){
                mainnode *newnode=new mainnode;
                newnode->word=s[i];
                newnode->next=newone->head;
                newone->head=newnode;
            }
            newone->next=header;
            header=newone;
            
        }
        void print(){
            cout<<endl;
            node *temp=this->header;
            while(temp!=NULL){
                mainnode *here=temp->head;
                while(here!=NULL){
                    cout<<here->word<<"   ";
                    here=here->next;
                }
                cout<<endl;
                temp=temp->next;
            }
            cout<<endl;
        }
};
int main(){
    myClass santhosh;
    int number_of_word_tracks;
    cout<<"enter the number of word tracks :"<<endl;
    cin>>number_of_word_tracks;
    for(int i=0;i<number_of_word_tracks;i++){
        cout<<"For the word Track "<<i+1<<"   enter  :"<<endl;
        santhosh.insert();
        cout<<endl;
    }
    santhosh.print();
    return 0;
}
