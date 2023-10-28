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
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({0,{i,j}});
                
                if(grid[i][j]==1)
                fresh++;
            }
        }
        
        int rotten=0;
        int time=0;
        
        while(q.empty()==0)
        {
            int t=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            time=max(time,t);
            
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int r=row+drow[i];
                int c=col+dcol[i];
                
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1)
                {
                    rotten++;
                    grid[r][c]=2;
                    q.push({t+1,{r,c}});
                }
            }
        }
        
        if(rotten!=fresh)
        return -1;
        
        return time;
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