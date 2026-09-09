class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        //Approach 1
        ll result=0;
        ll lower=1000;
        ll comma=1;

        while(lower<=n){
            ll upper=lower*1000-1;
            if(upper>n){
                upper=n;
            }
            ll CountNums=upper-lower+1;
            result+=CountNums*comma;

            lower*=1000;
            comma+=1;
        }
        return result;
    }
};