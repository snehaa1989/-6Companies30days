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
    vector<int>ans;
    void pp(TreeNode*toot){
        if(!toot){
            return;
        }
        ans.push_back(toot->val);
        pp(toot->right);
        pp(toot->left);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       pp(root1);
       pp(root2);
       sort(ans.begin(),ans.end());
       return ans; 
    }
};