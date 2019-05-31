/********************
 *
 * Sentence reversal program using Linked List based Stack
 *
 ********************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

// create the struct
struct Node_t_t
{
    char *value;
    struct Node_t_t *next;
};

// create the shortform
typedef struct Node_t_t Node_t ;

// function templates
Node_t *newNode(const char *value, Node_t *next);
Node_t *deleteNode(Node_t *current, char **value);
bool pop(Node_t **head, char **value);
bool push(Node_t **head, const char *value);

/* use void as parameters to silence the gcc warnings */
int main(void)
{
    // initialize our things
    Node_t *Stack = NULL;
    char buffer[BUFFER_SIZE] = { 0 };

    // fill our stack from the user input
    while(1 == scanf("%s", buffer))
    {
        push(&Stack, buffer);
    }

    // write out the sentence in reverse order

    while(Stack != NULL)
    {

        char *str = NULL;
        bool popped = pop(&Stack, &str);
        printf("THREE");
        if( popped && NULL != str )
        {
            printf("ONE");
            printf("%s ", str);
            free(str);
            printf("234234");

        }
    }

    return EXIT_SUCCESS;
}

/**************
 * TODO: Finish implementing these functions
 */

/**
 * return a NULL pointer if it failed to allocate memory
 * makes a copy of the string `value` on the heap (see strdup())
 * and stores the pointer in the newly created Node.
 * sets the next node to be the parameter `next`
 */
Node_t *newNode(const char *value, Node_t *next)
{
    struct Node_t_t* new_node = (struct Node_t_t*) malloc(sizeof(Node_t));
    new_node->value = value;
    new_node->next = next;
    return new_node;
    //return NULL;
}

/**
 * puts the current node string pointer at the `value` parameter
 * free's the `current` Node.
 * and return the next node.
 */
Node_t *deleteNode(Node_t *current, char **value)
{
  Node_t * temp = current;
  temp = current->next;
  *value = current->value;
  printf("in delete node, value = %s", *value);

  free (current);
  return temp;
}

/**
 * Pop the string from the top of the stack using deleteNode
 * update the top of the stack
 * puts the popped string onto `value`
 * return true on success
 */
bool pop(Node_t **Stack, char **value)
{
  struct Node_t* current = NULL;
  printf("not past current, value = %s", *value);
  current = deleteNode(&Stack, value);
  *value = current->value;
  printf("past current, value = %s", value);
  printf("<---");

  return true;

}

/**
 * Push the string to the top of the stack using newNode
 * update the top of the stack
 * return true if everything is successfull
 */
bool push(Node_t **Stack, const char *value)
{
  // allocate node
  Node_t *new_node = newNode(value, Stack);
  //put in new data
  new_node->value  = value;
  //make next of new node as head
  new_node->next = (*Stack);
  (*Stack)    = new_node;
  //printf("its %s", new_node->value);

  return true;
}
