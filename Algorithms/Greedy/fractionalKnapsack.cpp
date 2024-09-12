#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, wtLeft; //number of elements, maxWeight
    cin>>n>>wtLeft;

    priority_queue<pair<double, pair<double, double>>> pq;
    for(int i = 0; i<n; ++i){
        double p, wt;
        cin>>p>>wt;
        pq.push({p/wt, {p, wt}});
    }

    double ans = 0.0;

    for(int i = 0; i<n; ++i){
        auto top = pq.top();
        double ratio = top.first;
        double wt = top.second.second;
        double p = top.second.first;
        pq.pop();

        //take whole if wt is less than current weight left
        if(wt <= wtLeft){
            ans += p;
            wtLeft -= wt;
        }
        else{ // or take partial
            ans += ratio*wtLeft; // or x/wtLeft = p/wt -> x = ratio * wtLeft
            break;
        }
    }
    cout<<ans;
}