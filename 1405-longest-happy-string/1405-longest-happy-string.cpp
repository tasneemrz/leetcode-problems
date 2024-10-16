class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string ans = "";

        while(!pq.empty()) {
            auto [count1, char1] = pq.top();
            pq.pop();

            if(!ans.empty() && char1 == ans.back()) {
                if(pq.empty()) break;

                auto [count2, char2] = pq.top();
                pq.pop();

                ans.push_back(char2);
                count2--;

                if(count2 > 0) pq.push({count2, char2});
                pq.push({count1, char1});
            } 
            else {
                int add = min(2, count1);
                ans.append(add, char1);
                count1 -= add;

                if(count1 > 0) pq.push({count1, char1});
            }
        }

        return ans;
    }
};