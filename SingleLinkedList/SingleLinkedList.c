#include "SingleLinkedList.h"


static SllNode_t* sll_head = NULL_PTR;
static size_t SllListSize = 0;


/* Add node at the front of the list */
SllNode_t* AddNodeToSll(int16_t d)
{
    SllNode_t* new = malloc(sizeof(SllNode_t));
    if (new == NULL_PTR) {
        /* no need to free here because the memory was never allocated */
        return NULL_PTR;
    }

    SllListSize++;
    new->data = d;
    if (sll_head != NULL_PTR)
    {
        /* there isn't anything in the list yet */
        new->next = sll_head;
        sll_head = new;
    }
    else
    {
        /* push the new data at the front of the list */
        new->next = NULL_PTR;
        sll_head = new;
    }

    return new;
}


/* Remove node from anywhere in the list 
 *
 *    Returns whether an element was removed
 */
int8_t RemoveNodeFromSll(int16_t d)
{
    SllNode_t* current = sll_head;
    SllNode_t* prev = current;
    while (current != NULL_PTR)
    {
        if (current->data == d) {
            /* remove the node */

            if (current == sll_head)
            {
                /* if the item to be removed is the first */
                sll_head = current->next;
            }
            else
            {
                /* set the prev to point to the next */
                prev->next = current->next;
            }

            /* free the current memory (MEMORY LEAK) */
            free(current);
            current = NULL_PTR;
            if (SllListSize > 0)
            {
                SllListSize--;
            }

            return 1;
        } else {
            /* not a match - check the next node */
            prev = current;
            current = current->next;
        }
    }

    return 0;
}


/* Insert node anywhere into the list 
 *  NOTE: cannot insert into an empty list
 *          use AddNodeToSll first
 *  Returns a pointer to the newly added node
 */
SllNode_t* InsertNodeToSll(int16_t d, uint32_t index)
{
    if (index == 0)
    {
        return AddNodeToSll(d);
    }

    SllNode_t* current = sll_head;
    while (current != NULL_PTR && index > 0)
    {
        index--;
        current = current->next;
    }

    if (index > 0 || current == NULL_PTR) 
    {
        /* invalid insertion index */
        return NULL_PTR;
    }

    SllNode_t* new = malloc(sizeof(SllNode_t));
    if (new == NULL_PTR) {
        /* no need to free here because the memory was never allocated */
        return NULL_PTR;
    }

    SllListSize++;
    new->data = d;
    new->next = current->next;
    current->next = new;

    return new;
}


/* Get length of list */
uint32_t GetSllListSize(void)
{
    return SllListSize;
}


/* Get the list head */
SllNode_t* GetSllHead(void)
{
    return sll_head;
}