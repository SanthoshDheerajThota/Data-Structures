#include <iostream>
using namespace std;
class array{
    private :
        int *arr;
        int sizeOfArray;
    public :
        array();
        void setData();
        int size();
        void printData();
        void removeDuplicates();
        void insert(int data,int index);
        void deleteTheValue(int data);
};
array::array(){
    
}
int array::size(){
    return this->sizeOfArray;
}
void array:: setData(){
    cout<<"enter the size of the array :"<<endl;
    cin>>sizeOfArray;
    arr=new int[sizeOfArray];
    for(int i=0;i<sizeOfArray;i++){
        cout<<"enter the "<<i<<" index element :"<<endl;
        cin>>this->arr[i];
    }
    return;
}
void array:: printData(){
    for(int i=0;i<this->sizeOfArray;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
void array:: removeDuplicates(){
    int temp[20]={0};
    int realSize=0;
    for(int i=0;i<sizeOfArray;i++){
        int count=0;
        for(int j=0;j<realSize;j++){
            if(arr[i]==temp[j]){
                count++;
            }
        }
        if(count==0){
            temp[realSize]=arr[i];
            realSize++;
        }
    }
    for(int i=0;i<realSize;i++){
        arr[i]=temp[i];
    }
    sizeOfArray=realSize;
}
void array:: insert(int data,int index){
    int temp[20]={0};
    for(int i=0;i<sizeOfArray;i++){
        temp[i]=arr[i];
    }
    arr=new int[sizeOfArray+1];
    for(int i=0;i<sizeOfArray;i++){
        arr[i]=temp[i];
    }
    arr[sizeOfArray]=0;
   for(int i=sizeOfArray-1;i>=index;i--){
       int temp;
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
   }
   sizeOfArray++;
   arr[index]=data;
   return ;
}
void array:: deleteTheValue(int data){
    int temp[20]={0};
    int key=0;
    for(int i=0;i<sizeOfArray;i++){
        if(arr[i]==data){
            continue;
        }
        temp[key]=arr[i];
        key++;
    }
    for(int i=0;i<sizeOfArray-1;i++){
        arr[i]=temp[i];
    }
    this->sizeOfArray-=1;
    return;
}
int main(){
    array myArray;
    myArray.setData();
    myArray.printData();
    myArray.removeDuplicates();
    myArray.printData();
    cout<<"enter the number to delete "<<endl;
    int number;
    cin>>number;
    myArray.deleteTheValue(number);
    myArray.printData();
    cout<<"enter the number and inde to add "<<endl;
    int index;
    cin>>number>>index;
    myArray.insert(number,index);
    myArray.printData();
    return 0;
}
