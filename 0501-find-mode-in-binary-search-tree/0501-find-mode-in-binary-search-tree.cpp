/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(unordered_map<int,int>&mp,TreeNode*root){
      if(root==nullptr)return;
        mp[root->val]++;
        dfs(mp,root->left);
        dfs(mp,root->right);
      
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        dfs(mp,root);
    
        int maxfreq=0;
        for(auto&[key,val]:mp){
            maxfreq=max(maxfreq,val);
        }


        vector<int>ans;
        for(auto&[key,val]:mp){
            if(val==maxfreq)ans.push_back(key);
        }
        return ans;
    }
};