class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        int maxR=nums[0];
        vector<int> t(nums);

        deque<int> dq;

        for(int i=0;i<n;i++){

            //checking the window size
            while(!dq.empty() && dq.front()<i-k){
                dq.pop_front();
            }

            if(!dq.empty()){
                t[i]=max(t[i],nums[i]+t[dq.front()]);
            }

            while(!dq.empty() && t[i]>t[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);

            maxR=max(maxR,t[i]);
        }

        return maxR;
    }
};