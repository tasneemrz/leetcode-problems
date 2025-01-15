class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);

        int res = 0;
        for(int i = 31; i >= 0 && setBits; i--) {
            if(num1 & (1<<i)) {
                setBits--;
                res += (1<<i);
            }
        }

        for(int i = 0; i < 32 && setBits; i++) {
            if((num1 & (1<<i)) == 0) {
                setBits--;
                res += (1<<i);
            }
        }

        return res;
    }
};