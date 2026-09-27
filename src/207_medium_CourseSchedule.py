class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        pre2laters = defaultdict(list)
        node_count_list = [0 for _ in range(numCourses)]

        for item in prerequisites:
            if item[0] == item[1]:
                 return False
            pre2laters[item[1]].append(item[0])
            node_count_list[item[0]] += 1

        queue = [i for i in range(numCourses) if node_count_list[i] == 0]
        count = 0
        while queue:
            node = queue.pop()
            count += 1
            if node in pre2laters:
                for later in pre2laters[node]:
                    node_count_list[later] -= 1
                    if node_count_list[later] == 0:
                        queue.append(later)
                
        return count == numCourses
    