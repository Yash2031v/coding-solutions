

/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    int count=1;
    SinglyLinkedListNode* temp = llist;
    if(llist==NULL){
        return NULL;
    }
    while(count!=position){
        temp=temp->next;
        count++;
    }
    SinglyLinkedListNode* temp1 = temp->next;
    temp->next=temp->next->next;
    free(temp1);
    return llist;
    
}

