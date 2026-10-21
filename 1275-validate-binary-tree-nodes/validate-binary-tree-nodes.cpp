class Solution {
public:
    int components;
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    bool Union(int P,int C){
        if(find(C)!=C){
            return false;
        }

        if(find(P)==C){
            return false;
        }

        parent[C]=P;
        components-=1;
        return true;

    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components=n;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){

            int node=i;
            int leftchild=leftChild[i];
            int rightchild=rightChild[i];
            
            if(leftchild!=-1 && Union(node,leftchild)==false){
                return false;
            }

            if(rightchild!=-1 && Union(node,rightchild)==false){
                return false;
            }
        }

        return components==1;
    }
};