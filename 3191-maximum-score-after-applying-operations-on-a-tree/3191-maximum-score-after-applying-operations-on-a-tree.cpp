/* Approach : DFS 
We need to find minimum elements in paths from root to leaf nodes which will remain in the tree.
Root is a common node. So we need to compare root value with minimum leftout child sum we get.
Whichever is smaller will be passed to parent as minimum leftout value.

We can do this using DFS. Leaf nodes will be first considered as minimum element.
Then while backtracking, they will be compared with parent to find minimum elements to consider

Answer will be : total sum - sum of remaining node values
Time : O(V+E)   // DFS traversal
Space : O(V+E)  // for adjacency list
*/
class Solution {
public:
    long long dfs(int node, vector<int> &visited, vector<vector<int>> &adjList, vector<int> &values){
        visited[node] = 1;  // mark visited
        // visit children / neighbours
        long long minChildSum = 0;
        for(auto it : adjList[node])
            if(!visited[it])
                minChildSum += dfs(it, visited, adjList, values);

        // compare min child sum with node value
        if(minChildSum == 0)    // for leaf node
            return (long long) values[node];
        return min(minChildSum, (long long) values[node]);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        // store graph using adjacency list
        vector<vector<int>> adjList(n);
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        // calculate sum of all tree values
        long long total = 0;
        for(int i=0; i<n; i++)
            total += values[i];
        
        // calculate sum of leftout nodes using dfs
        vector<int> visited(n, 0);
        long long leftout = dfs(0, visited, adjList, values);
        return total - leftout;
    }
};