class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int mid=nums[n/2];
        
        int moves=0;
        for(int i=0;i<n/2;i++){
            moves+=abs(nums[i]-mid);
            moves+=abs(nums[n-i-1]-mid);
        }

        return moves;
    }
};