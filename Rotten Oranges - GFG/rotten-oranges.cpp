//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int fresh=0;
        queue<pair<pair<int,int>,int>>q;
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                
                if(grid[i][j]==1)
                fresh++;
            }
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int finaltime=0;
        int rotten=0;
        
        while(q.empty()==0)
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            finaltime=max(finaltime,time);
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int r=row+drow[i];
                int c=col+dcol[i];
                
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && grid[r][c]==1)
                {
                    q.push({{r,c},time+1});
                    vis[r][c]=1;
                    rotten++;
                    
                }
            }
        }
        
        if(rotten!=fresh)
        return -1;
        
        return finaltime;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends