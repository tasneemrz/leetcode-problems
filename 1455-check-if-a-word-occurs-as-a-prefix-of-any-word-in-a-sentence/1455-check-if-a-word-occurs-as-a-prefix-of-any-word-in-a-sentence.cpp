class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // extract the words from the input sentence
        istringstream iss(sentence);
        string word;
        
        int word_i = 1;
        
        // compare each word with the given search word
        while(iss >> word) {
            int w_ptr = 0;
            int s_ptr = 0;
            
            while(w_ptr < word.length() && s_ptr < searchWord.length()) {
                if(word[w_ptr] != searchWord[s_ptr]) {
                    break;
                }
                w_ptr++;
                s_ptr++;
            }
            
            // if match found return the index
            if(s_ptr == searchWord.length()) {
                return word_i;
            }
            
            word_i++;
        }
        
        // match not found
        return -1;
    }
};