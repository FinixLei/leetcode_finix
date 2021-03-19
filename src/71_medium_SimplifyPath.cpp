/*
    Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

    In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

    The canonical path should have the following format:

    The path starts with a single slash '/'.
    Any two directories are separated by a single slash '/'.
    The path does not end with a trailing '/'.
    The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
    Return the simplified canonical path.
*/

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;


string simplifyPath(string& path) 
{
    deque<string> mydeque;
    stack<string> mystack; 
    stringstream ss;
    string tmp = "";
    
    for (int i=1; i<path.size(); i++) {
        if (path[i] == '/') {
            tmp = ss.str();
            if (tmp.size() > 0) {
                mystack.push(std::move(tmp));
            }
            ss.str("");  // clear ss 
        }
        else {
            ss << path[i]; 
        }
    }
    
    tmp = ss.str();
    if (tmp.size() > 0) {
        mystack.push(std::move(tmp));
        ss.str("");
    }
    
    int record_pp = 0;
    
    while (!mystack.empty()) {
        tmp = mystack.top();
        
        if (tmp == "..") {
            record_pp ++;
        }
        else if (tmp == ".") {
            // Do nothing 
        }
        else {
            if (record_pp > 0) {
                record_pp --;
            }
            else {
                mydeque.push_back(tmp);
            }
        }
        
        mystack.pop(); // always pop() 
    }
    
    if (mydeque.empty()) return "/";
    
    while (!mydeque.empty()) {
        ss << "/";
        ss << mydeque.back(); 
        mydeque.pop_back();        
    }
    
    return ss.str(); 
}


int main()
{
    string path = "", result = "";
    
    path = string("/a/./b/../../c/");
    result = simplifyPath(path);
    cout << "path:   " << path << endl;
    cout << "result: " << result << endl << endl;
    
    path = string("/home//foo/");
    result = simplifyPath(path);
    cout << "path:   " << path << endl;
    cout << "result: " << result << endl << endl;
    
    path = string("/../");
    result = simplifyPath(path);
    cout << "path:   " << path << endl;
    cout << "result: " << result << endl << endl;
    
    return 0;
}
