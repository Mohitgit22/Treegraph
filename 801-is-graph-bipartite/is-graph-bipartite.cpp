class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int u, int currcolor){
         color[u] = currcolor;

         for(int &v : graph[u]){
            if(color[v] == currcolor)
            return false;
            if(color[v] == -1){
            if(dfs(graph, color, v, 1-currcolor) == false)
            return false;
            }
         }
         return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> color(n, -1);

      for(int i = 0; i < n; i++) {
        if(color[i] == -1 and dfs(graph, color, i, 1) == false) return false;
      }
      return true;
    }
};