class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freqArr(n + 1, 0);
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            freqArr[A[i]]++;
            freqArr[B[i]]++;

            int count = 0; 
            for(int j = 0; j < n + 1; j++) {
                if(freqArr[j] == 2)
                    count++;
            }

            ans[i] = count;
        }

        return ans;
    }
};