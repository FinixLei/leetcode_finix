/*
    Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
    Note that the same word in the dictionary may be reused multiple times in the segmentation.

    Example 1:
        Input: s = "leetcode", wordDict = ["leet","code"]
        Output: true
        Explanation: Return true because "leetcode" can be segmented as "leet code".
    
    Example 2:
        Input: s = "applepenapple", wordDict = ["apple","pen"]
        Output: true
        Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
        Note that you are allowed to reuse a dictionary word.
        
    Example 3:
        Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
        Output: false
*/

class Solution {
    class Node {
        String startString;
        String leftString;

        public Node(String s1, String s2) {
            startString = s1;
            leftString = s2;
        }
    }

    private Map<String, Boolean> cache;
    private Stack<Node> stack;

    boolean helper(String s, List<String> wordDict) {
        if (s.length() == 0) return true;
        if (cache.containsKey(s)) return cache.get(s);

        for (String word : wordDict) {
            if (s.startsWith(word)) {
                String leftString = s.substring(word.length());
                stack.push(new Node(word, leftString));

                boolean result = helper(leftString, wordDict);
                if (result) return true;
                else {
                    stack.pop();
                }
            }
        }
        cache.put(s, false);
        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        cache = new HashMap<>();
        stack = new Stack<>();
        return helper(s, wordDict);
    }
}
