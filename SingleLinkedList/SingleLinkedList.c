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


/* Remove node from anywhere in the list */



/* Insert node anywhere into the list */



/* Get length of list */
uint32_t GetSllListSize(void)
{
    return SllListSize;
}
