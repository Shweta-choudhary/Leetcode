//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<int>>& grid, int color) {
    int n = image.size();
    int m = image[0].size();

    if (sr < 0 || sr >= n || sc < 0 || sc >= m)
        return;

    if (image[sr][sc] != color)
        return;
        
    if(grid[sr][sc]==newColor)
    return;

    grid[sr][sc] = newColor;

    dfs(image, sr - 1, sc, newColor, grid, color);
    dfs(image, sr, sc + 1, newColor, grid, color);
    dfs(image, sr + 1, sc, newColor, grid, color);
    dfs(image, sr, sc - 1, newColor, grid, color);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = image[i][j];
        }
    }

    dfs(image, sr, sc, newColor, grid, image[sr][sc]);

    return grid;
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