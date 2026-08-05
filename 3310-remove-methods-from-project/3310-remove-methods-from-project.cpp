class Solution {
public:

    void  dfs(int node,vector<vector<int>>& adj , vector<int>& vis){
            vis[node]=1;

            for(int nxt : adj[node]){
                if(!vis[nxt]){
                    dfs(nxt,adj,vis);
                }
            }
        }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // vector<bool> suspicious(n,false);
        // suspicious[k]=true;
        // bool changed = true;

        // while(changed){
        //     changed = false;

        //     for(auto& edge : invocations){
        //         int u = edge[0];
        //         int v = edge[1];

        //         if(suspicious[u] && ! suspicious[v]){
        //             suspicious[v]=true;
        //             changed = true;
        //         }

        //     }
        // }

        // for(auto& edge : invocations){
        //     int u = edge[0];
        //     int v = edge[1];

        //     if(!suspicious[u] && suspicious[v]){
        //         vector<int>ans;
        //         for(int i =0;i<n;i++) ans.push_back(i);
        //         return ans;
        //     }
        // }
        // vector<int>ans;
        // for(int i =0;i<n;i++){
        //     if(!suspicious[i]) ans.push_back(i);
        // }
        // return ans;


        // DFS/BFS

        vector<vector<int>> adj(n);

        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(n,0);
        dfs(k,adj,vis);

        for(auto&e:invocations){
            int u = e[0];
            int v = e[1];

            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i = 0 ; i< n ; i++){
                    ans.push_back(i);
                } return ans;
            }
        }

        vector<int>ans;
        for(int i =0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        } return ans;
    }
};