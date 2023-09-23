//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>>res(n,vector<char>(m,'X'));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(mat[i][j]=='O')
                    {
                    res[i][j]='O';
                    q.push({i,j});
                    }
                }
            }
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(q.empty()==0)
        {
            int nrow=q.front().first;
            int ncol=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int r=nrow+drow[i];
                int c=ncol+dcol[i];
                
                if(r>=0 && r<n && c>=0 && c<m && mat[r][c]=='O' && res[r][c]=='X')
            {
                res[r][c]='O';
                q.push({r,c});
            }
            }
            
            
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends