class Solution {
public:
    int minLength(string s) {
        int writePtr = 0;

        for(int readPtr = 0; readPtr < s.length(); readPtr++) {
            s[writePtr] = s[readPtr];

            if(
                writePtr > 0 && 
                (s[writePtr-1] == 'A' || 
                s[writePtr-1] == 'C') && 
                s[writePtr] == s[writePtr - 1] + 1
            ) {
                writePtr--;
            } else {
                writePtr++;
            }
        }

        return writePtr;
    }
};