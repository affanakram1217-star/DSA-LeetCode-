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
// class Solution {
// public:
//     int result;
//     int findSum(TreeNode* root, int &count){
//         if(root==NULL){
//             return 0;
//         }
//         count++;
//         int lsum=findSum(root->left,count);
//         int rsum=findSum(root->right,count);
//         return lsum+rsum+root->val;
//     }
//     void solve(TreeNode* root){
//         if(root==NULL){
//             return;
//         }
//         int count=0;
//         int sum=findSum(root,count);
//         if(root->val==sum/count){
//             result+=1;
//         }
//         solve(root->left);
//         solve(root->right);
//     }
//     int averageOfSubtree(TreeNode* root) {
//         result=0;

//         solve(root);
//         return result;
//     }
// };

class Solution {
public:
    int result;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto p1=solve(root->left);
        auto p2=solve(root->right);

        int totalSum=p1.first+p2.first+root->val;
        int totCount=p1.second+p2.second+1;
        int avg=totalSum/totCount;
        if(root->val==avg){
            result++;
        }
        return {totalSum,totCount};
    }
    int averageOfSubtree(TreeNode* root) {
        result=0;

        solve(root);
        return result;
    }
};