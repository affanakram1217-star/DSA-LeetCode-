class Solution {
public:
    //Approach 1 BFS
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<P>> timeMeetings;

        for(vector<int>& meeting : meetings){
            int person1=meeting[0];
            int person2=meeting[1];
            int time=meeting[2];

            timeMeetings[time].push_back({person1,person2});
        }

        vector<bool> knowsSecret(n,false);
        knowsSecret[0]=true;
        knowsSecret[firstPerson]=true;

        for(auto& it: timeMeetings){
            int key=it.first;
            vector<P> meets=it.second;

            unordered_map<int,vector<int>> adj;
            queue<int> q;
            unordered_set<int> alreadyAdded;

            for(auto& [person1, person2]:meets){
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if(knowsSecret[person1]==true && alreadyAdded.find(person1)==alreadyAdded.end()){
                    q.push(person1);
                    alreadyAdded.insert(person1);
                }

                if(knowsSecret[person2]==true && alreadyAdded.find(person2)==alreadyAdded.end()){
                    q.push(person2);
                    alreadyAdded.insert(person2);
                }
            }

            while(!q.empty()){
                int person=q.front();
                q.pop();

                for(auto& nextPerson: adj[person]){
                    if(knowsSecret[nextPerson]==false){
                        q.push(nextPerson);
                        knowsSecret[nextPerson]=true;
                    }
                }
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(knowsSecret[i]==true){
                result.push_back(i);
            }
        }

        return result;
    }
};