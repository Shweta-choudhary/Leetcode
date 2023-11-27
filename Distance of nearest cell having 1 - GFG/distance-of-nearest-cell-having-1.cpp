//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>>res(n,vector<int>(m,INT_MAX));
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                res[i][j]=0;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    int drow[]={-1,0,1,0};
	    int dcol[]={0,1,0,-1};
	    
	    while(q.empty()==0)
	    {
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dist=q.front().second;
	        
	        q.pop();
	        
	        for(int i=0;i<4;i++)
	        {
	            int r=row+drow[i];
	            int c=col+dcol[i];
	            
	            if(r>=0 && r<n && c>=0 && c<m && res[r][c]>dist+1)
	            {
	                res[r][c]=dist+1;
	                q.push({{r,c},dist+1});
	            }
	        }
	    }
	    
	    return res;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends