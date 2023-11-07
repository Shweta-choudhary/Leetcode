//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int newColor,int original,vector<vector<int>>& vis)
    {
        int n=image.size();
        int m=image[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || image[i][j]!=original)
        return;
        
        vis[i][j]=1;
        image[i][j]=newColor;
        
        dfs(image,i-1,j,newColor,original,vis);
        dfs(image,i,j+1,newColor,original,vis);
        dfs(image,i+1,j,newColor,original,vis);
        dfs(image,i,j-1,newColor,original,vis);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(image[sr][sc]==newColor)
        return image;
        
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
       dfs(image,sr,sc,newColor,image[sr][sc],vis);
       
       return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends