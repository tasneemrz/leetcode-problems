class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> size_n;
        queue<string> q;

        // Push all start points
        q.push("a");
        q.push("b");
        q.push("c");

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() == n) {
                size_n.push_back(curr);
                continue;
            }

            // Build next 2 strings
            string first = curr;
            string second = curr;

            if (curr.back() == 'a') {
                first.push_back('b');
                second.push_back('c');
            } else if (curr.back() == 'b') {
                first.push_back('a');
                second.push_back('c');
            } else {
                first.push_back('a');
                second.push_back('b');
            }
            
            if (size_n.size() >= k)
                break;
            q.push(first);
            q.push(second);
        }

        if (size_n.size() < k)
            return "";
        return size_n[k - 1];
    }
};