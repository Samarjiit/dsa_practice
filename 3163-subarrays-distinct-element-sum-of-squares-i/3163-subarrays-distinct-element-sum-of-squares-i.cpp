class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>hash;
            for(int j=i;j<nums.size();j++){
               hash[nums[j]]++;
               ans+=(hash.size()*hash.size());
            }
        }
        return ans;
    }
};