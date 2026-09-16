class Solution {
public:
    int M=1e9+7;
    typedef long long ll;
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<ll,ll>>> t(m,vector<pair<ll,ll>>(n));

        t[0][0]={grid[0][0],grid[0][0]};

        //fill first row
        for(int i=1;i<n;i++){
            t[0][i].first=t[0][i-1].first*grid[0][i];//maxVal
            t[0][i].second=t[0][i-1].second*grid[0][i];//minVal
        }

        //fill first col
        for(int i=1;i<m;i++){
            t[i][0].first=t[i-1][0].first*grid[i][0];//maxVal
            t[i][0].second=t[i-1][0].second*grid[i][0];//minVal
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upMax=t[i-1][j].first;
                ll upMin=t[i-1][j].second;

                ll lmax=t[i][j-1].first;
                ll lmin=t[i][j-1].second;

                t[i][j].first=max({upMax*grid[i][j],upMin*grid[i][j],lmax*grid[i][j],lmin*grid[i][j]});
                t[i][j].second=min({upMax*grid[i][j],upMin*grid[i][j],lmax*grid[i][j],lmin*grid[i][j]});

            }
        }
        auto [maxProd,minProd]=t[m-1][n-1];
        return maxProd<0?-1:maxProd%M;
    }
};