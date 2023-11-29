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
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        pq.push({{source.first,source.second},0});
        dist[source.first][source.second]=0;
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(pq.empty()==0)
        {
            int cr=pq.top().first.first;
            int cc=pq.top().first.second;
            int cd=pq.top().second;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int r=cr+drow[i];
                int c=cc+dcol[i];
                
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && cd+1<dist[r][c])
                {
                    dist[r][c]=cd+1;
                    pq.push({{r,c},cd+1});
                }
            }
        }
        
        if(dist[destination.first][destination.second]==INT_MAX)
        return -1;
        
        return dist[destination.first][destination.second];
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