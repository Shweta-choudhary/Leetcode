//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isvalid(vector<int>& nums,int k,int mid)
    {
        int curr=0;
        
        for(int i=0;i<nums.size();i++)
        curr+=ceil((double)nums[i]/(double)mid);
        
        if(curr<=k)
        return true;
        
        return false;
    }
  
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int low=1,high=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        high=max(high,nums[i]);
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(isvalid(nums,K,mid))
            high=mid-1;
            
            else
            low=mid+1;
        }
        
        return low;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends