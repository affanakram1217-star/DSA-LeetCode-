class Solution {
public:
    int t[21][1001];
    int solve(int n,int sum,vector<int>& nums){
        if(n==0){
            return (sum==0)?1:0;
        }
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        int skip=solve(n-1,sum,nums);
        int take=0;
        if(nums[n-1]<=sum){
            take=solve(n-1,sum-nums[n-1],nums);
        }

        return t[n][sum]=skip+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int S=0;
        target=abs(target);

        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            S+=nums[i];
        }

        if((S+target)%2!=0){
            return 0;
        }

        int sum=(S+target)/2;
        return solve(n,sum,nums);
    }
};