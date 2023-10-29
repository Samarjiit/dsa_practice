class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if((nums[j]>>i)&1)c++;
            }
            if(c>=k)ans+=(1<<i);
        }
        return ans;
    }
};