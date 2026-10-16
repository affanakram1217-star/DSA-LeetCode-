class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;
    int n;
    vector<ll> SqSumTree;
    vector<ll> SumSegTree;
    vector<ll> lazyTree;

    void lazyAddition(int i, int l, int r,int val){
        int len=(r-l+1);

        SqSumTree[i]+=2*val*SumSegTree[i]+len*val*val;
        SumSegTree[i]+=(len*val);
    }

    void updateRange(int start, int end, int i, int l, int r, int val){
        if(lazyTree[i]!=0){
            lazyAddition(i,l,r,lazyTree[i]);

            if(l!=r){
                lazyTree[2*i+1]+=lazyTree[i];
                lazyTree[2*i+2]+=lazyTree[i];
            }
            lazyTree[i]=0;
        }

        //out of range
        if(l>end || r<start || l>r){
            return;
        }

        //completely within range
        if(l>=start && r<=end){
            lazyAddition(i,l,r,val);
            //child ko bta do ki add karna h future me 
            if(l!=r){
                lazyTree[2*i+1]+=val;
                lazyTree[2*i+2]+=val;
            }
            return;
        }

        int mid=l+(r-l)/2;
        updateRange(start,end,2*i+1,l,mid,val);
        updateRange(start,end,2*i+2,mid+1,r,val);

        SumSegTree[i]=SumSegTree[2*i+1]+SumSegTree[2*i+2];
        SqSumTree[i]=SqSumTree[2*i+1]+SqSumTree[2*i+2];

    }
    int sumCounts(vector<int>& nums) {
        n=nums.size();
        SqSumTree.assign(4*n,0);
        SumSegTree.assign(4*n,0);
        lazyTree.assign(4*n,0);

        vector<ll> lastSeenIdx(100001,-1);
        ll result=0;
        for(int i=0;i<n;i++){
            int start=lastSeenIdx[nums[i]]+1;
            int end=i;

            updateRange(start,end,0,0,n-1,1);
            result=(result+SqSumTree[0])%MOD;
            lastSeenIdx[nums[i]]=i;
        }

        return result;
    }
};