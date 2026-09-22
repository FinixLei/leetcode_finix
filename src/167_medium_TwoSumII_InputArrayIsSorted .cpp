class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size()-1;
        int tmp = 0;
        while(p1 < p2) {
            tmp = numbers[p1] + numbers[p2];
            if (tmp == target) return {p1+1, p2+1};
            if (tmp < target) p1 ++;
            else p2 --;
        }
        return {-1, -1};
    }
};