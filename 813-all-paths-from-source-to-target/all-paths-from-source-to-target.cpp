class Solution {
public:
    void dfs(int u, int target, vector<int>& temp, vector<vector<int>>& result, vector<vector<int>>& graph){
        //backtracking
        temp.push_back(u); //include
        if(u==target){
            result.push_back(temp);
        }else{
            for(int v: graph[u]){//explore
                dfs(v,target,temp,result,graph);
            }
        }
        temp.pop_back();//exclude

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> temp;
        vector<vector<int>> result;

        int source=0;
        int target=n-1;

        dfs(source,target,temp,result,graph);

        return result;
    }
};