class Solution {
public:
    typedef pair<int,int> P;
    typedef tuple<long, int, int> T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m=tasks.size();
        int n=servers.size();

        //We will use 2 heaps freeServers and busyServers
        priority_queue<P,vector<P>,greater<P>> freeServer;
        priority_queue<T,vector<T>,greater<T>> busyServer;

        //initially before processing any task we have all servers free
        for(int i=0;i<n;i++){
            freeServer.push({servers[i],i});
        }

        vector<int> result(m);

        //Process the tasks 
        for(int i=0;i<m;i++){
            //case 1->check if we can free the servers by time i, free them and push to freeServers
            while(!busyServer.empty() && get<0>(busyServer.top())<=i){
                auto [finTime, wt, idx]=busyServer.top();
                busyServer.pop();
                freeServer.push({wt,idx});
            }

            //case 2-> if all servers are busy
            if(freeServer.empty()){
                auto [finTime, wt, idx]=busyServer.top();
                busyServer.pop();
                result[i]=idx;
                busyServer.push({finTime + tasks[i], wt, idx});
            }else{
                auto [wt, idx]=freeServer.top();
                freeServer.pop();
                result[i]=idx;
                busyServer.push({i+tasks[i],wt,idx});
            }
        }

        return result;
    }
};