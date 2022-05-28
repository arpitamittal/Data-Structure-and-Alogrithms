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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum =0;
        DFS(root,0,sum);
        return sum;
    }
    void DFS(TreeNode *root,int currSum,int &sum)
    {
        currSum = currSum*10+root->val;
        if(root->left == NULL && root->right == NULL)
            sum+=currSum;
        if(root->left)
            DFS(root->left,currSum,sum);
        if(root->right)
            DFS(root->right,currSum,sum);
    }
};