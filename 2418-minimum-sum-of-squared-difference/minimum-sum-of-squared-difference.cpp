class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int K=k1+k2;
        int maxDiff=0;
        for(int i=0;i<n;i++){
            maxDiff=max(maxDiff,abs(nums1[i]-nums2[i]));
        }

        vector<int> countDiff(maxDiff+1,0);
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            countDiff[d]++;
        }

        for(int currDiff=maxDiff;currDiff>0 && K>0;currDiff--){
            int countOpns=min(countDiff[currDiff],K);
            countDiff[currDiff]-=countOpns;
            countDiff[currDiff-1]+=countOpns;
            K-=countOpns;
        }

        long long result=0;
        for(int d=0;d<=maxDiff;d++){
            result+=1LL*countDiff[d]*d*d;
        }

        return result;
    }
};