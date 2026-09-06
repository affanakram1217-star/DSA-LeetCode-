class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0]-points[p2][0])+abs(points[p1][1]-points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int mstCost=0;
        vector<bool> mstSet(n,false);
        pq.push({0,0});
        while(!pq.empty()){
            auto p=pq.top();
            int wt=p.first;
            int node=p.second;
            pq.pop();
            if(mstSet[node]) continue;
            mstSet[node]=true;
            mstCost+=wt;
            for(int i=0;i<n;i++){
                if(!mstSet[i]){
                    int edgeWt=manDist(points,node,i);
                    pq.push({edgeWt,i});
                }
                
            }
        }
        return mstCost;
    }
};