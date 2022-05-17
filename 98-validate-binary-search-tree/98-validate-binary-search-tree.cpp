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
 
      5
     / \
    1   4
       / \
      3   6
     Root:- 
     5 -> T && F = false
    left :-
    1 ->  1 > -999999 -> true
    prev = 5
    Right :-
    4 ->  F && T  = false
       3 < 5  -> false
       6 > 5  -> true
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long prev[1]= {-9999999999999};
        return valid(root,prev);
    }
    bool valid(TreeNode *root, long prev[1])
    {
        if(root==NULL)
            return true;
        bool left = valid(root->left,prev);
        if(root->val<=prev[0]) return false;
        prev[0] = root-> val;
        bool right = valid(root->right,prev);
        return left && right;
    }
};