class Solution {
public:
    vector<int> topoSort(unordered_map<int,vector<int>>& adj, vector<int>& indegree){

        queue<int> q;

        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> result;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);

            for(int & v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        return result.size()==adj.size()?result:vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //assigning groups to items that are loners
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m++;
            }
        }

        //Step:1 make itemGraph and itemIndegree
        unordered_map<int,vector<int>> itemGraph;
        vector<int> itemIndegree(n,0);
        for(int i=0;i<n;i++){
            itemGraph[i]=vector<int>();
        }

        //Step:2 make groupGraph and groupIndegree
        unordered_map<int,vector<int>> groupGraph;
        vector<int> groupIndegree(m,0);
        for(int i=0;i<m;i++){
            groupGraph[i]=vector<int>();
        }

        //filling the graphs
        for(int i=0;i<n;i++){
            for(int prev: beforeItems[i]){
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                if(group[i]!=group[prev]){
                    int prevItemGroup=group[prev];
                    int currItemGroup=group[i];

                    groupGraph[prevItemGroup].push_back(currItemGroup);
                    groupIndegree[currItemGroup]++;
                }
            }
        }

        //topoSort call
        vector<int> itemOrder=topoSort(itemGraph,itemIndegree);
        vector<int> groupOrder=topoSort(groupGraph, groupIndegree);

        unordered_map<int,vector<int>> groupToItemOrder;
        for(int& item: itemOrder){
            int itemGroup=group[item];
            groupToItemOrder[itemGroup].push_back(item);
        }

        vector<int> result;

        for(int& group: groupOrder){
            result.insert(result.end(),groupToItemOrder[group].begin(),groupToItemOrder[group].end());
        }

        return result;
    }
};