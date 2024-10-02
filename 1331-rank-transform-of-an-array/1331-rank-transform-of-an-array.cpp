class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        if(n == 0) return {};

        vector<int> arrCopy = arr;
        unordered_map<int, int> arrRank;

        sort(arrCopy.begin(), arrCopy.end());
        
        arrRank[arrCopy[0]] = 1;
        int rank = 1;
        for(int i = 1; i < n; i++) {
            if(arrCopy[i] != arrCopy[i - 1]) {
                rank++;
            }
            arrRank[arrCopy[i]] = rank;
        }

        for(int i = 0; i < n; i++) {
            arr[i] = arrRank[arr[i]];
        }

        return arr;
    }
};