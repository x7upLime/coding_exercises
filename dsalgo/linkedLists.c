#include <stdlib.h>
#include <stdio.h>

typedef struct lstNode {
  int val;
  struct lstNode *next;
} lstNode_t;

void
die(const char *msg) {
  printf("%s\n", msg);
  exit(-1);
}

void
lstWalk(lstNode_t *ptr) {
  int cntr = 1;
  
  printf("Start walking...\n");
  while(ptr != NULL) {
    printf("\tNode %d --> %d\n", cntr++, ptr->val);
    ptr = ptr->next;
  }
  printf("END\n");
}

lstNode_t*
addNode(lstNode_t *tail) {
  if (tail->next != NULL){
    die("%p is not the end of the list");
  }

  tail->next = (lstNode_t *) malloc(sizeof(lstNode_t));
  return tail->next;
}

void
push(lstNode_t *head, int val) {
  lstNode_t *ptr = head;

  // goto end of ll
  while(ptr->next != NULL) {
    ptr = ptr->next;
  }

  ptr->next = (lstNode_t*) malloc(sizeof(lstNode_t));
  ptr->next->next = NULL;
  ptr->next->val = val;
}

void
prepend(lstNode_t **head, int val){
  lstNode_t *ptr = NULL;

  ptr = (lstNode_t *) malloc(sizeof(lstNode_t));
  ptr->next = *head;
  ptr->val = val;

  *head = ptr;
}

int
pop(lstNode_t **head){
  lstNode_t *ptr = NULL;
  int retval = -1;

  if (*head == NULL) {
    return -1;
  }

  ptr = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = ptr;

  return retval;
}

int
popend(lstNode_t *head){
  lstNode_t *ptr = head;
  int retval = -1;
  if (head->next == NULL) {
    retval = head->val;
    free(head);
    return retval;
  }
  
  for(; ptr->next->next != NULL; ptr = ptr->next)
    continue;

  retval = ptr->next->val;
  free(ptr->next);
  ptr->next = NULL;
  return retval;
}

void
wipeList(lstNode_t **ptr) { //non optimal solution..
			   // maybe give this another look
  int rval = -1;

  if ((*ptr) == NULL) {
    printf("List is already empty\n");
    return;
  }

  while((*ptr)->next != NULL){
    rval = popend(*ptr);
    printf("we've popped %d\n", rval);
  }

  printf("we've popped %d\n", (*ptr)->val);
  free(*ptr);
  *ptr = NULL;
}

int
remove_by_index(lstNode_t **head, int n){
  int retval = -1;

  lstNode_t *ptr = *head;
  lstNode_t *tmp = NULL;

  if (n == 0) {
    return pop(head);
  }

  for (int i = 0; i < n-1; i++) {
    if(ptr->next == NULL) {
      return -1;
    }
    ptr = ptr->next;
  }

  if (ptr->next == NULL) {
    return -1;
  }

  tmp = ptr->next;
  retval = tmp->val;
  ptr->next = tmp->next;
  free(tmp);

  return retval;
}

int
remove_by_value(lstNode_t **head, int val) {
  int retval = -1;
  lstNode_t *tmp = NULL;

  if ((*head)->val == val) {
    return pop(head);
  }
  
  for (lstNode_t *ptr = *head; ptr->next != NULL; ptr = ptr->next) {
    if (ptr->next->val == val) {
      tmp = ptr->next;
      ptr->next = ptr->next->next;
      retval = tmp->val;
      free(tmp);
      return retval;
    }
  }

  return -1;
}

int
main(void){
  // defining a ptr that we will use to point to teh 1st node in the list
  lstNode_t *head = NULL;

  // creating 1st node (allocating memory for 1st node)
  head = (lstNode_t *) malloc(sizeof(lstNode_t));
  if (head == NULL) {
    return 1; //smthing went wrong
  }

  // putting values into the memory that we allocated for the 1st ndoe
  head->val = 1;
  head->next = NULL;

  push(head, 2);
  push(head, 2);
  prepend(&head, 0);

  // some output
  lstWalk(head);

  int retval = remove_by_value(&head, 2); // removing item @ index 1 (from 0 to len(ll))
  if (retval == -1) {die("no such value");}
  lstWalk(head);
}
