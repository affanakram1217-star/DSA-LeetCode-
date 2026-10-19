// class Solution {
// public:
//     unordered_map<string,vector<string>> adj;
//     int numtickets;
//     vector<string> result;
//     bool DFS(string fromAirport,vector<string>& path){
//         path.push_back(fromAirport);
//         if(path.size()==numtickets+1){
//             result=path;
//             return true;
//         }

//         vector<string>& neighbours=adj[fromAirport];
//         for(int i=0;i<neighbours.size();i++){
//             string toAirport=neighbours[i];
//             //abhi ke liye isko remove kardo
//             neighbours.erase(neighbours.begin()+i);
//             if(DFS(toAirport,path)==true){
//                 return true;
//             }
//             neighbours.insert(neighbours.begin()+i,toAirport);
//         }
//         path.pop_back();
//         return false;

//     }

//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         numtickets=tickets.size();

//         for(auto& t: tickets){
//             string u=t[0];
//             string v=t[1];

//             adj[u].push_back(v);
//         }

//         for(auto& edges:adj){
//             sort(begin(edges.second),end(edges.second));
//         }

//         vector<string> path;
//         DFS("JFK",path);

//         return result;
//     }
// };

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;
    void dfs(string u) {
        auto & edges = adj[u];
        
        while (!edges.empty())
        {
            string v = edges.top();
            edges.pop();
            dfs(v);
        }
        result.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto e : tickets)
            adj[e[0]].push(e[1]);
        
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
