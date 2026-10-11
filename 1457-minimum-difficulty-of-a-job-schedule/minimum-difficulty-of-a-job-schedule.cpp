class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jobDifficulty,int n,int idx, int d){
        if(d==1){
            int maxD=jobDifficulty[idx];
            for(int i=idx;i<n;i++){
                maxD=max(maxD,jobDifficulty[i]);
            }
            return maxD;
        }

        if(t[idx][d]!=-1){
            return t[idx][d];
        }
        int finalResult=INT_MAX;
        int maxD=jobDifficulty[idx];

        for(int i=idx;i<=n-d;i++){
            maxD=max(maxD,jobDifficulty[i]);
            int result=maxD+solve(jobDifficulty,n,i+1,d-1);
            finalResult=min(finalResult,result);
        }
        return t[idx][d]=finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        memset(t,-1,sizeof(t));
        if(d>n){
            return -1;
        }

        return solve(jobDifficulty,n,0,d);
    }
};