struct TrieNode {
    TrieNode* children[26];
    string word; // 到这个节点就代表该单词结束，存完整单词
    TrieNode() {
        memset(children, 0, sizeof(children));
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        const int m = board.size();
        if (m == 0) return res;
        const int n = board[0].size();
        res.reserve(32768);

        // 1. 构建Trie
        TrieNode* root = new TrieNode();
        for (auto& w : words) {
            TrieNode* cur = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!cur->children[idx]) {
                    cur->children[idx] = new TrieNode();
                }
                cur = cur->children[idx];
            }
            cur->word = w; // 单词结尾节点保存单词
        }

        // 方向数组：上下左右
        const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        function<void(int, int, TrieNode*)> dfs = [&](int i, int j, TrieNode* node) {
            // 越界 / 当前格子已经走过
            if (i < 0 || i >= m || j <0 || j >= n || board[i][j] == '#') return;

            char c = board[i][j];
            int idx = c - 'a';
            // 这个字符不在Trie里，直接剪枝，不用继续扩散
            if (!node->children[idx]) return;

            TrieNode* nextNode = node->children[idx];
            // 走到一个单词终点
            if (!nextNode->word.empty()) {
                res.push_back(nextNode->word);
                nextNode->word = ""; // 清除，防止重复收录同一个单词
            }

            // 标记已访问
            board[i][j] = '#';
            // 四向递归
            for (auto& d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                dfs(ni, nj, nextNode);
            }
            // 回溯，恢复字符
            board[i][j] = c;
        };

        // 每个格子作为起点启动DFS
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, root);
            }
        }
        return res;
    }
};

