class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> DeadEndsSet(deadends.begin(),deadends.end());
        string start="0000";

        if(DeadEndsSet.find(start)!=DeadEndsSet.end()){
            return -1;
        }

        queue<string> q;
        q.push(start);
        int level=0;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                string curr=q.front();
                q.pop();

                if(curr==target){
                    return level;
                }

                for(int i=0;i<4;i++){
                    char ch=curr[i];

                    char inc=(ch=='9')?'0':ch+1;
                    char dec=(ch=='0')?'9':ch-1;

                    curr[i]=inc;
                    if(DeadEndsSet.find(curr)==DeadEndsSet.end()){
                        q.push(curr);
                        DeadEndsSet.insert(curr);
                    }

                    curr[i]=dec;
                    if(DeadEndsSet.find(curr)==DeadEndsSet.end()){
                        q.push(curr);
                        DeadEndsSet.insert(curr);
                    }

                    curr[i]=ch;
                }
            }
            level++;
        }
        return -1;
    }
};