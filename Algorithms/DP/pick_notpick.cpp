#include<bits/stdc++.h>
using namespace std;

void subsequences(int ind, int n, vector<int> &arr, vector<int> &temp, vector<vector<int>> &combi ){
    //base case
    if(ind >= n){
        combi.push_back(temp);
        return;
    }

    //not pick case
    subsequences(ind+1, n, arr, temp, combi); //move this below pick case if u want to pick first and then not pick

    //pick case
    temp.push_back(arr[ind]);
    subsequences(ind+1, n, arr, temp, combi);
    temp.pop_back();
}

int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> combi;
    vector<int> temp;
    subsequences(0,3,arr,temp,combi);

    for(auto vecs: combi){
        if(vecs.size()==0) cout<<"{}";
        for(auto e: vecs){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}