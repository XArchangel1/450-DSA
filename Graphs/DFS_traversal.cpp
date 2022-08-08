void dfs(int s,vector<bool> &vis,vector<int> &ans,unordered_map<int,set<int>> adj){
    vis[s] = true;
    ans.push_back(s);
    for(auto i : adj[s]){
        if(!vis[i]){
            dfs(i,vis,ans,adj);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> temp;
    vector<vector<int>> ans;
    unordered_map<int,set<int>> adj;
    vector<bool> vis(V,false);
    
    for(int i=0; i<E; i++){
        adj[edges[i][0]].insert(edges[i][1]);
        adj[edges[i][1]].insert(edges[i][0]);
    }
    
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,temp,adj);
            ans.push_back(temp);
        }
        temp.clear();
    }
    
    return ans;
}