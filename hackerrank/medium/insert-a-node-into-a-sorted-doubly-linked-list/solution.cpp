

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
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

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);

    // Empty list
    if (llist == NULL) {
        return node;
    }

    // Insert at beginning
    if (data <= llist->data) {
        node->next = llist;
        llist->prev = node;
        return node;
    }

    DoublyLinkedListNode* temp = llist;

    // Find position
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    // Insert node after temp
    node->next = temp->next;
    node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = node;
    }

    temp->next = node;

    return llist;
}

