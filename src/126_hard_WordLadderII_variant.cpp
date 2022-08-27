#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
void printVector(vector<T>& vec)
{
    for (auto & v : vec) cout << v << " ";
    cout << endl;
}

template <class T>
void printVector2D(vector<vector<T>> & vec2d)
{
    for (auto & vec : vec2d) printVector(vec);
    cout << endl;
}

unordered_map<string, vector<string>> oneCharDiffMap;
vector<vector<string>> res;
unordered_map<string, vector<string>> parents;
vector<string> path;


// calculate all the words' one-char-diff word list and save the result as cache 
void prepare(const vector<string>& wordList, const string beginWord)
{
    int size = wordList.size();
    if (size == 0) return;
    
    int wordSize = wordList[0].size();
    
    for (int i=0; i<size; i++) {
        vector<string> tmpStrVec;
            
        for (int j=0; j<size; j++) {
            if (i == j) continue;
            
            int diffCount = 0;
            
            for (int k=0; k<wordSize; k++) {
                if (wordList[i][k] != wordList[j][k]) diffCount ++;
                if (diffCount > 1) break;
            }
            
            if (diffCount == 1) {
                tmpStrVec.push_back(wordList[j]);
            }
        }
        
        oneCharDiffMap[wordList[i]] = tmpStrVec; 
    }
    
    vector<string> begWordVec;
    
    for (int j=0; j<size; j++) {
        int diffCount = 0;
        
        for (int k=0; k<wordSize; k++) {
            if (beginWord[k] != wordList[j][k]) {
                diffCount ++;
                if (diffCount > 1) break;
            }
        }
        if (diffCount == 1) {
            begWordVec.push_back(wordList[j]);
        }
    }
    
    oneCharDiffMap[beginWord] = begWordVec;
}

void dfs(string& beginWord, string& currWord) {
    path.push_back(currWord);

    if(currWord == beginWord) {
        res.push_back(path);
        path.pop_back();
        return;
    }

    for(auto& nextWord : parents[currWord]) 
        dfs(beginWord, nextWord);

    path.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    unordered_map<string, int> visited;
    
    prepare(wordList, beginWord);

    int currLevel = 0;
    bool bHit = false; 
    
    queue<string> q;
    q.push(beginWord);

    while(!q.empty() && !bHit) {
        int queueSize = q.size();
        
        // This for loop calculates all the words in current layer, as queueSize has been fixed 
        for(int cnt = 0; cnt < queueSize; cnt++) {
            string currWord = q.front();
            q.pop();
            
            for (string nextWord : oneCharDiffMap[currWord]) {
                // The word has already existed on higher level of the word tree, 
                // so no need to record it in current level, continue 
                if(visited.count(nextWord) && visited[nextWord] < currLevel) continue;

                // Need to record parents for "visited[nextWord] == currLevel" 
                parents[nextWord].push_back(currWord);

                // Push to the queue only when this word never appears, 
                // also no appears in current layer 
                if(!visited.count(nextWord)) {
                    q.push(nextWord);
                    visited[nextWord] = currLevel;
                }
                
                if(nextWord == endWord) bHit = true;
            }
        }

        currLevel++;
    }

    dfs(beginWord, endWord);
    
    for(auto& path : res) reverse(path.begin(), path.end());
    
    return res;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log", "cog"};
    vector<vector<string>> result;
    
    // result = findLadders(beginWord, endWord, wordList);
    // printVector2D(result);
    
    beginWord = "red";
    endWord = "tax";
    wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    result = findLadders(beginWord, endWord, wordList);
    printVector2D(result);
    
    return 0;
}