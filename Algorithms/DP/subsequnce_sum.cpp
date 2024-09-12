#include<bits/stdc++.h>
using namespace std;

//ALL SUBSEQUENCES
void ssq(int ind, vector<int> &arr,vector<vector<int>> &ans, vector<int> &temp, int &sum, int s, int n){
    //base condition
    if(s>=sum || ind>=n){
        if(s==sum) ans.push_back(temp);
        return;
    }

    //pick case
    temp.push_back(arr[ind]);
    s+=arr[ind];
    ssq(ind+1, arr, ans, temp, sum, s, n);
    temp.pop_back();
    s-=arr[ind];

    //not pick case
    ssq(ind+1, arr, ans, temp, sum, s, n);
}

//FIRST SUBSEQUENCE ONLY
bool ssq1(int ind, vector<int> &arr,vector<vector<int>> &ans, vector<int> &temp, int &sum, int s, int n){
    //base condition
    if(s>=sum || ind>=n){
        if(s==sum){
            ans.push_back(temp);
            return true;
        }
        return false;
    }

    //pick case
    temp.push_back(arr[ind]);
    s+=arr[ind];
    if(ssq1(ind+1, arr, ans, temp, sum, s, n)) return true;
    temp.pop_back();
    s-=arr[ind];

    //not pick case
    if(ssq1(ind+1, arr, ans, temp, sum, s, n)) return true;
    return false;
}

//COUNT OF SUBSEQUENCES
int ssq2(int ind, vector<int> &arr, vector<int> &temp, int &sum, int s, int n){
    //base condition
    if(s>=sum || ind>=n){
        if(sum==s) return 1;
        return 0;
    }

    //pick case
    s+=arr[ind];
    temp.push_back(arr[ind]);
    int p= ssq2(ind+1, arr, temp,sum,s,n);
    s-=arr[ind];
    temp.pop_back();

    //not pick case
    int np=ssq2(ind+1, arr, temp, sum, s,n);

    return p+np;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    vector<vector<int>> ans;
    vector<int> temp;
    int sum=15;
    cout<<ssq2(0, arr,temp, sum, 0, 8);
    // for(auto vecs: ans){
    //     cout<<endl;
    //     for(int e: vecs){
    //         cout<<e<<" ";
    //     }
    // }
}