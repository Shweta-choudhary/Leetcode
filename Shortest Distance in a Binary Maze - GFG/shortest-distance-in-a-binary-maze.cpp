//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{source.first,source.second}});
        
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        
        vis[source.first][source.second]=0;
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(pq.empty()==0)
        {
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist+1<vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=dist+1;
                    pq.push({vis[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        
        if(vis[destination.first][destination.second]==INT_MAX)
        return -1;
        
        return vis[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends