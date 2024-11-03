class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size()) return false;
        if(n == 0) return true;
        
        for(int i = 0; i < n; i++){
            int j = 0;
            while(j < n && s[(i+j) % n] == goal[j]){
                j++;
            }
            if(j == n){
                return true;
            }
        }

        return false;
    }
};