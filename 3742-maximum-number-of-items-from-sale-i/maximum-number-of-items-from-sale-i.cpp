class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int cheapestItem=INT_MAX;
        vector<int> copies(n,0);

        for(int i=0;i<n;i++){
            cheapestItem=min(cheapestItem,items[i][1]);
            int copy=0;

            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(items[j][0]%items[i][0]==0){
                    copy++;
                }
            }
            copies[i]=copy;
        }

        vector<vector<int>> t(n+1,vector<int>(budget+1,0));

        //base case
        for(int b=0;b<budget+1;b++){
            t[0][b]=b/cheapestItem;
        }

        for(int i=1;i<n+1;i++){
            for(int b=0;b<budget+1;b++){
                int price=items[i-1][1];
                int take=0;

                if(price<=b){
                    take=1+copies[i-1]+t[i-1][b-price];
                }

                int skip=t[i-1][b];

                t[i][b]=max(take,skip);
            }
        }

        return t[n][budget];

    }
};