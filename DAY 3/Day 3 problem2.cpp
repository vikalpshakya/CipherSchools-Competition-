#include<map>
BinaryTreeNode<int>* createParentMapping(BinaryTreeNode<int>* root, map <BinaryTreeNode<int>*, BinaryTreeNode<int>*> &nodeToParent, int target){

    if(root == NULL) return(NULL);   
    BinaryTreeNode<int>* targetNode = NULL;
    queue<BinaryTreeNode<int>*> que;
    que.push(root);
    nodeToParent[root] = NULL;
    while(!que.empty()){
        BinaryTreeNode<int>* ptr = que.front();
        que.pop();
        if(ptr->data == target) targetNode = ptr; 
        if(ptr->left){
            nodeToParent[ptr->left] = ptr;
            que.push(ptr->left);
        }
        if(ptr->right){
            nodeToParent[ptr->right] = ptr;
            que.push(ptr->right);
        }
    }
    return(targetNode);
}

int burnTree(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &nodeToParent){
    map<BinaryTreeNode<int>*, bool> visited;
    queue<BinaryTreeNode<int>*> que;
     int time = 0;
     que.push(root);
    visited[root] = true;
    while(!que.empty()){
        bool addition = false;
        int size = que.size();
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* front = que.front();
            que.pop();
            if(front->left && !visited[front->left]){
                addition = true;
                que.push(front->left);
                visited[front->left] = true;
            }
            if(front->right && !visited[front->right]){
                addition = true;
                que.push(front->right);
                visited[front->right] = true;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                addition = true;
                que.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(addition == true) time++;
    }
     return(time);
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> nodeToParent;
    BinaryTreeNode<int>* targetNode = createParentMapping(root, nodeToParent, start);
    return(burnTree(targetNode, nodeToParent));

}
