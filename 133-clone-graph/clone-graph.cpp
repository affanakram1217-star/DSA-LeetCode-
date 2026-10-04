/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    void DFS(Node* node, Node* clone_node){

        for(Node* n:node->neighbors){
            if(mp.find(n)==mp.end()){
                Node* clone=new Node(n->val);
                mp[n]=clone;
                clone_node->neighbors.push_back(clone);
                DFS(n,clone);
            }else{
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        mp.clear();
        //cloning the given node
        Node* clone_node=new Node(node->val);
        //now clone the neighbors of the node recursively and if a node reappears then we access them by storing them in a map
        mp[node]=clone_node;

        DFS(node,clone_node);

        return clone_node;
    }
};