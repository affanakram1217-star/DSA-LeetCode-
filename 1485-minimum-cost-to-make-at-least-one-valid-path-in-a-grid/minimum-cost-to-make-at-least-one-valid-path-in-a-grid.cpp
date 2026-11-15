class Solution {
public:
    vector<vector<int>> directions = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        deque<pair<int,int>> dq;

        dq.push_front({0,0});
        cost[0][0] = 0;

        while(!dq.empty()) {

            auto [i,j] = dq.front();
            dq.pop_front();

            for(int dir_i = 0; dir_i < 4; dir_i++) {

                int new_i = i + directions[dir_i][0];
                int new_j = j + directions[dir_i][1];

                if(new_i >= 0 && new_i < m &&
                   new_j >= 0 && new_j < n) {

                    int gridDir = grid[i][j];

                    int dirCost = (gridDir - 1 != dir_i) ? 1 : 0;

                    int newCost = cost[i][j] + dirCost;

                    if(newCost < cost[new_i][new_j]) {

                        cost[new_i][new_j] = newCost;

                        if(dirCost == 0) {
                            dq.push_front({new_i,new_j});
                        }
                        else {
                            dq.push_back({new_i,new_j});
                        }
                    }
                }
            }
        }

        return cost[m-1][n-1];
    }
};