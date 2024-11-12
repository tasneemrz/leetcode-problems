class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size(), 0);
        
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) { 
            return a[0] < b[0]; 
        });
        
        int prefixMaxBeauty = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            prefixMaxBeauty = max(prefixMaxBeauty, items[i][1]);
            items[i][1] = prefixMaxBeauty;
        }
        
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = binarySearch(items, queries[i]);
        }

        return ans;
    }
    
private:
    int binarySearch(vector<vector<int>>& items, int targetPrice) {
        int l = 0;
        int r = items.size() - 1;
        int maxBeauty = 0;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            
            if (items[mid][0] <= targetPrice) {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return maxBeauty;
    }
};