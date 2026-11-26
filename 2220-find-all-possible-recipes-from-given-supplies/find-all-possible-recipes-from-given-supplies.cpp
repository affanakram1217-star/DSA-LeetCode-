class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();

        unordered_set<string> st(supplies.begin(),supplies.end());
        vector<bool> cooked(n,false);

        vector<string> result;
        int count=n;
        while(count--){

            for(int j=0;j<n;j++){
                if(cooked[j]==true){
                    continue;
                }
                bool banpayega=true;
                for(int k=0;k<ingredients[j].size();k++){
                    if(!st.count(ingredients[j][k])){
                        banpayega=false;
                        break;
                    }
                }
                if(banpayega==true){
                    result.push_back(recipes[j]);
                    st.insert(recipes[j]);
                    cooked[j]=true;
                }
            }
        }

        return result;
    }
};