//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> charMap; // Mapping from characters in s to characters in t
        unordered_set<char> mappedChars; // Set to track characters that have already been mapped in t

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (charMap.find(c1) != charMap.end()) {
                // If c1 has been mapped, check if the mapping is consistent
                if (charMap[c1] != c2)
                    return false;
            } else {
                // If c1 is not mapped yet, make sure c2 is not already mapped to another character
                if (mappedChars.find(c2) != mappedChars.end())
                    return false;

                // Add the mapping of c1 to c2
                charMap[c1] = c2;
                mappedChars.insert(c2);
            }
        }

        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends