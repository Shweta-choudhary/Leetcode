//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void func(vector<pair<int,int>>&curr)
    {
        pair<int,int>p=curr[0];
        
        for(int i=0;i<curr.size();i++)
        {
            curr[i].first-=p.first;
            curr[i].second-=p.second;
        }
    }
  
   void dfs(vector<vector<int>>& grid, vector<pair<int, int>>& curr, int i, int j, vector<vector<int>>& vis) {
    int n = grid.size();
    int m = grid[0].size();
    curr.push_back({ i, j });
    vis[i][j] = 1;

    int drow[] = { -1, 0, 1, 0 };
    int dcol[] = { 0, 1, 0, -1 };

    for (int k = 0; k < 4; k++) {
        int r = i + drow[k];
        int c = j + dcol[k];

        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && vis[r][c] == 0)
            dfs(grid, curr, r, c, vis);
    }
}

  
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
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    vector<pair<int,int>>curr;
                    dfs(grid,curr,i,j,vis);
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