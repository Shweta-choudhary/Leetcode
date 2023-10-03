//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        vector<vector<int>>matrix(n,vector<int>(n,1e8));
        
        for(auto it:edges)
        {
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                matrix[i][j]=0;
            }
        }
        
        for(int vis=0;vis<n;vis++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=min(matrix[i][j],matrix[i][vis]+matrix[vis][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]>distanceThreshold)
                matrix[i][j]=-1;
            }
        }
        
        vector<int>count(n,0);
        
        for(int i=0;i<n;i++)
        {
            int curr=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]!=-1)
                curr++;
            }
            
            count[i]=curr;
        }
        
        int minimum=INT_MAX;
        
        for(int i=0;i<n;i++)
        minimum=min(minimum,count[i]);
        
        int res;
        
        for(int i=0;i<n;i++)
        {
            if(count[i]==minimum)
            res=i;
        }
        
        return res;
                     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends