

/*
 * Complete the 'removeDuplicates' function below.
 *
 * The( function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(llist==NULL){
        return llist;
    }
    SinglyLinkedListNode* temp = llist;
    while(temp->next!=NULL){
        if(temp->data == temp->next->data){
            temp->next=temp->next->next;
        }else{
        temp=temp->next;
        }
    }
    return llist;
}

