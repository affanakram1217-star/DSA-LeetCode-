class Solution {
public:
    void bellmanFord(int S, vector<vector<int>>& edges, vector<int>& result,int n){
        fill(result.begin(), result.end(), 1e9+7);
        result[S]=0;

        for(int i=1;i<n;i++){
            for(auto& edge: edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];

                if(result[u]!=1e9+7 && result[u]+wt<result[v]){
                    result[v]=result[u]+wt;
                }

                if(result[v]!=1e9+7 && result[v]+wt<result[u]){
                    result[u]=result[v]+wt;
                }
            }
        }
    }

    int findTheResultCity(int n,  vector<vector<int>> &SPM, int D){
        int resultCity=-1;
        int leastCityReachcnt=INT_MAX;

        for(int i=0;i<n;i++){
            int currCityCnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && SPM[i][j]<=D){
                    currCityCnt++;
                }
            }

            if(currCityCnt<=leastCityReachcnt){
                leastCityReachcnt=currCityCnt;
                resultCity=i;
            }
        }

        return resultCity;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Approach 2-> Bellman ford
        vector<vector<int>> SPM(n,vector<int>(n,1e9+7));

        for(int i=0;i<n;i++){
            SPM[i][i]=0;
        }

   
        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            SPM[u][v]=wt;
            SPM[v][u]=wt;

        }

        //calculating shortest path from each node
        for(int i=0;i<n;i++){
            bellmanFord(i,edges,SPM[i],n);
        }

        return findTheResultCity(n,SPM,distanceThreshold);
    }
};