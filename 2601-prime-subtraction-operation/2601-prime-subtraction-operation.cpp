class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        
        int maxNumber = *max_element(nums.begin(), nums.end());
        
        vector<int> previousPrime(maxNumber+1, 0);
        for(int i = 2; i <= maxNumber; i++) {
            if(checkPrime(i)) 
                previousPrime[i] = i;
            else 
                previousPrime[i] = previousPrime[i-1];
        }
 
        for(int i = 0; i < nums.size(); i++) {
            int bound;

            if(i == 0) {
                bound = nums[0];
            } else {
                bound = nums[i] - nums[i-1];
            }

            if(bound <= 0) {
                return false;
            }

            int largestPrime = previousPrime[bound-1];
            nums[i] = nums[i] - largestPrime;
        }

        return true;
    }

private: 
    bool checkPrime(int n) {
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) 
                return false;
        }
        return true;
    }
};