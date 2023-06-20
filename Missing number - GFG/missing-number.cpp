//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int A[], int N)
{
    // Your code goes here
    unordered_map<int,int>mp;
    
    for(int i=0;i<N;i++)
    mp[A[i]]++;
    
    int count=1;
    
    for(int i=0;i<N;i++)
    {
        if(mp.find(count)==mp.end())
        return count;
        
        count++;
    }
    
    return count;
}