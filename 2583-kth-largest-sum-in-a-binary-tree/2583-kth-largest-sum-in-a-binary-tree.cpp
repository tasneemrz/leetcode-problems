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

 // we need to return the kth largest sum of the levels
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == nullptr) return -1;

        queue<TreeNode*> q;
        q.push(root);

        vector<long long> allLevelSums; // store sum of each level
        long long levelSum = 0; // keep track of the sum for the current level
        int currLevelNodes = q.size(); // keep track of the number of nodes in the current level

        while(!q.empty()) {
            // if current level nodes become 0; all nodes of this level have been traversed
            if(currLevelNodes == 0) {
                allLevelSums.push_back(levelSum);
                levelSum = 0; // reset to calculate next levels sum
                currLevelNodes = q.size(); // next levels number of nodes is equal to size of queue
            }

            TreeNode* node = q.front();
            levelSum += node->val;

            q.pop();
            currLevelNodes--;

            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        allLevelSums.push_back(levelSum); // add the last levels sum

        // sort the sums in ascending order
        sort(allLevelSums.begin(), allLevelSums.end());

        int kLargestSum_i = allLevelSums.size() - k;

        if(kLargestSum_i < 0) 
            return -1;
        return allLevelSums[kLargestSum_i];
    }
};