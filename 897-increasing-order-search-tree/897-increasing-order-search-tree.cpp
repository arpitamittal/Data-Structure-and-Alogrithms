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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        
        TreeNode *dummyNode = new TreeNode(-1);
        TreeNode *newNode = dummyNode;
        
        for(auto i : ans)
        {
            dummyNode->right = new TreeNode(i);
            dummyNode = dummyNode->right;
        }
        return newNode->right;
    }
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
};