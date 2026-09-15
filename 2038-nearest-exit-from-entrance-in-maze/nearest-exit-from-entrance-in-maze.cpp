class Solution {
public:
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});

        maze[entrance[0]][entrance[1]]='+'; //Marking it visited
        int steps=0;
        while(!q.empty()){
            int N=q.size();

            while(N--){
                auto temp=q.front();
                q.pop();

                int i=temp.first;
                int j=temp.second;

                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && (temp != make_pair(entrance[0], entrance[1]))) {
                    return steps;
                }

                //explore all directions
                for(auto &dir: directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && maze[new_i][new_j]!='+'){
                        q.push({new_i,new_j});
                        maze[new_i][new_j]='+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};