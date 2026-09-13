class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(),bank.end());

        unordered_set<string> visited;

        queue<string> q;
        q.push(start);
        visited.insert(start);
        int level=0;
        while(!q.empty()){
            int n=q.size();

            while(n--){
                string curr=q.front();
                q.pop();

                if(curr==end){
                    return level;
                }

                for(char ch:"ACGT"){
                    for(int i=0;i<curr.size();i++){
                        string neighbour=curr;
                        neighbour[i]=ch;//"Try A,C,G,T at each index"

                        if(visited.find(neighbour)==visited.end()&&bankset.find(neighbour)!=bankset.end()){
                            q.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};