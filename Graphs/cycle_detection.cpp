#include<bits/stdc++.h>
bool cycleDetection(unordered_map<int,list<int>> adj,vector<bool> &vis,int s){
    queue<pair<int,int>> q;
    q.push({s,-1});
    vis[s] = true;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int node = x.first;
        int parent = x.second;
        for(auto i : adj[node]){
            if(vis[i] == false){
                vis[i] = true;
                q.push({i,x.first});
            }
            
            else if(vis[i] == true and i!=parent){
                return true;
            }
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<bool> vis(n+1,false);
    
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            if(cycleDetection(adj,vis,i)){
                return "Yes";
            }
        }
    }
    
    return "No";
}
