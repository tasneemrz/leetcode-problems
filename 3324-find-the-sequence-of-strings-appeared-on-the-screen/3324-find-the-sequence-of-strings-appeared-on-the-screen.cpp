class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp = "";

        for (char c : target) {
            // append 'a' to temp; press key 1
            temp += 'a';
            ans.push_back(temp);
            
            // if c is not equal to the target char keep incrementing c; press key 2
            while (c != temp.back()) {
                temp.back() = (temp.back() == 'z') ? 'a' : temp.back()+1;
                ans.push_back(temp);
            }
        }

        return ans;
    }
};