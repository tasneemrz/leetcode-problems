class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freqMap;

        for(char c : s) {
            freqMap[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for(auto& [ch, count] : freqMap) {
            maxHeap.push({count, ch});
        }

        string result = "";

        while(!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result += string(count, ch);
        }

        return result;
    }
};