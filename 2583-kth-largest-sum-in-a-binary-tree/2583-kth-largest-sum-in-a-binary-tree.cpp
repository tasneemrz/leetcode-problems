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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == nullptr) return -1;

        queue<TreeNode*> q;
        q.push(root);

        vector<long long> allLevelSums; // store sum of each level

        while(!q.empty()) {
            long long currLevelSum = 0; 
            int currLevelNodes = q.size(); 

            // iterate through each node in the current level
            while(currLevelNodes--) {
                TreeNode* node = q.front();
                q.pop();

                currLevelSum += node->val;

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }

            allLevelSums.push_back(currLevelSum);
        }

        if(k > allLevelSums.size()) return -1;

        // sort the sums in ascending order
        sort(allLevelSums.begin(), allLevelSums.end());
        
        return allLevelSums[allLevelSums.size() - k];
    }
};