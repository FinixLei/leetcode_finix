// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// 
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// 
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
// 
// Example 1:
// Input: n = 3, k = 3
// Output: "213"
//
// Example 2:
// Input: n = 4, k = 9
// Output: "2314"
//
// Example 3:
// Input: n = 3, k = 1
// Output: "123"

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
void print_vec(vector<T>& vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

template <typename T>
void print_list(const list<T>& mylist) {
    for (auto v : mylist) {
        cout << v << " ";
    }
    cout << endl;
}

// Move the x-th item to the head
void move_x_to_head(list<int>& mylist, int x) {
    if (x <= 1 || x > mylist.size()) return;
    
    auto it = mylist.begin();
    int count = 1;
    while (it != mylist.end()) {
        if (x == count) break; 
        count ++;
        it ++;
    }
    
    if (it != mylist.end()) {
        int tmp = *it; 
        mylist.erase(it);
        mylist.push_front(tmp);
    }
}

pair<int, int> get_left_right(const vector<unsigned int>& vec, int n, int k)
{
    int left = 0, right = n;
    
    for (int i=1; i<=n; i++) {
        if (vec[i] < k) {
            left = i;
        }
        else if (vec[i] == k) {
            left = right = i;
            break;
        }
        else { // vec[i] > k 
            right = i;
            break;
        }
    }

    return make_pair(left, right);
}

string getPermutation(int n, int k) 
{
    bool bPrint = false;
    
    if ( n <= 0 || k <= 0 ) return "";
    if ( n == 1 ) {
        if ( k == 1 ) return "1";
        else return "";
    }
    
    string result = "";
    
    // Generate vector for 1!, 2!, ..., n! 
    vector<unsigned int> vec; 
    vec.reserve(n+1);
    vec.push_back(1);  // vec[0] is 0!
    for (int i=1; i<=n; i++) {
        vec.push_back(vec[i-1] * i);
    }
    
    if (bPrint) print_vec(vec);
    
    // k cannot be greater than n! 
    if ( k > vec[n]) return result;
    
    list<int> number_list;
    for (int i=1; i<=n; i++) {
        number_list.push_back(i);
    }
    
    int cn = n;  // cn - current n 
    int d=0, t=0, m=0, certain_numbers=0;  // d - distance, t - times, m - mod 
    
    while ( k > 1 ) {
        pair<int, int> left_right = get_left_right(vec, cn, k);
        int left   = left_right.first;
        int right  = left_right.second;
        
        d = cn - left;
        certain_numbers = d - 1;
        
        t = k / vec[left]; 
        m = k % vec[left];
        k = m;
        cn = left; 
        
        // Logic Part 
        
        if (d == 0) break;  // d为0，代表就是最后一种可能，即全反序打印
        
        if (left == right) {
            certain_numbers = d;
        }
        
        // Generate d-1 positions 
        if (certain_numbers > 0) {
            for (int i=0; i<certain_numbers; i++) {
                result.push_back('0' + number_list.front());
                number_list.pop_front();
            }
            if (left == right) break;
        }
        
        // Generate 1 position according to t and k
        // 是几倍，就将第一个位置之后的第几个位置的数字挪到头部； 但如果k是0，则少挪一位。
        move_x_to_head(number_list, (k > 0 ? t+1 : t));
        result.push_back('0' + number_list.front());
        number_list.pop_front();
    }
    
    // k==1 代表按当前顺序打印
    // k==0, 代表之前少挪了一位，所以剩下的数字按最后一种可能打印，即全反序打印
    while (!number_list.empty()) {
        result.push_back('0' + ( (k==1) ? (number_list.front()) : (number_list.back())));
        if (k==1) number_list.pop_front();
        else number_list.pop_back();
    }
    
    return result;
}


int main()
{
    int n = 3, k = 3;
    string result = getPermutation(n, k);
    cout << "n: " << n << ", k: " << k << endl;
    cout << "result = " << result << "\n\n";    // 213
    
    n = 4; k = 9;
    result = getPermutation(n, k);
    cout << "n: " << n << ", k: " << k << endl;
    cout << "result = " << result << "\n\n";    // 2314
    
    n = 4; k = 4;
    result = getPermutation(n, k);
    cout << "n: " << n << ", k: " << k << endl;
    cout << "result = " << result << "\n\n";    // 1342
    
    n = 2; k = 2;
    result = getPermutation(n, k);
    cout << "n: " << n << ", k: " << k << endl;
    cout << "result = " << result << "\n\n";    // 21
    
    n = 3; k = 2;
    result = getPermutation(n, k);
    cout << "n: " << n << ", k: " << k << endl;
    cout << "result = " << result << "\n\n";    // 132
    
    n = 3; k = 4;
    result = getPermutation(n, k);
    cout << "n: " << n << ", k: " << k << endl;
    cout << "result = " << result << "\n\n";    // 231
    
    n = 3; k = 5;
    result = getPermutation(n, k);
    cout << "n: " << n << ", k: " << k << endl;
    cout << "result = " << result << "\n\n";    // 312
    
    return 0;
}
