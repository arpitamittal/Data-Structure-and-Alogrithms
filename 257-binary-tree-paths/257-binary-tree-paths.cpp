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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        paths(root,"",answer);
        return answer;
    }
    void paths(TreeNode* root,string current,vector<string> &answer)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            current += to_string(root->val);
            answer.push_back(current);
            return;
        }
        current += to_string(root->val) + "->";
        if(root->left) paths(root->left, current, answer);
        if(root->right) paths(root->right, current, answer);
        return;
    }
};