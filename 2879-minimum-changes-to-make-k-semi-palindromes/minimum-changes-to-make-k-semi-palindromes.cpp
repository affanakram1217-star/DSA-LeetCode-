//Approach-2 (Bottom Up)
//T.C : O(n^3 * div(n) + n^2 * k) ~ O(n^3)
//S.C : O(n^2) (costMemo n*n + memo n*k)
class Solution {
public:
    int n;
    string str;

    vector<vector<int>> costMemo;
    vector<vector<int>> memo;

    int getCost(int i, int j) {
        int len = j - i + 1;

        int minCost = INT_MAX;

        for(int d = 1; d < len; d++) {
            if(len % d != 0)
                continue;
            
            int cost = 0;
            for(int group = 0; group < d; group++) { //for d, we will have d groups
                int l = i + group;
                int r = l + (len/d - 1) * d;

                while(l < r) {
                    if(str[l] != str[r])
                        cost++;
                    
                    l += d;
                    r -= d;
                }
            }

            minCost = min(minCost, cost);
        }

        return minCost;
    }

    int minimumChanges(string s, int k) {
        n = s.length();
        str = s;

        costMemo.assign(n+1, vector<int>(n+1, INT_MAX)); //n*n
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                costMemo[i][j] = getCost(i, j);
            }
        }

        memo.assign(n+1, vector<int>(k+1, INT_MAX));

        memo[n][0] = 0;

        for(int start = n; start >= 0; start--) {
            for(int pieces = 1; pieces <= k; pieces++) {
                if(start + 2*pieces > n)
                    continue;
                
                int result = INT_MAX;

                for(int end = start+1; end < n; end++) {
                    int remainCost = memo[end+1][pieces-1];

                    if(remainCost == INT_MAX)
                        continue;
                    
                    result = min(result, costMemo[start][end] + remainCost);
                }

                memo[start][pieces] = result;
            }
        }

        return memo[0][k];
    }
};