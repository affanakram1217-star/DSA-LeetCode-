class Solution {
public:
    int n;

    vector<vector<int>> t;

    int findMethod(int start, int target,vector<int>& nums){
        int j=lower_bound(begin(nums)+start,end(nums),target)-begin(nums);

        if(j<n && nums[j]==target){
            return j;
        }
        return -1;
    }

    int solve(int i, int inc, vector<int>& nums){

        if(t[i][inc]!=-1){
            return t[i][inc];
        }

        int len=1;
        int currVal=nums[i]+inc;

        //1st option find currVal+1 directly
        int j=findMethod(i+1,currVal+1,nums);
        if(j!=-1){
            len=max(len,1+solve(j,0,nums));
        }

        //2nd option ffind currVal and then +1 karo
        j=findMethod(i+1,currVal,nums);
        if(j!=-1){
            len=max(len,1+solve(j,1,nums));
        }

        return t[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();
        t.assign(n+1,vector<int>(2,-1));

        sort(begin(nums),end(nums));
        int result=1;

        for(int i=0;i<n;i++){
            result=max({result,solve(i,0,nums),solve(i,1,nums)});
        }

        return result;
    }
};