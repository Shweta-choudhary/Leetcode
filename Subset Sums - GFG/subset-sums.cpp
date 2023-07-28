//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
   void sum(vector<int> &arr,int N,vector<int>& res,int i,int curr)
   {
       if(i==N)
       {
           res.push_back(curr);
           return;
       }
       
       sum(arr,N,res,i+1,curr+arr[i]);
       sum(arr,N,res,i+1,curr);
   }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>res;
        int i=0;
        int curr=0;
        
        sum(arr,N,res,i,curr);
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends