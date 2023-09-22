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
        int n=grid.size();
        int m=grid[0].size();
        
        int vis[n][m]={0};
        
        queue<pair<pair<int,int>,int>>q;
        int cntFresh=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                
                else
                vis[i][j]=0;
                
                if(grid[i][j]==1)
                cntFresh++;
            }
        }
        
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;
        
        while(q.empty()==0)
        {
            int nrow=q.front().first.first;
            int ncol=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            
            for(int i=0;i<4;i++)
            {
                int currow=nrow+drow[i];
                int curcol=ncol+dcol[i];
                
                if(currow>=0 && currow<n && curcol>=0 && curcol<m && vis[currow][curcol]==0 && grid[currow][curcol]==1){
                    q.push({{currow,curcol},t+1});
                    vis[currow][curcol]++;
                    cnt++;
                }
            }
        }
        
        if(cnt!=cntFresh)
        return -1;
        
        return tm;
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