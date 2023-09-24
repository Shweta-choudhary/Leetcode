//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>dist(N ,INT_MAX);
    //   creating a adj
    vector<vector<pair<int,int>>>adj(N);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
    }
    // done with adj
    dist[0]=0;
    queue<pair<int,int>>q;
    q.push({0,0});
    
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            // checking the neigbours
            for(auto it: adj[node]){
                int nei = it.first;
                int price = it.second;
                if(price+distance>=dist[nei])continue;
                dist[nei]=price+distance;
                q.push({nei , dist[nei]});
            }
        }
    }
    for(int i=0;i<N;i++){
        if(dist[i]==INT_MAX){
            dist[i]=-1;
        }
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