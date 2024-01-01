#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdint.h>
#include <stdlib.h>


typedef struct {
    void* next;
    int16_t data;
} SllNode_t;

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif // NULL_PTR


SllNode_t* AddNodeToSll(int16_t d);
uint32_t GetSllListSize(void);


#endif // SINGLE_LINKED_LIST_H