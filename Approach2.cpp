class Solution {
public:
    /**
     * Calculates the maximal network rank using degree array and connection matrix.
     * Optimized in terms of look-up speed compared to unordered_set.
     *
     * @param n Number of cities labeled from 0 to n-1.
     * @param roads List of bidirectional roads between cities.
     * @return The maximal network rank among any two cities.
     */
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        // deg[i] stores the number of roads connected to city i
        vector<int> deg(n, 0);

        // isconnected[i][j] is true if there is a direct road between city i and city j
        vector<vector<bool>> isconnected(n, vector<bool>(n, false));

        // Build degree array and connection matrix
        for (int i = 0; i < roads.size(); i++) {
            int from = roads[i][0];
            int to = roads[i][1];

            deg[from]++;
            deg[to]++;
            isconnected[from][to] = true;
            isconnected[to][from] = true;
        }

        int maxans = 0;

        // Check all pairs (i, j) to compute their network rank
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int first = deg[i];
                int second = deg[j];

                // Subtract 1 if cities i and j are directly connected
                int total = first + second - isconnected[i][j];

                maxans = max(maxans, total);
            }
        }

        return maxans;
    }
};
