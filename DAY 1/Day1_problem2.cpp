// Time Complexity: O(n^2) [Worst case]
// Space Complexity: O(n) [Space by recursive stack]

Node* partition(Node* start, Node* end) {
    Node* pivot = start;
    Node* curr = start->next;
    Node* prev = start;

    while (curr != end->next) {
        if (pivot->value > curr->value) {
            swap(prev->next->value, curr->value);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(prev->value, pivot->value);
    return prev;
}

void sort(Node* start,Node* end){
    if(start!=NULL && end!=NULL && start!=end->next){
        Node* part = partition(start,end);
        sort(start,part->prev);
        sort(part->next,end);
    }
}

Node* quickSort(Node* head) {
    Node* temp = head;
    while(temp->next && temp){
        temp = temp->next;
    }
    sort(head,temp);
    return head;
}
