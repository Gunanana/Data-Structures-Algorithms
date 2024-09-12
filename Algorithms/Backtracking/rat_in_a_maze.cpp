#include<bits/stdc++.h>
using namespace std;


//DFS APPROACH
class Solution{
    public:
    void dfs(int row, int col, int n,
    vector<vector<int>> &m,
    vector<vector<bool>> &visited,
    vector<pair<int,int>> &directions,
    string &path,
    vector<string> &ans){
        visited[row][col] = true;
        if(row==n-1 && col == n-1) ans.push_back(path);
        
        for(auto dir: directions){
            int nr= row+ dir.first;
            int nc= col+ dir.second;
            
            if( (nr > -1 && nr<n) && (nc<n && nc>-1) && m[nr][nc] && !visited[nr][nc]){
                char ch;
                if(dir.first == 0){
                    if(dir.second == 1) ch='R';
                    else ch= 'L';
                }
                else if (dir.first == -1) ch='U';
                else ch='D';
                
                path.push_back(ch);
                dfs(nr,nc,n,m,visited,directions,path,ans);
                
            }
        }
        visited[row][col] =false;
        path.pop_back();
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        //apply normal dfs first, check if it works
        vector<pair<int,int>> directions = {{0,1}, {-1,0}, {1,0}, {0,-1}};
        vector<vector<bool>> visited(n, vector<bool> (n));
        vector<string> ans;
        string path="";
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return {};
        
        dfs(0, 0, n, m, visited, directions, path, ans);
        return ans;
    }
};
