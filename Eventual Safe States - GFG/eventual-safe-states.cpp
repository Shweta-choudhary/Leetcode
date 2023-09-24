//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>adjrev[V];
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                adjrev[it].push_back(i);
            }
        }
        
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adjrev[i])
            indegree[it]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        vector<int>res;
        
        while(q.empty()==0)
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it:adjrev[node])
            {
                indegree[it]--;
                
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        sort(res.begin(),res.end());
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