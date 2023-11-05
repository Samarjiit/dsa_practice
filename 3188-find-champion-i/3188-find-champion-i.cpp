class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(grid[i][j]==1)mp[j]++;
                else mp[i]++;
        }

        }

        for(int k=0;k<n;k++){
            if(mp[k]==0)
            return k;
        }
        
     return 0;
    }
};