class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        
        // Step 1: Compute indegree
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) indegree[v]++;
        }
        
        // Step 2: Topological order
        queue<int> q;
        for (int i = 0; i < V; i++) if (indegree[i] == 0) q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : graph[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        // Step 3: DP storing paths
        vector<vector<vector<int>>> dp(V);
        dp[0] = {{0}};  // source path starts from 0

        for (int u : topo) {
            for (int v : graph[u]) {
                for (auto path : dp[u]) {
                    path.push_back(v);
                    dp[v].push_back(path);
                }
            }
        }
        return dp[V-1]; // All paths to target
    }
};
