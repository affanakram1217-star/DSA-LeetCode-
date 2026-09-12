class Solution {
public:
    struct Node{
        long long score=-1;
        vector<int> idxs;
    };

    int n;
    vector<int> nextIdx;
    vector<vector<Node>> t;
   
    int binarySearch(vector<vector<int>>& intervals, int endpoint){
        int low=0;
        int high=n-1;
        int result=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(intervals[mid][0]>endpoint){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;
    }
    // Node solve(vector<vector<int>>& intervals, int i, int k){  //Recursion + MEMOIZATION
    //     if(k==0 || i>=n){
    //         return Node();
    //     }

    //     if(t[i][k].score!=-1){
    //         return t[i][k];
    //     }

    //     Node skip=solve(intervals, i+1, k);
    //     //Current Node info
    //     int weight=intervals[i][2];
    //     int idx=intervals[i][3];
    //     int j=nextIdx[i];
    //     Node temp=solve(intervals,j,k-1);
    //     Node take;
    //     take.score=temp.score+ weight;
    //     take.idxs=temp.idxs;
    //     take.idxs.push_back(idx);
    //     sort(take.idxs.begin(),take.idxs.end());

    //     Node result;
    //     if(skip.score>take.score){
    //         result=skip;
    //     }else if(skip.score<take.score){
    //         result=take;
    //     }else{
    //         result=(skip.idxs<take.idxs)? skip:take;
    //     }

    //     return t[i][k]=result;
    // }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n=intervals.size();

        //store original indexes
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(),intervals.end());
        
        nextIdx.resize(n);

        for(int i=0;i<n;i++){
            int endpoint=intervals[i][1];
            nextIdx[i]=binarySearch(intervals,endpoint);
        }
        int K=4;
        t.assign(n+1,vector<Node>(K+1));


        // return solve(intervals,0,K).idxs; recursion memoization

        for(int i=n-1;i>=0;i--){
            int weight=intervals[i][2];
            int idx=intervals[i][3];
            int j=nextIdx[i];

            for(int k=1;k<=4;k++){
                Node skip=t[i+1][k];
                Node temp=t[j][k-1];
                
                Node take;
                take.score=temp.score+ weight;
                take.idxs=temp.idxs;
                take.idxs.push_back(idx);
                sort(take.idxs.begin(),take.idxs.end());

                Node result;
                if(skip.score>take.score){
                    result=skip;
                }else if(skip.score<take.score){
                    result=take;
                }else{
                    result=(skip.idxs<take.idxs)? skip:take;
                }

                t[i][k]=result;
            }
        }
        return t[0][K].idxs;

    }
};