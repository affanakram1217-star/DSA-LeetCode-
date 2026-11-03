class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxEl=*max_element(nums.begin(),nums.end());
        int moves=0;

        for(int i=0;i<n;i++){
            moves+=maxEl-nums[i];
        }

        return moves;
    }
};