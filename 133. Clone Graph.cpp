//https://leetcode.com/problems/clone-graph/

class Solution {
public:
    map<int,Node *> isVisited;
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
    
        Node * temp  = new Node(node->val,{});
        isVisited[temp->val] = temp;
           
        for(int i = 0;i<node->neighbors.size();i++){   
            
            if(isVisited.find(node->neighbors[i]->val) == isVisited.end()){
                temp->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }    
            else{
                temp->neighbors.push_back(isVisited[node->neighbors[i]->val]);
            }
        }
            
        return isVisited[node->val];
        
    }
};