#include <bits/stdc++.h>
using namespace std;

void generateSubSequences(int index, vector<int> &arr, vector<int> &ds, int n){
    if(index==n){
        for(int x: ds) cout<<x<<" ";
        cout<<endl;
        return;
    }   
    ds.push_back(arr[index]);
    generateSubSequences(index+1,arr,ds,n);
    ds.pop_back();
    generateSubSequences(index+1,arr,ds,n);
}
int main(){
    vector<int> arr={1,2,3};
    int n=3;
    vector<int> ds;
    generateSubSequences(0,arr,ds,n);
    return 0;
}  