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
    TreeNode *prev, *first, *last, *mid;
    void inorder(TreeNode* root)
    {
        if(root == NULL) return;
        inorder(root->left);
        if(prev !=NULL and prev->val > root->val)
        {
            if(first == NULL)
            {
                first = prev;
                mid = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = prev = last = mid = NULL;
        inorder(root);
        if(last == NULL) swap(first->val, mid->val);
        else swap(first->val, last->val);
    }
};