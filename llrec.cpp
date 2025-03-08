#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  // if head is equal to null list is empty
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  // store the location of the next node
  Node* followingnode = head->next;

  // check if the value is less than or equal to or greater than the pivot
  if(head->val <= pivot){
    // add to smaller list
    smaller = head;
    // recursively call using the next node and moving forward in the smaller list
    llpivot(followingnode, smaller->next, larger, pivot);
  } else {
    // add to larger list
    larger = head;
    // recursively call using the next node and moving forward in the larger list
    llpivot(followingnode, smaller, larger->next, pivot);
  }

  // delete head Pointer
  head = nullptr;
}
