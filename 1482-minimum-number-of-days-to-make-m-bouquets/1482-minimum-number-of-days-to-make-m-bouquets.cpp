class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((1LL * m * k) > bloomDay.size()) 
            return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(canMakeBouquets(bloomDay, m, k, mid)) 
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
    
private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0;
        int numBouquetsFormed = 0;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                count++;
                if(count == k) {
                    numBouquetsFormed++;
                    count = 0;
                }
            } else {
                count = 0;
            }
            
            if(numBouquetsFormed >= m) 
                return true;
        }
            
        return false;
    }
};