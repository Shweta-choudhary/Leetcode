//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int>mp;
      
      for(int i=0;i<N;i++)
      mp[arr[i]]++;
      
      int ans=1;
      int curr=0;
      
      for(int i=0;i<N;i++)
      {
          int num=arr[i];
          curr=1;
          
          while(mp.find(num-1)!=mp.end())
          {
              curr++;
              ans=max(ans,curr);
              num--;
          }
      }
      
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends