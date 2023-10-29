class Solution {
public:
    #define ll long long   
    ll dp[100005][17];
    ll dfs(int node,int par,int f,int k,vector<int> adj[],vector<int> &coins){

        
        if(dp[node][f] != -1){
            return dp[node][f];
        }
        
       
        if(f>15) f=15;
        ll cur = (coins[node]>>(f+1));
         ll res= (coins[node]>>f)-k;
        
        for(auto child:adj[node]){
            if(child != par){
                cur+=dfs(child,node,f+1,k,adj,coins);
                res+=dfs(child,node,f,k,adj,coins);
            }
        }
        return dp[node][f] = max(cur,res); 
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        vector<int> adj[n];
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,-1,0,k,adj,coins);
    }
};