class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return {};
        }
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            int currEnd=merged.back()[1];
            int nextStart=intervals[i][0];
            int nextEnd=intervals[i][1];

            if(currEnd>=nextStart){
                merged.back()[1]=max(currEnd,nextEnd);
            }else{
                merged.push_back(intervals[i]); //no overlap add new interavl
            }
        }

        return merged;
    }
};