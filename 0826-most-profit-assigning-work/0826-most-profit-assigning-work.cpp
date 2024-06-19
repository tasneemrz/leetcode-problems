class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int totalMaxProfit = 0;
        
        for(int i = 0; i < worker.size(); i++) {
            int maxProfitWorker = 0;

            for(int j = 0; j < difficulty.size(); j++) {
                if(worker[i] >= difficulty[j]) {
                    maxProfitWorker = max(maxProfitWorker, profit[j]);
                }
            }

            totalMaxProfit += maxProfitWorker;
        }

        return totalMaxProfit;
    }
};