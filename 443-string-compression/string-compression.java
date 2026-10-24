class Solution {
    public int compress(char[] chars) {
        int n=chars.length;
        int idx=0;
        int i=0;

        while(i<n){
            char curr_char=chars[i];
            int count=0;

            while(i<n && chars[i]==curr_char){
                count++;
                i++;
            }

            chars[idx]=curr_char;
            idx++;

            if(count>1){
                String count_chars=String.valueOf(count);
                for(char dig: count_chars.toCharArray()){
                    chars[idx]=dig;
                    idx++;
                }
            }
        }

        return idx;
    }
}