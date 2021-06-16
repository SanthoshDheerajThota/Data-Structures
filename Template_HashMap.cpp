//this is completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
template <class T,class K>
class nodeMap{
    public :
        K data;
        T index;
        nodeMap *next;
};
template <class T ,class K >
class hashMap{
    private:
        nodeMap<T,K> *head;
        int sizer;
    public :
        hashMap(){
            sizer=0;
            head=NULL;
        }
        K atIndex(T index){
            nodeMap<T,K> *temp=head;
            while(temp!=NULL){
                if(temp->index==index){
                    return (temp->data);
                }
                else{
                    temp=temp->next;
                }
            }
            cout<<"the data is not present at index "<<endl;
            return;
        }
        void print(){
            nodeMap<T,K> *temp=head;
            while(temp->next!=NULL){
                cout<<"the data at index "<<temp->index<<" is "<<temp->data<<endl;
                temp=temp->next;
            }
            cout<<"the data at index "<<temp->index<<" is "<<temp->data<<endl;
            return;
        }
        void push_back(T index,K data){
            if(head==NULL||sizer==0){
                head=new nodeMap<T,K>;
                head->index=index;
                head->data=data;
                head->next=NULL;
                sizer++;
                return;
            }
            nodeMap<T,K> *newnoder=new nodeMap<T,K>;
            newnoder->index=index;
            newnoder->data=data;
            newnoder->next=head;
            head=newnoder;
            sizer++;
            return;
        }
        void deleteThe(T index){
            nodeMap<T,K> *temp=head,*previous=NULL,*nextnode=NULL;
            if(temp->index==index){
                temp=temp->next;
                return;
            }
            bool found = false;
            while(!found){
                previous=temp;
                temp=temp->next;
                nextnode=temp->next;
                if(temp->index==index){
                    found=true;
                    break;
                }
            }
            if(found){
                previous->next=nextnode;
            }
            else{
                cout<<"the index is not present in the hash Map";
            }
            return;
        }
};
int main(){
    hashMap<char,int> myMap;
    myMap.push_back('s',99);
    myMap.push_back('a',97);
    myMap.push_back('n',98);
    myMap.push_back('t',97);
    myMap.push_back('h',96);
    myMap.push_back('o',99);
    myMap.push_back('s',99);
    myMap.push_back('h',98);
    myMap.print();
    cout<<endl;
    myMap.deleteThe('o');
    myMap.print();
    cout<<endl;
    myMap.deleteThe('n');
    myMap.print();
    cout<<endl;
    myMap.deleteThe('t');
    myMap.print();
    cout<<endl;
    return 0;
}
