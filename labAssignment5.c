#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head) {
  
    node *temp = head;
    int sum = 0;
    while(temp != NULL) {
      sum++;
      temp = temp->next;
    }
    return sum;
  }


// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char *toCString(node *head) {
  
  node *temp = head;
  int len = length(head);
  char *str = (char *)malloc(len + 1);
  int i = 0;
  while(temp != NULL) {
    str[i] = temp->letter;
    temp = temp->next;
    i++;
  }
  str[i] = '\0';
  return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c) {
  
  node *tmp = *pHead;
  node *node = malloc(sizeof(node));
  node -> letter = c;
  node -> next = NULL;
  
  while (tmp -> next != NULL)
    tmp = tmp->next;
  tmp->next = node; 
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead) {
  
  node *current = *pHead;
  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }
  *pHead = NULL; 
}

int main(void) {
  int i, strLen, numInputs;
  node *head = NULL;
  char *str;
  char c;
  FILE *inFile = fopen("input.txt", "r");
  fscanf(inFile, " %d\n", &numInputs);
  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++) {
      fscanf(inFile, " %c", &c);
      insertChar(&head, c);
    }
    str = toCString(head);
    printf("String is : %s\n", str);
    free(str);
    deleteList(&head);
    if (head != NULL) {
      printf("deleteList is not correct!");
      break;
    }
  }
  fclose(inFile);
}