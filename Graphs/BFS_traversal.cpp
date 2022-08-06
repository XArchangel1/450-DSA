#include<bits/stdc++.h>
void bfs(vector<int> &ans,unordered_map<int,set<int>> &adj,unordered_map<int, bool> &vis, int node){
    queue<int> q;
    q.push(node);
    vis[node] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        
        for(auto i : adj[frontNode]){
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int,set<int>> adj;
    unordered_map<int,bool> vis;
    
    for(auto x : edges){
        int u = x.first;
        int v = x.second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    for(int i = 0;i<vertex;i++){
        if(!vis[i]){
            bfs(ans,adj,vis,i);
        }
    }
    
    return ans;
}