class Solution {
public:
    void dfs(int u, vector<bool>& vis, vector<vector<int>>& rooms){
        vis[u]=true;
        for(int v: rooms[u]){
            if(!vis[v]){
                dfs(v,vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(0,vis,rooms);
        for(bool room: vis){
            if(room==false){
                return false;
            }
        }
        return true;
    }
};