class Solution {
private:
    set<int> numCache = {};

public:
    bool isHappy(int n) {
        if (n == 1) return true;
        if (numCache.contains(n)) return false;
        numCache.insert(n);

        int s = 0;
        while (n > 0) {
            int tmp = n % 10;
            s += tmp * tmp;
            n = n / 10;
        }
        return isHappy(s);
    }
};