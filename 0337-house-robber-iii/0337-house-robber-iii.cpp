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
struct Rob
{
    int withRobbery;
    int withoutRobbery;
    Rob(){
        withRobbery=0;
        withoutRobbery=0;
    }
};
class Solution {
public:
      
int rob(TreeNode* root) {
        Rob result=fun(root);
    return max(result.withRobbery,result.withoutRobbery); 
    }
    Rob fun(TreeNode* root)
    {
      if(!root)
          return Rob();
        Rob left=fun(root->left);
        Rob right=fun(root->right);
        
      Rob ans=Rob();
        ans.withRobbery=root->val;
        ans.withRobbery+=(left.withoutRobbery+right.withoutRobbery);

           ans.withoutRobbery=0;
          ans.withoutRobbery+=max(left.withoutRobbery,left.withRobbery)+max(right.withoutRobbery,right.withRobbery);
        return ans;
     
    }
};