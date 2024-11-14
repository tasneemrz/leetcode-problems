class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        
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
};