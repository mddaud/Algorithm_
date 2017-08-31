/**
  Maximum Path Sum Between Any two node in Binary tree
  
  https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/
  
  http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
 */
 
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int futil(TreeNode* root, int &ans) {
        if(root == NULL) return 0;
        int left = futil(root -> left, ans);
        int right = futil(root -> right, ans);
        
        int M1 = max(max(left, right) + root -> val, root -> val);
        int M2 = max(M1, left + right + root -> val);
        ans = max(ans, M2);
        return M1;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        futil(root, ans);
        return ans;
    }
};
