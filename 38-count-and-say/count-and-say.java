class Solution {
    public String countAndSay(int n) {
        if(n==1){
            return "1";
        }

        String say=countAndSay(n-1);
        String res="";
        int i=0;
        int len=say.length();
        while(i<len){
            char curr_char=say.charAt(i);
            int count=0;

            while(i<len && say.charAt(i)==curr_char){
                count++;
                i++;
            }

            res+=String.valueOf(count)+String.valueOf(curr_char);
        }

        return res;
    }
}