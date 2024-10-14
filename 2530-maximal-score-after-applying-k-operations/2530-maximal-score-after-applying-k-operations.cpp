class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long score = 0;

        for(int num : nums) {
            pq.push(num);
        }

        while(k--) {
            int maxEle = pq.top();
            score += maxEle;
            pq.pop();

            int newEle = maxEle / 3;
            if (maxEle % 3 != 0) {
                newEle += 1; 
            }

            pq.push(newEle);
        }

        return score;
    }
};