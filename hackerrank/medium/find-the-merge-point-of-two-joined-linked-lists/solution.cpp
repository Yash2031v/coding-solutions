

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* a = head1;
    SinglyLinkedListNode* b = head2;

    while (a != b) {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }

    return a->data;
}
