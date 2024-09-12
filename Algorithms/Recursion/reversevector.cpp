#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &vec, int i, int &n){
    if(i== n) return;
    int num=vec[i];
    reverse(vec, i+1, n);
    vec[n-1-i]=num;
}

int main(){
    vector<int> vec={1,2,3,4};
    int n= 4;
    reverse(vec, 0, n);
    for(auto i: vec) cout<<i<<" ";

}