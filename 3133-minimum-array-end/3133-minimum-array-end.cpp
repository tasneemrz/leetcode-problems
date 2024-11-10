class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = 0, bit;
        --n;
        
        vector<int> binaryX(64, 0);
        vector<int> binaryN(64, 0);
        
        long long longX = x;
        long long longN = n;
        
        for(int i = 0; i < 64; i++) {
            bit = (longX >> i) & 1;
            binaryX[i] = bit;
            
            bit = (longN >> i) & 1;
            binaryN[i] = bit;
        }
        
        int posX = 0, posN = 0;
        
        while(posX < 63) {
            // find a bit that is 0 in x that can be modified, 
            // because we dont want to disturb the bits that are 1
            while(binaryX[posX] != 0 && posX < 63) {
                ++posX;
            }
            
            binaryX[posX] = binaryN[posN];
            ++posX;
            ++posN;
        }
        
        for(int i = 0; i < 64; ++i) {
            if(binaryX[i] == 1) {
                result += pow(2, i);
            }
        }
        
        return result;
    }
};