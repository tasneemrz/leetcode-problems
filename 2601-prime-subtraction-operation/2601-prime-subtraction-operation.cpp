class Solution {
public:
    static vector<int> previousPrime;
    
    bool primeSubOperation(vector<int>& nums) {
        if (previousPrime.empty()) {
            computePreviousPrimes(1000);
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
    static void computePreviousPrimes(int maxLimit) {
        previousPrime.resize(maxLimit+1, 0);
        
        for (int i = 2; i <= maxLimit; i++) {
            if (checkPrime(i)) 
                previousPrime[i] = i;
            else 
                previousPrime[i] = previousPrime[i-1];
        }
    }
    
    static bool checkPrime(int n) {
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) 
                return false;
        }
        return true;
    }
};

vector<int> Solution::previousPrime;