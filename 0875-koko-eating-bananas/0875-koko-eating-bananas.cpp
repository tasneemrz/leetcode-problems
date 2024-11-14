class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high+1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(totalHrsTaken(piles, mid) <= h) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
private:
    long long totalHrsTaken(vector<int>& piles, int hourly) {
        long long totalHrs = 0;
        
        for(int i = 0; i < piles.size(); i++) {
            totalHrs += (piles[i] + hourly - 1) / hourly;
        }
        
        return totalHrs;
    }
};