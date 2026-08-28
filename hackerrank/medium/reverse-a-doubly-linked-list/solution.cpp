

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if (llist == NULL)
        return NULL;

    DoublyLinkedListNode* curr = llist;

    while (curr != NULL) {
        swap(curr->next, curr->prev);
        
        if (curr->prev == NULL)
            return curr;

        curr = curr->prev;
    }

    return llist;
}  

