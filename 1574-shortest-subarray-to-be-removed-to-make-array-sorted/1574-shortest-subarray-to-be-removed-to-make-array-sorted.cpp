class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        
        // iterate the left pointer towards right hand side
        while (left < n - 1) {
            // if next element smaller then break
            if (arr[left] > arr[left + 1]) {
                break;
            }
            left++;
        }
        
        // case : the array is already sorted
        if (left == right) 
            return 0;
        
        // iterate the right pointer from the end towards left hand side
        while (right > 0) {
            // last element of prefix is greater than first element of suffix
            // then decrement left
            if (left > -1 && arr[left] > arr[right]) {
                left--;
            }
            
            // if next element greater then break
            if (arr[right] < arr[right - 1]) {
                break;
            }
            right--;
        }

        return right - left - 1;
    }
};