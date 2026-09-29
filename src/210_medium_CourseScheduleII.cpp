class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> pre2later = {};
        vector<int> indegree(numCourses, 0);

        for (auto item : prerequisites) {
            if (item[0] == item[1]) return {};
            pre2later[item[1]].push_back(item[0]);
            indegree[item[0]] += 1;
        }

        vector<int> result;
        queue<int> dataq;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) dataq.push(i);
        }

        while (!dataq.empty()) {
            int tmp = dataq.front();
            result.push_back(tmp);
            dataq.pop();

            if (pre2later.contains(tmp)) {
                for (int i : pre2later[tmp]) {
                    indegree[i] -= 1;
                    if (indegree[i] == 0) {
                        dataq.push(i);
                    }
                }
            }
        }

        if (result.size() == numCourses) return result;
        return {};
    }
};