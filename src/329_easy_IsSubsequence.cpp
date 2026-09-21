class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1=0, p2=0;
        while (p1 < s.size()) {
            while (p2 < t.size()) {
                if (s[p1] == t[p2]) break;
                p2 ++;
            }
            if (p2 == t.size()) return false;
            p1 ++;
            p2 ++;
        }
        return p1 == s.size();
    }
};