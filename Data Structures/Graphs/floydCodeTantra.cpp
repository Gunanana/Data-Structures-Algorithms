#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin>>n; cin>>e;

    vector<vector<int>> dist(n, vector<int>(n, 1e8));

    for(int i = 0; i<e; ++i){
        int src, wt, dest;
        cin>>src>>dest>>wt;
        dist[src][dest] = wt;
    }

    for(int k = 0; k<n; ++k){
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            if(dist[i][j] == 1e8) cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}