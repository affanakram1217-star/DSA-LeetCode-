class Solution {
public:
    int n;
    int t[50001];
    int getNextIdx(vector<vector<int>>& arr, int l, int currJobEnd){
        int r=n-1;
        int result=n+1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid][0]>=currJobEnd){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& arr, int i){
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int next=getNextIdx(arr,i+1,arr[i][1]);
        int taken=arr[i][2]+solve(arr,next);
        int skip=solve(arr,i+1);

        return t[i]=max(taken,skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> arr(n,vector<int>(3,0)); //store start,end,profit
        memset(t,-1,sizeof(t));

        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }

        auto lambda=[&](vector<int> &vec1, vector<int>& vec2){
            return vec1[0]<vec2[0];
        };

        sort(arr.begin(),arr.end(),lambda);

        return solve(arr,0);
    }
};