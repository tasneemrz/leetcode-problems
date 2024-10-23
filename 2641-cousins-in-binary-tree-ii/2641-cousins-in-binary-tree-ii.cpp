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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == nullptr) return root;

        queue<TreeNode*> q;
        q.push(root);
        int currLevelSum = root->val;

        while(!q.empty()) {
            int nodesRemaining = q.size();
            int nextLevelSum = 0;

            while(nodesRemaining--) {
                TreeNode* currNode = q.front();

                // current nodes values includes its siblings value as well (except if current = root node)
                // subtracting its value from the total sum of current level gives cousins sum
                currNode->val = currLevelSum - currNode->val;

                // calculating current nodes children sums
                int childSum = (currNode->left ? currNode->left->val : 0);
                childSum += (currNode->right ? currNode->right->val : 0);

                // next levels sum will have the sum of this nodes children
                nextLevelSum += childSum;

                // each childs value becomes sum of both child
                // this is to ensure that when we subtract each child nodes value from its level's sum, 
                // then its's sibling's value is also subtracted to get the cousins sum
                if(currNode->left) {
                    currNode->left->val = childSum; 
                    q.push(currNode->left);
                    
                }
                if(currNode->right) {
                    currNode->right->val = childSum; 
                    q.push(currNode->right);
                }

                q.pop();
            }

            // now we move to the next level
            // so the current level will become the next level whose sum we calculated above
            currLevelSum = nextLevelSum;
        }

        return root;
    }
};