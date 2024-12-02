class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        istringstream iss(sentence);
        string word;
        
        while(iss >> word) {
            words.push_back(word);
        }
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int w_ptr = 0;
            int s_ptr = 0;
            
            while(w_ptr < word.size() && s_ptr < searchWord.size()) {
                if(word[w_ptr] != searchWord[s_ptr]) {
                    break;
                }
                w_ptr++;
                s_ptr++;
            }
            
            if(s_ptr == searchWord.size()) {
                return i + 1;
            }
        }
        
        return -1;
    }
};