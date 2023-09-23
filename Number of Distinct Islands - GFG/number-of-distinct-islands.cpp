//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void func(vector<pair<int,int>>& curr)
    {
        pair<int,int>p=curr[0];
        
        for(int i=0;i<curr.size();i++)
        {
        curr[i].first-=p.first;
        curr[i].second-=p.second;
        }
    }
    
    void dfs(int i,int j,vector<vector<int>>&grid,vector<pair<int,int>>& curr,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        curr.push_back({i,j});
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        for(int i1=0;i1<4;i1++)
        {
            int r=i+drow[i1];
            int c=j+dcol[i1];
            
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && vis[r][c]==0)
            dfs(r,c,grid,curr,vis);
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>s;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    vector<pair<int,int>>curr;
                    dfs(i,j,grid,curr,vis);
                    sort(curr.begin(),curr.end());
                    func(curr);
                    s.insert(curr);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends