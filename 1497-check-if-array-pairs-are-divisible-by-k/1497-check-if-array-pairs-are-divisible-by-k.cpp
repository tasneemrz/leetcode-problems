class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end(), [k](int a, int b) { 
            return ((a % k + k) % k) < ((b % k + k) % k);
        });

        int i = 0, j = arr.size()-1;

        while(i < j) {
            if(arr[i] % k != 0) break;

            if(arr[i + 1] % k != 0) return false;

            i+=2;
        }

        while(i < j) {
            if((arr[i] + arr[j]) % k != 0) return false;
            i++;
            j--;
        }

        return true;
    }
};