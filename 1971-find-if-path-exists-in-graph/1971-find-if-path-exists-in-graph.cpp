class Solution {
public:
    bool dfs(int node, map<int, vector<int>> &mp, int des, vector<bool>& vis){
        if(node == des) return true;
        vis[node] = true;
        vector<int>child = mp[node];
        for(int i: child)
        {
            if(vis[i] == false)
            {
                if(dfs(i, mp, des, vis) == true)
                {
                    return true;
                }
            }
        }
        return false;

    }



    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int, vector<int>> mp;
        vector<bool> vis(n, false);

        for(int i=0; i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);

        }
        return dfs(source, mp, destination, vis);
    }
};