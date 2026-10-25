/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<double> average;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            int numNodes=size;
            double levelnodesum=0.0;

            while(size--){
                TreeNode* curr=q.front();
                q.pop();

                levelnodesum+=curr->val;

                if(curr->left!=NULL){
                    q.push(curr->left);
                }

                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }

            average.push_back(levelnodesum/numNodes);
        }

        return average;
    }
};