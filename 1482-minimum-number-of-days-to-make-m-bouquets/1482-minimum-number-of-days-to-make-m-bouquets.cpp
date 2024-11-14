class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((1LL * m * k) > bloomDay.size()) 
            return -1;
        
        int low = findMin(bloomDay);
        int high = findMax(bloomDay);
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(numBouquets(bloomDay, m, k, mid) < m) 
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
    
private:
    int numBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0;
        int numBouquetsFormed = 0;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                count++;
            } else {
                numBouquetsFormed += (count / k);
                count = 0;
            }
        }
        numBouquetsFormed += (count / k);
            
        return numBouquetsFormed;
    }
    
    int findMin(vector<int>& bloomDay) {
        int minVal = INT_MAX;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            minVal = min(minVal, bloomDay[i]);
        }
        
        return minVal;
    }
    
    int findMax(vector<int>& bloomDay) {
        int maxVal = INT_MIN;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            maxVal = max(maxVal, bloomDay[i]);
        }
        
        return maxVal;
    }
};