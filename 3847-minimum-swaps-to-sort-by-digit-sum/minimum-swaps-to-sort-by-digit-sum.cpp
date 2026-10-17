class Solution {
public:
    int getDigSum(int num){ //static also possible so it becomes a class entity
        int sum=0;
        while(num>0){
            int dig=num%10;
            sum+=dig;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> afterSorted=nums;

        auto lambda=[&](int num1,int num2){ //& to call getDigSum or make the function static
            int dSum1=getDigSum(num1);
            int dSum2=getDigSum(num2);

            if(dSum1!=dSum2){
                return dSum1<dSum2;
            }
            return num1<num2;
        };

        sort(afterSorted.begin(),afterSorted.end(),lambda);

        unordered_map<int,int> valToIdx;
        for(int i=0;i<n;i++){
            valToIdx[nums[i]]=i;
        }

        int swapCount=0;
        for(int i=0;i<n;i++){
            int expected=afterSorted[i];
            int curr=nums[i];

            if(expected==curr) continue;

            int expectedValIdx=valToIdx[expected]; //expected value kis index pe h abhi original nums pe
            //swapping
            nums[i]=expected;
            nums[expectedValIdx]=curr;
            //map update
            valToIdx[expected]=i;
            valToIdx[curr]=expectedValIdx;

            swapCount++;
        }

        return swapCount;
    }
};