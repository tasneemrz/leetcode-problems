class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;

        for(int i = 0; i < s.length()-1; i++) {
            int a = s[i];
            int b = s[i+1];

            if (a > b){
                score += a-b;
            }
            else{
                score += b-a;
            }
        }

        return score;
    }
};