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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int preindex = 0;
        return constructTree(preorder, mp, 0, inorder.size()-1, preindex);
    }
    TreeNode* constructTree(vector<int> &preorder, map<int,int>&mp,int start, int end, int &preindex)
    {
        if(start>end)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[preindex]);
        int currentIndex = mp[preorder[preindex]];
        preindex++;
        
        root->left = constructTree(preorder, mp, start, currentIndex-1, preindex);
        root->right = constructTree(preorder, mp, currentIndex+1, end, preindex);
        
        return root;
    }
};