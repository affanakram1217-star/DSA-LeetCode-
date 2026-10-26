class Solution {
public:
    void FloydWarshall(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
        for(int i=0;i<26;i++){
            adjMatrix[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            int s=original[i]-'a';
            int t=changed[i]-'a';

            adjMatrix[s][t]=min(adjMatrix[s][t],(long long)cost[i]);
        }

        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adjMatrix[i][j]=min(adjMatrix[i][j],adjMatrix[i][via]+adjMatrix[via][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adjMatrix(26,vector<long long>(26, INT_MAX));
        long long ans=0;
        FloydWarshall(adjMatrix, original, changed, cost);

        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]){
                continue;
            }

            if(adjMatrix[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }

            ans+=adjMatrix[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
};