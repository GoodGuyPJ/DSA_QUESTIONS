// 1 - BFS traversal
vector<int> bfs( int V, vector<int> adj[]){
  itn vis[V] = {0};
  vis[0] = 1;
  queue<int> q;
  q.push(0);
  vector<int> bfs;
  while(!q.empty()){
    int node = q.front();
    q.pop();

    bfs.push_back(node);
    for(auto it : adj[node]){
      if(!vis[it]){
        vis[it] =1;
        q.push(it);
      }
    }
  }
  return bfs;
}
Tc-> O(N) + O(2*Edges)
SC- O(N)


// 2 DFS
class Solution{
  public:
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
  vis[node] = 1;
  ls.push_back(node);
  for(auto it: adj[node]){
    if(!vis[it]){
      dfs(it, adj, vis, ls);
    }
  }
}
  vector<int> dfsofGraph(int V, vector<int adj[]){
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;

    dfs(start, adj, vis, ls);

    return ls;
  }
};

TC -> O(N) + O(2*Edges)
SC-> O(N)

// 3 Number of Provinces

class Solution {
public:
    int n;
    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;
        
        //Visit neighbours
        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        
        return count;
        
    }
};




// 4 Number of Islands
 class Solution{
  public:
  void bfs( int row, int col, vector<vector<int>>& vis, vector<vector<char>> grid){
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    int n = grid.size(), m = grid[0].size();
    while(!q.empty()){
      int row = q.fornt().first;
      int col = q.front().second;
      q.pop();

      for(int delRow = -1; delRow <= 1; delRow++){
        for(int delCol = -1; delCol<=1; delCol++){
          int nRow = row + delRow;
          int nCol = col + delCol;

          if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && !vis[nRow][nCol] && grid[nRow][nCol] == '1' ){
            vis[nRow][nCol] = 1;
            q.push({nRow, nCol});
          }
        }
      }
    }
  }

  int numIsLands(vector<vector<char>> & grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vis(m, 0));
    itn cnt = 0;
    for(int row = 0; row < n; row++){
      for(int col = 0; col <m; col++){
        if(!vis[row][col] && grid[row][col] == '1'){
            cnt++;
            bfs(row, col, vis, grid);
        }
      }
    }
    return cnt;
  }

 };



// 5 Flood Fill Algorithm
class Solution {
public:

void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image,
int newColor, int delRow[], int delCol[], int iniColor){
    ans[row][col] = newColor;
    int n = image.size(), 
    m = image[0].size();
    for(int i= 0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >=0 && nrow<n && ncol >=0 && ncol <m
        && image[nrow][ncol] == iniColor &&
        ans[nrow][ncol] != newColor){
            dfs(nrow, ncol, ans, image, newColor,
            delRow, delCol, iniColor);
        }
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, color, delRow, delCol, 
        iniColor);

        return ans;
    }
};



// 6



// 7



// 8






// 9



// 10



// 11



// 12



// 13



// 14



// 15



// 16



// 17



// 18



// 19



// 20











