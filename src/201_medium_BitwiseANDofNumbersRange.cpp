class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        
        int count = 0;
        while (left > 0) {
            left = left >> 1;
            right = right >> 1;
            count ++;
            if (left == right) break;
        }

        if (left == 0) return 0;
        for (int i=0; i<count; i++) {
            left = left << 1;
        }
        return left;
    }
};
