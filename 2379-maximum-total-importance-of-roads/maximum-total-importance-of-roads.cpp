class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0); //S.C->o(n)

        for(auto& road: roads){  //T.C.=O(E);
            int u=road[0];
            int v=road[1];

            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end()); //T.C.=O(nlogn) sorting ka

        long long sum=0; //ye wo sum h jo ham return karenge
        long long value=1; //we will assign the value

        for(int i=0;i<n;i++){
            sum+=(degree[i]*value);
            value++;
        }

        return sum;
    }
};