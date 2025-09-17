#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> findCycles(const vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    vector<vector<int>> result;

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        unordered_set<int> currentSet;
        vector<int> path;
        int current = i;

        // Follow the chain until we revisit a node
        while (!visited[current] && currentSet.find(current) == currentSet.end()) {
            currentSet.insert(current);
            path.push_back(current);
            current = arr[current];
        }

        // If we detect a cycle in the current path
        if (currentSet.find(current) != currentSet.end()) {
            vector<int> cycle;
            bool inCycle = false;
            for (int idx : path) {
                if (idx == current) inCycle = true;
                if (inCycle) cycle.push_back(idx);
                visited[idx] = true;
            }
            result.push_back(cycle);
        } else {
            // Mark all visited even if no cycle was found
            for (int idx : path) {
                visited[idx] = true;
            }
        }
    }

    return result;
}
