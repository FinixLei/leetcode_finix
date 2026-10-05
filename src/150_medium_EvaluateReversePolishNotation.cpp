class Solution {
private:
    int convertStringToInt(string& s) {
        if (s == "") return 0;
        long res = 0;
        bool negative = false;
        if (s[0] == '-') negative = true;
        else res = s[0] - '0';
        
        for (int i=1; i<s.size(); i++) {
            res = res * 10 + s[i] - '0';
        }
        return (int)(negative ? -res : res); 
    }

    string convertIntToString(long num) {
        string s;
        if (num < 0) {
            s.push_back('-');
            num = -num;
        }
        vector<char> vec;
        while (num > 0) {
            vec.push_back(num % 10 + '0');
            num /= 10;
        }
        const int size = vec.size();
        int left = 0, right = size-1;
        while (left < right) {
            swap(vec[left++], vec[right--]);
        }
        for (auto& ch : vec) {
            s.push_back(ch);
        }
        return s;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for (string& s : tokens) {
            if (s=="+" || s=="-" || s=="*" || s=="/") {
                string s1 = stk.top();
                stk.pop();
                string s2 = stk.top();
                stk.pop();

                int n1 = convertStringToInt(s1);
                int n2 = convertStringToInt(s2);
                int res = 0;
                if (s == "+") {
                    res = n1 + n2;
                } 
                else if (s == "-") {
                    res = n2 - n1;
                }
                else if (s == "*") {
                    res = n1 * n2;
                }
                else if (s == "/") {
                    res = n2 / n1;
                }
                string tmp = convertIntToString(res);
                stk.push(tmp);
            }
            else {
                stk.push(s);
            }
        }
        string res = stk.top();
        stk.pop();
        return convertStringToInt(res);
    }
};