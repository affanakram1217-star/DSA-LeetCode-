class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        int l=0;
        int maxLen=0;
        Map<Character,Integer> mp=new HashMap<>();
        for(int r=0;r<n;r++){
            char ch=s.charAt(r);
            if(mp.containsKey(ch)){
                l=Math.max(l,mp.get(ch)+1);
            }
            mp.put(ch,r);
            maxLen=Math.max(maxLen,r-l+1);
        }

        return maxLen;
    }
}