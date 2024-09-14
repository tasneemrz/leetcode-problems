class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i = 0; i <= n; i++) {
            int count_1 = 0;
            int num = i;

            while(num > 0) {
                if(num % 2 != 0) {
                    count_1++;  // if odd (last bit 1) increment count of 1 
                }
                num = num >> 1; // right shift by 1
            }

            ans[i] = count_1;
        }

        return ans;
    }
};