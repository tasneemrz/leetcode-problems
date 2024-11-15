class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int i = 0;
        int j = n-1;
        while (i < n-1) {
            if (arr[i] > arr[i+1]) {
                break;
            }
            i++;
        }
        if (i == j) return 0;

        while (j > 0) {
            if (i > -1 && arr[i] > arr[j]) {
                i--;
            }
            if (arr[j] < arr[j-1]) {
                break;
            }
            j--;
        }

        return j - i - 1;
    }
};