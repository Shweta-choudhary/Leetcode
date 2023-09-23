//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i,vector<int>adj[],vector<int>& vis,int parent)
    {
          vis[i]=!parent;
        
        for(auto it:adj[i])
        {
            if(vis[it]==-1)
            {
                if(dfs(it,adj,vis,vis[i])==0)
                return false;
                
            }
            
            if(vis[it]==vis[i])
            return false;
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
	            if(dfs(i,adj,vis,1)==0)
	            return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends