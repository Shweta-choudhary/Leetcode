//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(string &s, string &d, vector<string> &ans, vector<int> &freq)
{
    if (d.size() == s.size())
    {
        ans.push_back(d);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (freq[i] == 0)
        {
            d.push_back(s[i]);
            freq[i] = 1;
            solve(s, d, ans, freq);
            freq[i] = 0;
            d.pop_back();

           
            while (i + 1 < s.size() && s[i] == s[i + 1])
                i++;
        }
    }
}

vector<string> find_permutation(string s)
{
    vector<string> ans;
    string d;
    vector<int> freq(s.size(), 0);

    
    sort(s.begin(), s.end());

    solve(s, d, ans, freq);

    return ans;
}

};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends