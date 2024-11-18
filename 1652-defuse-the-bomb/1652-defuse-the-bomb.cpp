class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        if(k == 0) 
            return ans;
        
        vector<int> codeTemp(n * 3, 0); 
        for(int i = 0; i < (n*3); i++) {
            codeTemp[i] = code[i % n];
        }
        
        int i = 0;
        while (i < n && k > 0) {
            int sum = 0;
            for(int j = 1; j <= k; j++) 
                sum += codeTemp[i + n + j];
            ans[i] = sum;
            i++;
        }
        
        while(i < n && k < 0) {
            int sum = 0;
            for(int j = 1; j <= (-k); j++) 
                sum += codeTemp[i + n - j];
            ans[i] = sum;
            i++;
        }
        
        return ans;
    }
};