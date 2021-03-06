/*
    Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

    You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

    Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

    For the last line of text, it should be left justified and no extra space is inserted between words.

    Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.
     

    Example 1:

    Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
    Output:
    [
       "This    is    an",
       "example  of text",
       "justification.  "
    ]
    Example 2:

    Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
    Output:
    [
      "What   must   be",
      "acknowledgment  ",
      "shall be        "
    ]
    Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
    Note that the second line is also left-justified becase it contains only one word.
    Example 3:

    Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
    Output:
    [
      "Science  is  what we",
      "understand      well",
      "enough to explain to",
      "a  computer.  Art is",
      "everything  else  we",
      "do                  "
    ]
*/

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


void print_string_vec(vector<string>& vec)
{
    cout << "------------------------------\n";
    for (auto str : vec) {
        cout << str << endl;
    }
    cout << endl;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    vector<string> result; 
    
    int size  = words.size();
    int index = 0;
    int pos   = index; 
    
    while (pos < size) {
        int sum = 0;         // words + one space/word for one line 
        int chars = 0;       // one line of chars without spaces 
        
        // 1. Determine how many words should be in this line
        while ( pos < size ) {
            if (sum + words[pos].size() > maxWidth) {
                break;
            }
            else if (sum + words[pos].size() < maxWidth) {
                sum += words[pos].size();
                sum ++;  // add one space per word 
            }
            else {  // cannot add one space for the last word 
                sum += words[pos].size();
            }
            
            chars += words[pos++].size();
        }
        
        int words_count  = pos - index;
        int total_spaces = maxWidth - chars;
        stringstream ss; 
        
        if (words_count == 1) {  // one line has one word 
            string last_spaces(total_spaces, ' ');
            ss << words[index] << last_spaces; 
            result.push_back(ss.str());
        }
        else {  // 2. Check if spaces can be evenly assigned 
            if (pos < size) {  
                int space_sections = words_count - 1;
                int x2 = total_spaces / space_sections;
                int x1 = (total_spaces % space_sections ? (x2+1) : x2);
                
                /*
                    假设有 total_spaces 个空格，要分配到 space_sections 个段中，每段只能是 x1 个空格或 x2 个空格；
                    其中， x1 = x2 + 1； 
                    假设每段存 x1 个空格的有 n1 段，每段存 x2 个空格的有 n2 段， 
                    问： n1 和 n2 分别是多少？ 
                    数学求解：
                        x2*n2 + (x2+1) * (space_sections - n2) = total_spaces
                        即： 
                        x2*n2 + (x2+1) * space_sections - x2*n2 - n2 = total_spaces 
                        即： 
                        n2 = (x2+1)* space_sections - total_spaces
                        即： 
                        n2 = x1 * space_sections - total_spaces
                        
                    对于本题，存在 x1 == x2 的情况，在这种情况下， n2 的数值也是正确的，而n1为0. 
                */
                
                int n2 = x1 * space_sections - total_spaces; 
                int n1 = space_sections - n2; 
                
                string spaces_sec1(x1, ' ');
                string spaces_sec2(x2, ' ');
                
                for (int i=index; i<pos; i++) {
                    ss << words[i]; 
                    if (i != pos-1) {  // when not the last word of the line, output spaces 
                        ss << ( i-index < n1 ? spaces_sec1 : spaces_sec2 ); 
                    }
                }
                result.push_back(ss.str());
            }
            else if (pos == size) { // Last Line 
                int n1 = words_count - 1;
                int n2 = total_spaces - n1; 
                string last_spaces(n2, ' ');
                
                for (int i=index; i<pos; i++) {
                    ss << words[i];
                    if (i < pos-1) ss << " ";
                }
                ss << last_spaces; 
                result.push_back(ss.str());
            }
        }
        
        index = pos;
    }
    
    return result; 
}


int main()
{
    vector<string> string_vec{"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = fullJustify(string_vec, maxWidth);
    print_string_vec(result);
    
    string_vec = {"What","must","be","acknowledgment","shall","be"};
    maxWidth = 16;
    result = fullJustify(string_vec, maxWidth);
    print_string_vec(result);
    
    string_vec = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}; 
    maxWidth = 20;
    result = fullJustify(string_vec, maxWidth);
    print_string_vec(result);
    
    string_vec = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    maxWidth = 16;
    result = fullJustify(string_vec, maxWidth);
    print_string_vec(result);
    
    return 0;
}