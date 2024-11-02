class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(int i = 0; i < sentence.length(); i++) 
            if(sentence[i+1] == ' ' && sentence[i+2] != sentence[i])  
                return false;
        
        return sentence[sentence.length()-1] == sentence[0];
    }
};