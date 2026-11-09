class Solution {
public:
    typedef pair<int,int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i=0;i<k;i++){
            available_servers.insert(i);
        }

        priority_queue<P,vector<P>,greater<P>> busyServers;
        vector<int> countReq(k);
        vector<int> result;

        for(int i=0;i<arrival.size();i++){
            int time=arrival[i];

            while(!busyServers.empty() && busyServers.top().first<=time){
                int serverId=busyServers.top().second;
                busyServers.pop();

                available_servers.insert(serverId);
            }

            int targetServer=i%k;
            auto it=available_servers.lower_bound(targetServer);

            if(it==available_servers.end()){
                it=available_servers.begin(); //wrap around
            }

            if(available_servers.empty()){
                continue; //no servers available
            }

            int Target_Server=*it;
            available_servers.erase(Target_Server);

            busyServers.push({time+load[i], Target_Server});
            countReq[Target_Server]++;
        }

        int maxNoReqs=*max_element(countReq.begin(), countReq.end());
        for(int i=0;i<k;i++){
            if(countReq[i]==maxNoReqs){
                result.push_back(i);
            }
        }

        return result;
    }
};