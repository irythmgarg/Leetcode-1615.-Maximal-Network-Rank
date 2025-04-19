class Solution {
public:
    /**
     * Calculates the maximal network rank in a city network.
     * The network rank of two cities is the total number of roads connected to either city,
     * counting the direct road between them only once.
     *
     * @param n Number of cities labeled from 0 to n-1.
     * @param roads List of roads where each road connects two cities.
     * @return The maximal network rank of any two different cities.
     */
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        // Adjacency list using unordered_set to avoid duplicate entries
        unordered_map<int, unordered_set<int>> mp;

        // Build the graph: store all connected cities for each city
        for (int i = 0; i < roads.size(); i++) {
            int from = roads[i][0];
            int to = roads[i][1];
            mp[from].insert(to);
            mp[to].insert(from);
        }

        int maxans = 0;

        // Iterate over all unique pairs of cities (i, j)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int first = mp[i].size();   // Number of roads connected to city i
                int second = mp[j].size();  // Number of roads connected to city j

                // Subtract one if cities i and j are directly connected
                int total = first + second - (mp[i].find(j) != mp[i].end());

                // Track the maximum network rank found so far
                maxans = max(maxans, total);
            }
        }

        return maxans;
    }
};
