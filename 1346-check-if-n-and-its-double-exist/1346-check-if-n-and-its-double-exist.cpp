class Solution {
    int findDouble (vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
    
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++) {
            int target = arr[i] * 2;
            int doubleIndex = findDouble(arr, target);
            
            if (doubleIndex >= 0 && doubleIndex != i)
                return true;
        }
        
        return false;
    }
};