

/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
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

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    dummy->next = llist;
    SinglyLinkedListNode* a = dummy;
    SinglyLinkedListNode* b = dummy;
    for(int i=0;i< positionFromTail;i++){
        b = b->next;
    }
    while(b->next!=NULL){
        a=a->next;
        b=b->next;
    }
    int r = a->data;
    return r;
}

