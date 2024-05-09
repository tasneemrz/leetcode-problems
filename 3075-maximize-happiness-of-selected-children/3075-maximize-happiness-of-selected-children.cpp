class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sort(happiness.rbegin(), happiness.rend());
        
        priority_queue<int> pq;

        for(const auto& h : happiness) {
            pq.push(h);
        }

        long long ans = 0;

        for(int i = 0; i < k; i++) {
            ans += max(pq.top() - i, 0);
            pq.pop();
        }

        return ans;
    }
};