class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        unordered_set<string> vis;

        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int level=1;
        while(!q.empty()){
            int n=q.size();

            while(n--){
                string curr=q.front();
                q.pop();

                if(curr==endWord){
                    return level;
                }

                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<curr.size();i++){
                        string neighbour=curr;
                        if(ch==curr[i]) continue;
                        neighbour[i]=ch;

                        if(vis.find(neighbour)==vis.end() &&
                        wordSet.find(neighbour)!=wordSet.end()){
                            q.push(neighbour);
                            vis.insert(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};