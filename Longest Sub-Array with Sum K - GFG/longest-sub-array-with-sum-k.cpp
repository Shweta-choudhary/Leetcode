//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int res=0;
        int curr=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<N;i++)
        {
            curr+=A[i];
            
            if(curr==K)
            res=max(res,i+1);
            
            if(mp.find(curr)==mp.end())
            mp[curr]=i;
            
            if(mp.find(curr-K)!=mp.end())
            res=max(res,i-mp[curr-K]);
        }
        
        return res;
    } 
    

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends