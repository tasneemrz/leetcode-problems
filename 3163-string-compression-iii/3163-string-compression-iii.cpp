class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;

        while (i < word.size()) {
            char currChar = word[i];
            int count = 0;

            while (i < word.size() && word[i] == currChar && count < 9) {
                ++count;
                ++i;
            }
            
            comp += count+'0';
            comp += currChar;
        }

        return comp;
    }
};