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




// 4



// 5



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











