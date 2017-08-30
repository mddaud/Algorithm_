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
    const long long min = -10000000000000;
    const long long max =  10000000000000;
    bool is_bst(TreeNode* root, long long min, long long max) {
        if(root == NULL) return true;
        else if(root -> val > min && root -> val < max) {
            return is_bst(root -> left, min, root -> val)
                                and
                    is_bst(root -> right, root -> val, max);
        }
        else {
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return is_bst(root, min, max);
    }
};
