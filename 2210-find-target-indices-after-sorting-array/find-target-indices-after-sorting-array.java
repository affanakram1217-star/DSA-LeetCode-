class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int count1=0;
        int count2=0;

        for(int num: nums){
            if(num<target){
                count1++;
            }else if(num==target){
                count2++;
            }
        }

        List<Integer> result=new ArrayList<>();
        for(int idx=count1;idx<count1+count2;idx++){
            result.add(idx);
        }

        return result;
    }
}