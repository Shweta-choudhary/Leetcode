//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(vector<int>adj[],vector<int>& vis,vector<int>& path,vector<int>& check,int i)
    {
        vis[i]=1;
        path[i]=1;
        
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            {
                if(dfs(adj,vis,path,check,it)==true)
                {
                    check[it]=0;
                    return true;
                }
            }
            
            else if(path[it]==1)
            {
                check[it]=0;
                return true;
            }
        }
        
        check[i]=1;
        path[i]=0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>path(V,0);
        vector<int>check(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            dfs(adj,vis,path,check,i);
        }
        
        vector<int>res;
        
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            res.push_back(i);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends