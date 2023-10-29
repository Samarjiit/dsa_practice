class Solution {
public:
    long long dp[100005][5];
    long long f(int i,long long cnt,vector<int>& ar, long long k){
        if(cnt>=3) return 1e15;
        if(i==ar.size()) return 0;
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        if(ar[i]<k) return dp[i][cnt]= min(f(i+1,cnt+1,ar,k),f(i+1,0,ar,k)-ar[i]+k);
       
        return dp[i][cnt]=f(i+1,0,ar,k);   //if ar[i]>=k we update cnt=0
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        memset(dp,-1,sizeof(dp));
        return f(0,0,nums,k);
    }
};