class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix=strs[0];
        int n=strs.length;
        if(n==0){
            return "";
        }
        int m=prefix.length();
        for(int i=0;i<m;i++){
            char ch=prefix.charAt(i);
            for(int j=1;j<n;j++){
                if(i>=strs[j].length() || ch!=strs[j].charAt(i)){
                    return prefix.substring(0,i);
                }
            }
        }
        return prefix;
    }
}