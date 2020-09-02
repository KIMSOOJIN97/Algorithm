#include <vector>
#include <string>

using namespace std;


struct Node {
    int x,y,idx;
    Node * left;
    Node * right;
};

vector<int> preorder(Node * node, vector <int> & pre)
{
    pre.push_back(node->idx +1);
    if(node->left!=NULL)    preorder(node->left, pre);
    if(node->right!=NULL) preorder(node->right,pre);
    
    return pre;
}

vector<int> postorder(Node * node, vector <int>& post){
    if(node->left!=NULL)    postorder(node->left, post);
    if(node->right!=NULL) postorder(node->right,post);
    post.push_back(node->idx+1);
    
    return post;
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    vector<vector<int>> answer;
    
    vector<Node> node;
    int size= nodeinfo.size();
    
    for(int i=0;i<nodeinfo.size();i++){

        Node temp = { nodeinfo[i][0], nodeinfo[i][1], i, NULL,NULL };
        node.push_back(temp);
    }
        
        
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(node[j].y < node[j+1].y){
                
                Node temp = node[j];
                node[j] = node[j+1];
                node[j+1] = temp;
            }
        }
    }
    
    
    Node * Head = &node[0];
    
    for(int i=1;i<size;i++){
        
        Node * parent = Head;
        Node * temp = Head;
        
        while( temp != NULL){
            parent = temp;
            if(node[i].x < temp->x) temp = temp->left;
            else    temp= temp->right;
            
        }
        
        if(node[i].x < parent->x) parent->left = &node[i];
        else    parent->right = &node[i];
        
    }

    vector <int> pre;
    vector <int> post;
    
    pre = preorder(Head, pre);
    post =postorder(Head,post);
    
    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

