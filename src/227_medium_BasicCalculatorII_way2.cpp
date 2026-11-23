class Solution {
private:
    long get_number(const string& s, int start, int end) {
        long sum = 0;
        for (int i=start; i<end; i++) sum = sum * 10 + s[i] - '0';
        return sum;
    }
public:
    int calculate(string s) {
        string s1 = "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ') s1.push_back(s[i]);
        }
        vector<pair<int, char>> vec;
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/') {
                vec.push_back(make_pair(i, s1[i]));
            }
        }

        unordered_map<char, long> sign_map = { {'+', -1}, {'-', -2}, {'*', -3}, {'/', -4} };
        vector<long> vec_chain;
        int begin = 0;
        for (int i=0; i<vec.size(); i++) {
            int sign_pos = vec[i].first;
            char sign_ch = vec[i].second;
            long number = get_number(s1, begin, sign_pos);
            begin = sign_pos + 1;
            vec_chain.push_back(number);
            vec_chain.push_back(sign_map[sign_ch]);
        }
        int last_number = get_number(s1, begin, s1.size());
        vec_chain.push_back(last_number);

        deque<long> dq;
        int i=0;
        while (i < vec_chain.size()) {
            if (vec_chain[i] == -3 || vec_chain[i] == -4) {
                long tmp = vec_chain[i] == -3 ? (dq.back() * vec_chain[i+1]) : (dq.back() / vec_chain[i+1]);
                dq.pop_back();
                dq.push_back(tmp);
                i += 2;
            }
            else {
                dq.push_back(vec_chain[i]);
                i++;
            }
        }

        long res = 0;
        bool negative = false;
        while(!dq.empty()) {
            if (dq.front() >= 0) res += (negative ? -dq.front() : dq.front());
            else if (dq.front() == -1) negative = false;
            else if (dq.front() == -2) negative = true;
            dq.pop_front();
        }
        return res;
    }
};
