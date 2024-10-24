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

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        findCanonicalForm(root1);
        findCanonicalForm(root2);

        return areEquivalent(root1, root2);
    }

    void findCanonicalForm(TreeNode* root) {
        if(!root) return;

        findCanonicalForm(root->left);
        findCanonicalForm(root->right);

        // if right is null; then either left null or left has a node; canonical form
        if(!root->right) return;

        // if left null; then flip left and right to make in canonical form
        if(!root->left) {
            root->left = root->right;
            root->right = nullptr;
            return;
        }

        // if both left and right not null; 
        // then left val should be greater than right val to be canonical
        if(root->left->val > root->right->val) {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }

    bool areEquivalent(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true; 
        if(!root1 || !root2) return false; 
        if(root1->val != root2->val) return false; 

        return areEquivalent(root1->left, root2->left) && areEquivalent(root1->right, root2->right);
    }
};