//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        
        while(q.empty()==0)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<8;i++)
            {
                int r=row+drow[i];
                int c=col+dcol[i];
                
                
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && vis[r][c]==0)
                {
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    bfs(grid,vis,i,j);
                    res++;
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