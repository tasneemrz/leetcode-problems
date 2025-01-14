class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freqArr(n + 1, 0);
        vector<int> ans(n, 0);
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            freqArr[A[i]]++;
            if(freqArr[A[i]] == 2) count++;
            
            freqArr[B[i]]++;
            if(freqArr[B[i]] == 2) count++;

            ans[i] = count;
        }

        return ans;
    }
};