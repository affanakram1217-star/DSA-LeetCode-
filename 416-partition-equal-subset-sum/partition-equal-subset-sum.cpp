class Solution {
public:
    int n;
    bool solve(int i, int sum,vector<int>& nums,int tar,vector<vector<int>> &t){
        if(sum==tar){
            return true;
        }
        if(i>=n || sum >tar){
            return false;
        }
        if(t[i][sum]!=-1){
            return t[i][sum];
        }

        bool take=solve(i+1,sum+nums[i],nums,tar,t);
        bool skip=solve(i+1,sum,nums,tar,t);

        return t[i][sum]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>> t(n,vector<int>(target+1,-1));
        return solve(0,0,nums,target,t);
    }
};