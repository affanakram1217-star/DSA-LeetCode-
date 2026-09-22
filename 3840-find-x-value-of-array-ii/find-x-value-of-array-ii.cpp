
struct Node {
    int count[5]={0};
    int prod=0;
};

class SegmentTree{
    public:
        int n;
        int k;
        vector<Node> segTree;

        SegmentTree(vector<int>& nums, int k){
            this->k=k;
            this->n=nums.size();
            segTree.resize(4*n,Node());
            build(0,0,n-1,nums);
        }

        void build(int i, int l, int r ,vector<int>& nums){
            if(l==r){
                leafNode(i,nums[l]);
                return;
            }

            int mid=l+(r-l)/2;
            build(2*i+1,l,mid,nums);
            build(2*i+2,mid+1,r,nums);
            segTree[i]=mergeNodes(segTree[2*i+1],segTree[2*i+2]);
        }

        void leafNode(int i, int val){
            for(int x=0;x<k;x++){
                segTree[i].count[x]=0;
            }

            int rem=val%k;
            segTree[i].count[rem]=1;
            segTree[i].prod=rem;
        }

        Node mergeNodes(Node& left, Node& right){
            Node result;
            result.prod=(left.prod*right.prod)%k;

            for(int x=0;x<k;x++){
                result.count[x]=left.count[x];
            }
            for(int x=0;x<k;x++){
                int newRem=(left.prod*x)%k;
                result.count[newRem]+=right.count[x];
            }

            return result;
        }

        void segTreeUpdate(int i, int l, int r, int index, int val){
            if(l==r){
                leafNode(i,val);
                return;
            }

            int mid=l+(r-l)/2;
            if(index<=mid){
                segTreeUpdate(2*i+1,l,mid,index,val);
            }else{
                segTreeUpdate(2*i+2,mid+1,r,index,val);
            }

            segTree[i]=mergeNodes(segTree[2*i+1],segTree[2*i+2]);
        }

        void update(int idx, int val){
            segTreeUpdate(0,0,n-1,idx,val);
        }

        Node segTreeQuery(int start,int end,int i, int l, int r){
            if(l>=start && r<=end){
                return segTree[i];
            }

            int mid=l+(r-l)/2;
            if(end<=mid){
                return segTreeQuery(start, end,2*i+1,l,mid);
            }
            if(start>mid){
                return segTreeQuery(start,end,2*i+2,mid+1,r);
            }

            Node left=segTreeQuery(start, end,2*i+1,l,mid);
            Node right=segTreeQuery(start,end,2*i+2,mid+1,r);

            return mergeNodes(left,right);
        }

        Node query(int start, int end){
            //range is[start,end]
            //i=-->index of root node of segment tree which covers the range 0..n-1 of nums

            return segTreeQuery(start,end,0,0,n-1);
        }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();

        SegmentTree segTree(nums,k);
        vector<int> result;

        for(auto& q:queries){
            int idx=q[0];
            int val=q[1];
            int start=q[2];
            int x=q[3];

            segTree.update(idx,val);

            Node resultNode=segTree.query(start,n-1);
            result.push_back(resultNode.count[x]);
        }

        return result;
    }
};