/**
 Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
**/

#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<string> letterCombinations_way1(string digits) {  // This is my own way
    const vector<vector<char>> collection = {
        { ' ' },                  // 0
        {},                     // 1
        { 'a', 'b', 'c' },        // 2
        { 'd', 'e', 'f' },        // 3
        { 'g', 'h', 'i' },        // 4
        { 'j', 'k', 'l' },        // 5
        { 'm', 'n', 'o' },        // 6
        { 'p', 'q', 'r', 's' },   // 7
        { 't', 'u', 'v' },        // 8
        { 'w', 'x', 'y', 'z' }    // 9
    };
    const int collection_size[] = { 1, 0, 3, 3, 3, 3, 3, 4, 3, 4 };

    const int digits_length = digits.length();
    vector<string> result;

    if (digits_length == 0) {
        // pass
    }
    else if (digits_length == 1) {
        int num = digits[0] - '0';
        for (int i = 0; i<collection_size[num]; ++i) {
            string tmp = "";
            tmp = tmp + collection[num][i];
            result.push_back(tmp);
        }
    }
    else {
        vector<int> stack;  // if digits == "23", then stack = {2, 3}
        stack.reserve(digits_length);
        for (int i = 0; i<digits_length; ++i) {
            stack.push_back(digits[i] - '0');
        }

        vector<int> pos;  // position array changing from {0, 0} to {2-big_size, 3-big_size}
        pos.reserve(digits_length);
        for (int i = 0; i<digits_length; ++i) {
            pos.push_back(0);
        }

        bool flag = true;
        while (flag) {
            string tmp = "";
            for (int i = 0; i<digits_length; ++i) {
                if (collection[stack[i]].size() > 0) {
                    tmp = tmp + collection[stack[i]][pos[i]];
                }
            }
            if (tmp != "") {
                result.push_back(tmp);
            }

            // adjust pos, similar to "carry bit".
            int index = digits_length - 1;
            for (; index >= 0; --index) {
                if (pos[index] < collection_size[stack[index]] - 1) {
                    if (index == digits_length - 1)  {
                        pos[index] ++;
                        break;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (index > 0) {
                        pos[index] = 0;
                        pos[index - 1] ++;

                        if (pos[index - 1] < collection_size[stack[index - 1]]) {
                            break;
                        }
                    }
                    else if (index == 0) {
                        if (pos[index] >= collection_size[stack[index]]) {
                            flag = false;
                        }
                    }
                }
            }
        }

    }

    return result;
}

vector<string> letterCombinations_way2(string digits) {  // this way references to haochen
    char  phone[10][4]={ {' ',  '\0', '\0', '\0' }, //0
                         {'\0', '\0', '\0', '\0' }, //1
                         {'a',  'b',  'c',  '\0' }, //2
                         {'d',  'e',  'f',  '\0' }, //3
                         {'g',  'h',  'i',  '\0' }, //4
                         {'j',  'k',  'l',  '\0' }, //5
                         {'m',  'n',  'o',  '\0' }, //6
                         {'p',  'q',  'r',  's'  }, //7
                         {'t',  'u',  'v',  '\0' }, //8
                         {'w',  'x',  'y',  'z'  }  //9
                       };

    vector<string> result;
    if (digits.size()<=0){
        result.push_back("");
        return result;
    }
    for( int i=0; i<digits.size(); i++ ) {
        if (!isdigit(digits[i])) {
            vector<string> r;
            return r;
        } 
        int d = digits[i] - '0';
        if (result.size()<=0){
            for( int j=0; j<4 && phone[d][j]!='\0'; j++ ){
                string s;
                s += phone[d][j];
                result.push_back(s);
            }
            continue;
        }
        vector<string> r;
        for (int j=0; j<result.size(); j++){
            for( int k=0; k<4 && phone[d][k]!='\0'; k++ ){
                string s = result[j] + phone[d][k];
                //sort(s.begin(), s.end());
                r.push_back(s); 
            }
        }
        result = r;
    }
    //sort(result.begin(), result.end());

    return result; 
}

int main()
{
    string str = "234"; 
    vector<string> result = letterCombinations_way1(str);
    
    for (auto s : result) {
        cout << s << endl;
    }
    cout << "-------------------------------------\n";
    
    result = letterCombinations_way2("432");
    
    for (auto s : result) {
        cout << s << endl;
    }
    
    return 0;
}
