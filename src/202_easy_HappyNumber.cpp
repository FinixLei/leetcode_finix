class Solution {
private:
    set<int> numCache = {};

public:
    bool isHappy(int n) {
        if (n == 1) return true;

        int s = 0;
        while (n >= 10) {
            int tmp = n % 10;
            s += tmp * tmp;
            n = n / 10;
        }
        s += n*n; 

        if (numCache.contains(s)) return false;
        numCache.insert(s);
        return isHappy(s);
    }
};