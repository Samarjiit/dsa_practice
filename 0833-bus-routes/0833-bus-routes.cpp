class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>bstoptoid;

        for(int i=0;i<routes.size();i++){
            int bid=i;
            vector<int>bstops=routes[i];
            for(auto bstop:bstops){
                bstoptoid[bstop].push_back(bid);
            }
        }

        queue<pair<int,int>>q;//currstop bustravel
        unordered_map<int,bool>bvis,btstopvis;
        q.push({source,0});
        btstopvis[source]=true;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int,int>p=q.front();
                q.pop();
                int curstop=p.first;
                int bustravel=p.second;

                if(curstop==target)return bustravel;

                for(auto bus:bstoptoid[curstop]){
                    if(bvis[bus])continue;
                    bvis[bus]=true;
                    for(auto bustop:routes[bus]){
                        if(btstopvis[bustop])continue;
                        btstopvis[bustop]=true;
                        q.push({bustop,bustravel+1});
                    }
                }
            }
        }
            return -1;
    }
};