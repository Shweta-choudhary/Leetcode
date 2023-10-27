//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void dfs(vector<int>adj[],int start,vector<int>&vis)
   {
       vis[start]=1;
       
       for(auto it:adj[start])
       {
           if(vis[it]==0)
           dfs(adj,it,vis);
       }
   }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>mat[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    mat[i].push_back(j);
                    mat[j].push_back(i);
                }
            }
        }
        
        int res=0;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                res++;
                dfs(mat,i,vis);
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends