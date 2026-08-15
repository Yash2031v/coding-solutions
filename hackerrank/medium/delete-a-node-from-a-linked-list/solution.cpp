

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
    int count=1;
    SinglyLinkedListNode* temp = llist;
    while(count!=position){
        temp=temp->next;
        count++;
    }
    SinglyLinkedListNode* temp1 = temp->next;
    temp->next=new_node;
    new_node->next=temp1;
    return llist;
    
    
}

