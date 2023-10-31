//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void toposort(int i,vector<pair<int,int>>adj[],int vis[],stack<int>& st)
    {
        vis[i]=1;
        
        for(auto it:adj[i])
        {
            int v=it.first;
            
            if(vis[v]==0)
            toposort(v,adj,vis,st);
        }
        
        st.push(i);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        int vis[N]={0};
        
        stack<int>st;
        
        for(int i=0;i<N;i++)
        {
            if(vis[i]==0)
            toposort(i,adj,vis,st);
        }
        
        vector<int>dist(N);
        
        for(int i=0;i<N;i++)
        dist[i]=1e9;
        
        dist[0]=0;
        
        while(st.empty()==0)
        {
            int node=st.top();
            st.pop();
            
            for(auto it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                
                if(dist[node]+wt<dist[v])
                dist[v]=dist[node]+wt;
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends