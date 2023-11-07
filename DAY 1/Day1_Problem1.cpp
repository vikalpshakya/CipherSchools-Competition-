// 		Time Complexity: O(n), Space Complexity: O(1)

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    if(!head) return NULL;
 
    Node *prev = NULL, *next = NULL;
    Node *tail = NULL, *join = NULL;
	Node *curr = head;
    bool newHead = false;
    int i = 0;
	
    while(curr and i<n){
        int K = b[i];
        
        if(K == 0){
            i++;
            continue;
        }
        join = curr;
        prev = NULL;
        
        while(curr and K--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if(newHead == false){
            head = prev;
            newHead = true;
        }
        
        if(tail){
            tail->next = prev;
        }
        
        tail = join;
        i++;
    }
    
    if(tail != NULL){
        tail->next = curr;
    }
    
    return head;
}


