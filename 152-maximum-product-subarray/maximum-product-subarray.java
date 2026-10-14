class Solution {
    public int maxProduct(int[] nums) {
        int n=nums.length;
        int ans=nums[0];
        int maxP=nums[0];
        int minP=nums[0];

        for(int i=1;i<n;i++){
            int x=nums[i];
            if(x<0){
                int temp=minP;
                minP=maxP;
                maxP=temp;
            }
            maxP=Math.max(x,x*maxP);
            minP=Math.min(x,x*minP);
            ans=Math.max(ans,maxP);
        }
        return ans;
    }
}