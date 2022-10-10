/*
    There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

    Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

    Example 1:
        Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
        Output: 3
        Explanation:
            Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
            Travel to station 4. Your tank = 4 - 1 + 5 = 8
            Travel to station 0. Your tank = 8 - 2 + 1 = 7
            Travel to station 1. Your tank = 7 - 3 + 2 = 6
            Travel to station 2. Your tank = 6 - 4 + 3 = 5
            Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
            Therefore, return 3 as the starting index.
    
    Example 2:
        Input: gas = [2,3,4], cost = [3,4,3]
        Output: -1
        Explanation:
            You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
            Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
            Travel to station 0. Your tank = 4 - 3 + 2 = 3
            Travel to station 1. Your tank = 3 - 3 + 3 = 3
            You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
            Therefore, you can't travel around the circuit once no matter where you start.
*/

// There are 2 ways below. They are the same on the algorithm. 
// Way-2 can save much more memory than Way-1. 

// Way-1 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int gas_sum = 0, cost_sum = 0;
        for (int i=0; i<size; i++) gas_sum += gas[i];
        for (int i=0; i<size; i++) cost_sum += cost[i];
        if (gas_sum < cost_sum) return -1;
        
        vector<pair<int, int>> sites(size, {0,0}); 
        sites[0].first = 0;  // first is reaching the site but not adding gas yet 
        sites[0].second = gas[0];  // second is reaching the site and after adding gas 
        
        int minGas = INT_MAX; 
        int minSite = size; 
        
        for (int i=1; i<size; i++) {
            sites[i].first = sites[i-1].second - cost[i-1]; 
            sites[i].second = sites[i].first + gas[i];
            
            if (sites[i].first < minGas) {
                minGas = sites[i].first;
                minSite = i;
            }
        }
        
        sites[0].first = sites[size-1].second - cost[size-1];
        if (sites[0].first < minGas) minSite = 0;
        
        return minSite; 
    }
};

// Way-2
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int gas_sum = 0, cost_sum = 0;
        for (int i=0; i<size; i++) gas_sum += gas[i];
        for (int i=0; i<size; i++) cost_sum += cost[i];
        if (gas_sum < cost_sum) return -1;
        
        int currJustReach = 0;
        int currReachAndAdd = gas[0]; 
        
        int minGas = INT_MAX; 
        int minSite = size; 
        
        for (int i=1; i<size; i++) {
            currJustReach = currReachAndAdd - cost[i-1];
            currReachAndAdd = currJustReach + gas[i]; 
            
            if (currJustReach < minGas) {
                minGas = currJustReach; 
                minSite = i;
            }
        }
        
        // Finally, return to site[0]
        currJustReach = currReachAndAdd - cost[size-1];
        if (currJustReach < minGas) minSite = 0;
        return minSite; 
    }
};
