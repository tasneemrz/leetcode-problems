class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c : expression) {
            if(c == ')') {
                vector<char> values;

                while(st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();

                st.push(evaluateSubExpr(op, values));
            }
            else if(c != ',') {
                st.push(c);
            }
        }

        return st.top() == 't';
    }

private:
    char evaluateSubExpr(char op, vector<char>& values) {
        if(op == '!') {
            if(values[0] == 't') return 'f';
            else return 't';
        }

        if(op == '&') {
            for(char v : values) {
                if(v == 'f') return 'f'; 
            }
            return 't';
        }

        if(op == '|') {
            for(char v : values) {
                if(v == 't') return 't'; 
            }
            return 'f';
        }

        return 'f';
    }
};