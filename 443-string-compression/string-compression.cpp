class Solution {
public:
    int compress(vector<char>& chars) {
        // int n=chars.size();
        // int idx=0;
        // for (int i=0;i<n;i++){
        //     char ch=chars[i];
        //     int count=0;
        //     while(i<n && chars[i]==ch){
        //         count++;
        //         i++;
        //     }
        //     if (count==1){
        //         chars[idx++]=ch;
        //     }
        //     else{
        //         chars[idx++]=ch;
        //         string str=to_string(count);
        //         for (char dig:str){
        //             chars[idx++]=dig;
        //         }
        //     }
        //     i--;
        // }
        // chars.resize(idx);
        // return idx;

        //While Loop se 

        int n=chars.size();
        int index=0;
        int i=0;

        while(i<n){
            char curr_char=chars[i];
            int count=0;
            //find the duplicates
            while(i<n && chars[i]==curr_char){
                i++;
                count++;
            }

            //Assign karo
            chars[index]=curr_char;
            index++;

            if(count>1){
                string count_char=to_string(count);
                for(char& dig:count_char){
                    chars[index]=dig;
                    index++;
                }
            }
            
        }
        return index;
    }
};