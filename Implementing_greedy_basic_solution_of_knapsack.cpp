#include <iostream>
#include <vector>
using namespace std;
int getmax(vector<float> arr){
    int max=0;
    for(int i=0;i<arr.size();i++){
        if(arr[max]<arr[i]){
            max=i;
        }
    }
    return max;
}
int main(){
    vector<int> values={10,5,15,7,8,9,4};
    vector<int> weights={1,3,5,4,1,3,2};
    vector<float> ans={0,0,0,0,0,0,0};
    vector<float> ratios={0,0,0,0,0,0,0};
    for(int i=0;i<ratios.size();i++){
        ratios.at(i)=(float)values.at(i)/weights.at(i);
    }
    int weight;
    cin>>weight;
    float value=0;
    while(weight!=0){
        int i=getmax(ratios);
        if(weights.at(i)>=weight){
            value=value+(float)weight*values.at(i)/weights.at(i);
            ans.at(i)=(float)weights.at(i)/weight;
            
            break;
        }
        else{
            value=value+(float)values.at(i);
            ans.at(i)=(float)weights.at(i);
            ratios.at(i)=0;
            weight=weight-weights.at(i);
        }
    }
    cout<<"The value is "<<value<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<values[i]<<"   ";
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<weights[i]<<"   ";
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"   ";
    }
    cout<<endl;
    return 0;
}
