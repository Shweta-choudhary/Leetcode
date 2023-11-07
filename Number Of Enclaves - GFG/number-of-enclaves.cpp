//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> res(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    
    // Marking cells connected to the border
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                res[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    
    // BFS to mark all connected land cells
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int r = row + drow[i];
            int c = col + dcol[i];
            
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && res[r][c] == 0) {
                res[r][c] = 1;
                q.push({r, c});
            }
        }
    }
    
    int count = 0;
    // Count the number of enclaves
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && res[i][j] == 0) {
                count++;
            }
        }
    }
    
    return count;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends