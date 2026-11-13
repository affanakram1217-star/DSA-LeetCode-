class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        //O(n)
        vector<int> result;
        deque<int> dq;

        for(int i=0;i<n;i++){

            //Checking window size
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            //Removing smaller elements than the curr element from the window
            while(!dq.empty() && nums[i]> nums[dq.back()]){
                dq.pop_back();
            }

            //insert element to deque
            dq.push_back(i);

            //if we finish the window size we will populate the result as the largest element is always at front
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};