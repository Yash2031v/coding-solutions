

// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
    if(llist==NULL){
        llist=new_node;
        return llist;
        
    }
	new_node->next=llist;
    llist=new_node;
    return llist;

}

