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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int poststart,int postend){
        if(instart>inend)return NULL;

        TreeNode*root=new TreeNode(postorder[postend]);
        int i = instart;

        int root_can=root->val;
        for(;i<=inend;i++){
            if(inorder[i]==root_can)break;
        }

        int leftsize=i-instart;
        int rightsize=inend-i;

        root->left=solve(inorder,postorder,instart,i-1,poststart,poststart+leftsize-1);
        root->right=solve(inorder,postorder,i+1,inend,postend-rightsize,postend-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode*root=NULL;
        int n=inorder.size();
        int instart=0;
        int inend=n-1;
        int poststart=0;
        int postend=n-1;
        root=solve(inorder,postorder,instart,inend,poststart,postend);
        return root;
    }
};