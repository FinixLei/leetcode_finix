/*
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

    Example 1:
        Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        Output: 5
    Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
    
    Example 2:
        Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        Output: 0
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
     
    Constraints:
        1 <= beginWord.length <= 10
        endWord.length == beginWord.length
        1 <= wordList.length <= 5000
        wordList[i].length == beginWord.length
        beginWord, endWord, and wordList[i] consist of lowercase English letters.
        beginWord != endWord
        All the words in wordList are unique.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, int> visited;
        
        if (wordSet.count(endWord) == 0) return 0;

        int currLevel = 1;
        
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()) {
            int queueSize = q.size();
            
            // This for loop calculates all the words in current layer, as queueSize has been fixed 
            for(int orderPath = 1; orderPath <= queueSize; orderPath++) {
                string currWord = q.front();
                q.pop();

                for(int indexOfDiffrentCharacter = 0; indexOfDiffrentCharacter < currWord.size(); indexOfDiffrentCharacter++) {
                    for(char diffCharacter = 'a'; diffCharacter <= 'z'; diffCharacter++) {
                        string nextWord = currWord;
                        nextWord[indexOfDiffrentCharacter] = diffCharacter;
                        
                        if (nextWord == currWord) continue; 

                        // Invalid word, continue 
                        if(!wordSet.count(nextWord)) continue;
                        
                        // The word has already existed on higher level of the word tree, 
                        // so no need to record it in current level, continue 
                        if(visited.count(nextWord) && visited[nextWord] < currLevel) continue;

                        if(!visited.count(nextWord)) {
                            q.push(nextWord);
                            visited[nextWord] = currLevel;
                        }
                        
                        if(nextWord == endWord) return currLevel+1; 
                    }
                }
            } // end of first for 
            
            currLevel++;
        }
        
        return 0;
    }
};
