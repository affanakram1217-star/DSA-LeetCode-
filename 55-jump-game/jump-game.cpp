class Solution {
public:
    int t[10001];
    bool solve(int idx, int n, vector<int>& nums){
        if(idx==n-1){
            return true;
        }

        if(t[idx]!=-1){
            return t[idx];
        }

        for(int i=1;i<=nums[idx];i++){
            if(solve(idx+i,n,nums)==true){
                return t[idx]=1;
            }
        }

        return t[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,n,nums);
    }
};