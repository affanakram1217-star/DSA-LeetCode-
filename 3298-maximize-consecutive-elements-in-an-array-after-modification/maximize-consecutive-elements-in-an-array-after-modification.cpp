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

    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();
        t.assign(n+1,vector<int>(2,-1));
        sort(begin(nums),end(nums));
        int result=1;

        for(int i=n-1;i>=0;i--){
            for(int inc=0;inc<2;inc++){

                int currVal=nums[i]+inc;
                int len=1;

                int j=findMethod(i+1,currVal+1,nums);
                if(j!=-1){
                    len=max(len,1+t[j][0]);
                }
                
                j=findMethod(i+1,currVal,nums);
                if(j!=-1){
                    len=max(len,1+t[j][1]);
                }

                t[i][inc]=len;
                result=max(result,len);
            }
        }

        return result;
    }
};