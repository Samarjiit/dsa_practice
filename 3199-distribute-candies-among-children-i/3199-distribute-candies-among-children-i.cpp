class Solution {
public:
   long long dp[50][51];
    long long solve(int i,int n,int limit){
        if(i==3){
            if(n==0)return 1;
            return 0;
        }
        if(n==0)return 1;

        if(dp[i][n]!=-1)return dp[i][n];

        long long ans=0;
        for(int candy=0;candy<=min(n,limit);candy++){
            ans+=solve(i+1,n-candy,limit);
        }
        return dp[i][n]=ans;
    }
    int distributeCandies(int n, int limit) {
        memset(dp,-1,sizeof(dp));
            return solve(0,n,limit);
    }
};