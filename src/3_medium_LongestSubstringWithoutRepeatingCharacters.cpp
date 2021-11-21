/*
    Given a string, find the length of the longest substring without repeating characters. 
    For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
    For "bbbbb" the longest substring is "b", with the length of 1.
*/


#include <cstring>
#include <string>
#include <iostream>
using namespace std;


int lengthOfLongestSubstring(string s) {
    const int bitmap_size = 256;
    int bitmap[bitmap_size]; 
    int longest = 0;
    int last_hit = -1;
    
    memset(bitmap, -1, bitmap_size * sizeof(int));
    
    for (int i=0; i<s.size(); i++) {
        // "abba", last_hit=1 but bitmap['a']=0, 1>0, so cannot assign bitmap['a'] to last_hit. 
        // 下面其实是判断是否真的有重复数字出现。有重复数字出现需满足2个条件：
        // 1. 位图中，该字符对应的值已经不是初始值
        // 2. 上一次重复位置，在当前字符对应的位图值之前； 这是因为，上一次重复位置之后的位置，就是这一次计算的起始位置
        // 当满足这2个条件时，即相当于发现了最新的重复字符，于是更新最新重复位置，并计算是否为最长无重复字符串
        // 无论是否找到重复字符，都需要更新一下最长无重复字符串长度，以及更新当前字符的位图值。
        if (bitmap[s[i]] != -1 && last_hit < bitmap[s[i]]) {  
            last_hit = bitmap[s[i]]; 
        } 
        longest = (i - last_hit > longest) ? i - last_hit : longest;
        bitmap[s[i]] = i;
    }
    
    return longest;
}

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    
    string s3 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCD";
    
    string s4 = "abba";
    string s5 = "aab"; 
    
    /*cout << "s1's length is " << lengthOfLongestSubstring(s1) << endl;
    cout << "s2's length is " << lengthOfLongestSubstring(s2) << endl;
    cout << "s3's length is " << lengthOfLongestSubstring(s3) << endl;*/
    cout << "s4's length is " << lengthOfLongestSubstring(s4) << endl;
    // cout << "s5's length is " << lengthOfLongestSubstring(s5) << endl;
    
    return 0;
}
