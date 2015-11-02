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
        if (bitmap[s[i]] != -1 && last_hit < bitmap[s[i]]) {  // "abba", last_hit=1 but bitmap['a']=0, 1>0, so cannot assign bitmap['a'] to last_hit. 
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
