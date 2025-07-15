class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<bool>& vis, vector<bool>& inRec, vector<bool>& safe) {
        vis[u] = true;
        inRec[u] = true;

        for (int &v : graph[u]) {
            if (!vis[v]) {
                if (!dfs(graph, v, vis, inRec, safe)) return false;
            } else if (inRec[v]) {
                return false;  // Found a cycle
            }
        }

        inRec[u] = false;
        safe[u] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false), inRec(n, false), safe(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(graph, i, vis, inRec, safe);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (safe[i]) res.push_back(i);
        }

        return res;
    }
};
