class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        //arr[i]=ith ugly number
        arr[1]=1; //first ugly number is 1

        int i2=1;//point initially to first ugly number
        int i3=1;
        int i5=1;
        for(int i=2;i<=n;i++){
            int i2UglyNum=arr[i2]*2;
            int i3UglyNum=arr[i3]*3;
            int i5UglyNum=arr[i5]*5;

            int minUglyNum=min({i2UglyNum,i3UglyNum,i5UglyNum}); //agla ugly number yahi h
            arr[i]=minUglyNum;//assigned the ugly number
            if(minUglyNum==i2UglyNum){ //jiska uglynum ke equal h uska pointers increment karna h
                i2++;
            }
            if(minUglyNum==i3UglyNum){
                i3++;
            }
            if(minUglyNum==i5UglyNum){
                i5++;
            }
        }
        return arr[n];
    }
};