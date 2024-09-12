#include<bits/stdc++.h>
using namespace std;

void printname(int n, string &name){
    if(n==0) return;
    cout<<name<<endl;
    printname(n-1, name);
}

void printnum(int n){
    if(n==-1) return;
    cout<<n<<endl;
    printnum(n-1);
}

int main(){
    // string name= "guna";
    // printname(4, name);
    printnum(10);
}