//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});
        vector<int>res(n,INT_MAX);
        res[src]=0;
        
        while(pq.empty()==0)
        {
            int stop=pq.top().first;
            int node=pq.top().second.first;
            int dist=pq.top().second.second;
            pq.pop();
            
            if(stop>K)
            continue;
            
            for(auto it:adj[node])
            {
                int node1=it.first;
                int dist1=it.second;
                
                int dist2=dist+dist1;
                
                if(dist2<res[node1])
                {
                    res[node1]=dist2;
                    pq.push({stop+1,{node1,dist2}});
                }
            }
        }
        
        if(res[dst]==INT_MAX)
        return -1;
        
        return res[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends