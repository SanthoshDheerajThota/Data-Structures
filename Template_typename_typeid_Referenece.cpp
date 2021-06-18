#include <iostream>
using namespace std;
template <typename T>    // the type name is a operator to declare tpe of template argument 
class myBaseClass{       // I declare this to show virtual functions in template classes 
    protected:
        T data;   
        int intData;
    public :
        virtual void setData(){               //declared virtual so as to call derived class function 
            if(typeid(T)==typeid(string)){    //Check if the template argumet is string
                cout<<"enter the string :"<<endl;
                cin>>this->data;
                return ;
            }
            cout<<"enter the data :"<<endl;
            cin>>this->data;
        }
        virtual void printData(){
            cout<<"the data entered is "<<this->data<<endl;
        }
};
template <typename T >
class myDerivedclass:public myBaseClass<T>{
    private :
        T yet_another_data;
    public :
        void setData(){
            myBaseClass<T> :: setData();
            cout<<"enter another data :"<<endl;
            cin>>this->yet_another_data;
        }
        void printData(){
            myBaseClass<T> :: printData();
            cout<<"the yet another fata is "<<this->yet_another_data<<endl;
            return ;
        }
};
int main(){
    myBaseClass <string> *santhosh;
    santhosh=new myBaseClass<string>;
    santhosh->setData();
    santhosh->printData();
    santhosh=new myDerivedclass<string>;
    santhosh->setData();
    santhosh->printData();
    return 0;
}
