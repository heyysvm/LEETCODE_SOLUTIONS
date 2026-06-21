class Solution {
public:

    long long dfs(int node,
                  vector<vector<int>>& adj,
                  vector<int>& baseTime)
    {
        // Leaf node
        if(adj[node].empty())
            return baseTime[node];

        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;

        for(int child : adj[node])
        {
            long long finish = dfs(child, adj, baseTime);

            mn = min(mn, finish);
            mx = max(mx, finish);
        }

        long long ownDuration = (mx - mn) + baseTime[node];

        return mx + ownDuration;
    }

    long long finishTime(int n,
                         vector<vector<int>>& edges,
                         vector<int>& baseTime)
    {
        auto torqavemi = make_tuple(n, edges, baseTime);

        vector<vector<int>> adj(n);

        for(auto &e : edges)
        {
            int parent = e[0];
            int child  = e[1];

            adj[parent].push_back(child);
        }

        return dfs(0, adj, baseTime);
    }
};