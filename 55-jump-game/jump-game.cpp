class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> t(n+1,0);
        t[0]=true;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(j+nums[j]>=i && t[j]==true){
                    t[i]=true;
                    break;
                }
            }
        }
        return t[n-1];
    }
};