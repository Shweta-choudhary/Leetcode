//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0' || vis[i][j]==1)
        return;
        
        vis[i][j]=1;
        
        dfs(i-1,j,grid,vis);
        dfs(i-1,j+1,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i+1,j+1,grid,vis);
        dfs(i+1,j,grid,vis);
        dfs(i+1,j-1,grid,vis);
        dfs(i,j-1,grid,vis);
        dfs(i-1,j-1,grid,vis);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int res=0;
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    res++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends