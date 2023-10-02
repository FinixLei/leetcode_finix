/*
    Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
    Note that the same word in the dictionary may be reused multiple times in the segmentation.

    Example 1:
        Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
        Output: ["cats and dog","cat sand dog"]
    
    Example 2:
        Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
        Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
        Explanation: Note that you are allowed to reuse a dictionary word.
    
    Example 3:
        Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
        Output: []
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

    private Stack<Node> stack;
    private List<String> allResults;

    private void helper(String s, List<String> wordDict) {
        if (s.length() == 0) {
            if (stack.size() > 0) {
                StringBuilder sb = new StringBuilder();
                
                for (int i=0; i<stack.size(); i++) {
                    if (i < stack.size()-1) {
                        sb.append(stack.get(i).startString);
                        sb.append(" ");
                    }
                    else {
                        sb.append(stack.get(i).startString);
                    }
                }
                allResults.add(sb.toString());
                return;
            }
        }

        for (String word : wordDict) {
            if (s.startsWith(word)) {
                String leftString = s.substring(word.length());
                stack.push(new Node(word, leftString));
                helper(leftString, wordDict);
                stack.pop();
            }
        }
    }

    public List<String> wordBreak(String s, List<String> wordDict) {
        stack = new Stack<>();
        allResults = new ArrayList<>();
        helper(s, wordDict);
        return allResults;
    }
}
