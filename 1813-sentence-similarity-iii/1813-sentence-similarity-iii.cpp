class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2) return true; 

        istringstream iss1(sentence1);
        vector<string> s1_words((istream_iterator<string>(iss1)), istream_iterator<string>());

        istringstream iss2(sentence2);
        vector<string> s2_words((istream_iterator<string>(iss2)), istream_iterator<string>());

        vector<string> commonWords;

        // find longest common prefix
        int start = 0;
        while(start < s1_words.size() && start < s2_words.size()) {
            if(s1_words[start] != s2_words[start]) {
                break;
            }
            commonWords.push_back(s1_words[start]);
            start++;
        }
        start--;

        // find longest common suffix
        int end1 = s1_words.size()-1, end2 = s2_words.size()-1;
        while(end1 >= 0 && end2 >= 0 && start < end1 && start < end2) {
            if(s1_words[end1] != s2_words[end2]) {
                break;
            }
            commonWords.push_back(s1_words[end1]);
            end1--;
            end2--;
        }

        return commonWords.size() == s1_words.size() || commonWords.size() == s2_words.size();
    }
};