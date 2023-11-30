//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end)
        return 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,start});
        vector<int>res(100000,INT_MAX);
        int mod=100000;
        res[start]=0;
        
        while(pq.empty()==0)
        {
            int step=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:arr)
            {
                int num=(node*it)%mod;
                
                if(step+1<res[num])
                {
                    res[num]=step+1;
                    
                    pq.push({step+1,num});
                    
                    if(num==end)
                    return step+1;
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends