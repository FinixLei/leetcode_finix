/*
    Given two strings s and t, return the minimum window in s which will contain all the characters in t. 
    If there is no such window in s that covers all characters in t, return the empty string "".

    Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

    Example 1:
        Input: s = "ADOBECODEBANC", t = "ABC"
        Output: "BANC"
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

string minWindow(string& s, string& t)
{
    int s_size = s.size();
    int t_size = t.size();

    if (s_size < t_size) return "";

    int min_len = INT_MAX;
    string result = "";

    unordered_map<char, int> char_map;
    for (auto ch : t) char_map[ch] += 1;  // If not found, insert default value as 0

    unordered_map<char, int> tmp_map = char_map;

    int beg=0, end=0;
    int min_beg = -1, min_end = -1;

    while (beg == end &&  end < s_size && char_map.count(s[beg]) == 0) {
        ++ beg;
        ++ end;
    }

    if (end >= s_size) return result;

    if (tmp_map.count(s[beg])) {
        -- tmp_map[s[beg]];
        if (tmp_map[s[beg]] == 0) tmp_map.erase(s[beg]);
    }

    // Fix beg, expand end, to find out the first result 
    while (!tmp_map.empty() && end < s_size) {
        ++ end;
        while (end < s_size && tmp_map.count(s[end]) == 0) ++ end; 

        if (end < s_size) {
            -- tmp_map[s[end]];
            if (tmp_map[s[end]] <= 0) tmp_map.erase(s[end]);
        }
        else {
            return result;
        }
    }

    // Figure out the first result (先找出一个结果)
    int len = end - beg + 1;
    if (len < min_len) {
        min_len = len;
        min_beg = beg; 
        min_end = end; 
        if (min_len == t_size) goto exit;
    }
    
    tmp_map = {};
    for (int i=beg; i<=end; i++) {
        if (char_map.find(s[i]) != char_map.end()) {
            tmp_map[s[i]] += 1;
        }
    }
    
    do {
        // Fix end, expand beg, to find out a shorter result; 
        // 固定右边，看左边能否右移，以缩短长度

        // Can increase beg 
        while (char_map.count(s[beg]) == 0 || (tmp_map.count(s[beg]) && tmp_map[s[beg]] > char_map[s[beg]])) {
            if (char_map.count(s[beg])) -- tmp_map[s[beg]];
            ++ beg;
        }

        len = end - beg + 1;
        if (len < min_len) {
            min_len = len;
            min_beg = beg; 
            min_end = end;
            if (min_len == t_size) goto exit;
        }

        // Expand beg by 1, then expand end 
        // 左边右移一个，这样就不是完整字串，所以需要右移右边游标，以再次达到完整字串

        char lack = s[beg]; 
        -- tmp_map[s[beg]];
        ++ beg;
        ++ end;

        while (end < s_size) {
            if (char_map.count(s[end])) ++ tmp_map[s[end]];
            if (s[end] == lack) break; // find another result 
            ++ end;
        }

        len = end - beg + 1;
        if (len < min_len) {
            min_len = len;
            min_beg = beg; 
            min_end = end; 
            if (min_len == t_size) goto exit;
        }

    } while (end < s_size);

exit: 
    result = "";
    for (int i=min_beg; i<=min_end; i++) result.push_back(s[i]);
    return result;
}

void test(string s, string t) 
{
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    string result = minWindow(s, t);
    cout << "result: " << result << endl;
    cout << "-----------------------------\n";
}

int main()
{
    test("ADOBECODEBANC", "ABC");   // BANC 
    test("a", "aa");                // empty 
    test("aa", "aa");               // aa
    test("aBbaBBBBA", "BBA");       // BBA 
    test("acb", "ab");              // acb 
    
    return 0;
}
