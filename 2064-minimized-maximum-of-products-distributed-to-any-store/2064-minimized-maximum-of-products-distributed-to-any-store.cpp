class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int p = quantities.size();
        
        int low = 1;
        int high = findMax(quantities);
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(canDistributeAll(n, quantities, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
private:
    bool canDistributeAll(int n, vector<int>& quantities, int x) {
        int numProductsDistributed = 0;
        int numShopsLeft = n;
        int p = quantities.size();
            
        for(int i = 0; i < p; i++) {
            int numShopsDistributed = ceil(double(quantities[i]) / double(x));
                
            if(numShopsDistributed <= numShopsLeft) {
                numShopsLeft -= numShopsDistributed;
                numProductsDistributed++;
            }
        }
            
        if(numProductsDistributed == p) {
            return true;
        }
        return false;
    }
    
    int findMax(vector<int>& nums) {
        int maxVal = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
        }
        
        return maxVal;
    }
};