class Solution {
public:
    int n,x,k;
    vector<long long> minOpsSubarray;
    vector<vector<long long>> memo;

    long long solve(int count, int i){
        if(count==k){
            return 0;
        }
        int subArraysNeeded=k-count;
        int elementsNeeded=subArraysNeeded*x;
        int lastIdx=i+elementsNeeded-1;

        if(lastIdx>=n){
            return 1e16;
        }

        if(memo[count][i]!=-1){
            return memo[count][i];
        }

        long long result= minOpsSubarray[i]+solve(count+1,i+x); //take ith index as starting of a subarray
        result=min(result,solve(count,i+1));//skip the index i

        return memo[count][i]=result;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        this->n=nums.size();
        this->x=x;
        this->k=k;

        minOpsSubarray.resize(n - x + 1);
        memo.assign(k + 1, vector<long long>(n + 1, -1));
        
        multiset<int> left,right;
        int i=0;
        int j=0;
        long long leftSum=0;
        long long rightSum=0;

        while(j<n){
            //inserting new element to the sliding window
            if(left.size()<=right.size()){
                left.insert(nums[j]);
                leftSum+=nums[j];
            }else{
                right.insert(nums[j]);
                rightSum+=nums[j];
            }

            //Balancing
            if(!left.empty() && !right.empty()){
                int leftMax=*left.rbegin();
                int rightMin=*right.begin();

                if(leftMax>rightMin){
                    left.insert(rightMin);
                    right.insert(leftMax);
                    left.erase(left.find(leftMax));
                    right.erase(right.find(rightMin));

                    leftSum+=rightMin-leftMax;
                    rightSum+=leftMax-rightMin;
                }
            }

            //checking if the subarray is valid
            if(j-i+1==x){
                long long median=*left.rbegin();
                long long leftSize=left.size();
                long long rightSize=right.size();

                minOpsSubarray[i]=(median*leftSize-leftSum) + (rightSum-median*rightSize);

                if(left.find(nums[i])!=left.end()){
                    left.erase(left.find(nums[i]));
                    leftSum-=nums[i];
                }else{
                    right.erase(right.find(nums[i]));
                    rightSum-=nums[i];
                }
                i++;
            }
            j++;
        }

        return solve(0,0);
    }
};