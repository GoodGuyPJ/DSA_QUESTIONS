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



// 2



// 3



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











