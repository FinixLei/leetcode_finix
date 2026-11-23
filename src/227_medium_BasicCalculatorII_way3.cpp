class Solution {
public:
    int calculate(string s) {
        vector<long> st;
        long num = 0;
        char op = '+';  // last operation
        for (int i=0; i<s.size(); i++) {
            char ch = s[i];
            bool is_digit = (ch >= '0' && ch <='9');
            if (is_digit) num = num * 10 + ch - '0';
            if ((!is_digit && ch!=' ') || i == s.size()-1) {
                if (op == '+') st.push_back(num);
                else if (op == '-') st.push_back(-num);
                else if (op == '*') st.back() *= num;
                else if (op == '/') st.back() /= num;
                op = ch;
                num = 0;
            }
        }
        return accumulate(st.begin(), st.end(), 0L);
    }
};

