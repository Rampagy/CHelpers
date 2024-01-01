#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "unity/unity.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif // NULL_PTR

// constructor and deconstructor for unity test suite
void setUp (void) {} /* Is run before every test, put unit init calls here. */
void tearDown (void) {} /* Is run after every test, put unit clean-up calls here. */


void test_DoubleLinkedList(void)
{
    /* TODO: Double Linked list */
    TEST_ASSERT_MESSAGE(0, "Not yet implemented");
}


void test_SingleLinkedList(void)
{
    int16_t newVal = 5;
    uint32_t listSize = 0;
    SllNode_t* head = AddNodeToSll(newVal);
    SllNode_t* current = head;

    TEST_ASSERT_EQUAL_size_t_MESSAGE(1, GetSllListSize(), "incorrect size");
    while (current != NULL_PTR)
    {
        /* there should only be 1 value in the list and it should have a value of 5 */
        TEST_ASSERT_EQUAL_INT16_MESSAGE(5, current->data, "incorrect value after add");
        current = current->next;
    }

    newVal = 22;
    head = AddNodeToSll(newVal);
    listSize = GetSllListSize();
    TEST_ASSERT_EQUAL_size_t_MESSAGE(2, listSize, "incorrect size");
    while (current != NULL_PTR)
    {
        /* there should be 2 values in the list [22, 5] */
        if (listSize == 2) {
            /* first value should be 22 */
            TEST_ASSERT_EQUAL_INT16_MESSAGE(22, current->data, "incorrect value after add");
        } else if (listSize == 1) {
            /* second value should be 5 */
            TEST_ASSERT_EQUAL_INT16_MESSAGE(5, current->data, "incorrect value after add");
        } else {
            TEST_ASSERT_MESSAGE(0, "Should not be reached");
        }
        
        current = current->next;
        listSize--;
    }
}


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    UNITY_BEGIN();

    /* run the tests */
    RUN_TEST(test_SingleLinkedList);
    RUN_TEST(test_DoubleLinkedList);

    return UNITY_END();
}