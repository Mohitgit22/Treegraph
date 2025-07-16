class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x, vector<int>& parent) {
        if(x == parent[x])
        return x;

        return parent[x] = find(parent[x], parent);
    }

    void  Union(int x, int y, vector<int>& parent, vector<int>& rank) {
      int x_parent = find(x, parent);
      int y_parent = find(y, parent);

      if(x_parent == y_parent) 
      return ;

      if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
      }else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
      }else{
        parent[y_parent] = x_parent;
        rank[x_parent]++;
      }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1)
        return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int components = n; 

        for(auto &vec : connections) {
            if(find(vec[0], parent) != find(vec[1], parent)){
                Union(vec[0], vec[1], parent, rank);
                components--;
            }
        }
        return components-1;
    }
};