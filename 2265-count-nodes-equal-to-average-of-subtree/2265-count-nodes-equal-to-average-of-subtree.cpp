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
    int dfs(TreeNode* root, int &sum, int &count){
    if(root==NULL){
            sum=0,count=0;
            return 0;
    }
    int sum1 = 0, count1 = 0, sum2 = 0, count2 = 0;
    int ans1 = dfs(root->left, sum1, count1);
    int ans2 = dfs(root->right, sum2, count2);
    int ans = ans1+ans2;
    sum = sum1+sum2+root->val;
    count = count1+count2+1;
    int avg = (sum/(double)count);
    if(avg == root->val)
        ans++;

    return ans;
}
    public:
        int averageOfSubtree(TreeNode* root) {
        int sum, count;
        return dfs(root, sum, count);
        }
}; 