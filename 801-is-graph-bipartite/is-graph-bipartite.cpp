class Solution {
public:
    bool dfsCheck(int curr,int currColor,vector<vector<int>>& graph,vector<int> &colors){
        colors[curr]=currColor;
        
        for(auto& ngbr: graph[curr]){
            if(colors[curr]==colors[ngbr]){
                return false;
            }

            if(colors[ngbr]==-1){
                if(dfsCheck(ngbr,1-currColor,graph,colors)==false){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n,-1);

        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(dfsCheck(i,1,graph,colors)==false){
                    return false;
                }
            }
        }

        return true;
    }
};