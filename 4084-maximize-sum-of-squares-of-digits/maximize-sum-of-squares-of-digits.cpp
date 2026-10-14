class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum> num*9){
            return "";
        }

        int nines=sum/9;
        int rem=sum%9;

        string result(nines,'9');

        if(rem>0){
            result.push_back(rem+'0');
        }

        result.append(num-result.length(),'0');
        return result;
    }
};