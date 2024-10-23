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
        map<TreeNode*, int> siblingVal;

        siblingVal[root] = 0;
        q.push(root);

        while(!q.empty()) {
            int nodesRemaining = q.size();
            int currLevelSum = 0;
            vector<TreeNode*> currLevelNodes;

            while(nodesRemaining--) {
                TreeNode* currNode = q.front();
                currLevelNodes.push_back(currNode);
                currLevelSum += currNode->val;

                if(currNode->left != nullptr) {
                    q.push(currNode->left);
                    siblingVal[currNode->left] = (currNode->right) ? currNode->right->val : 0;
                }
                if(currNode->right != nullptr) {
                    q.push(currNode->right);
                    siblingVal[currNode->right] = (currNode->left) ? currNode->left->val : 0;
                }

                q.pop();
            }

            for(auto node : currLevelNodes) {
                node->val = currLevelSum - (node->val + siblingVal[node]); 
            }
        }

        return root;
    }
};