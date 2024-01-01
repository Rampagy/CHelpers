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
    (void)AddNodeToSll(newVal);
    SllNode_t* current = GetSllHead();

    TEST_ASSERT_EQUAL_UINT32_MESSAGE(1, GetSllListSize(), "incorrect size");
    current = GetSllHead();
    while (current != NULL_PTR)
    {
        /* there should only be 1 value in the list and it should have a value of 5 */
        TEST_ASSERT_EQUAL_INT16_MESSAGE(5, current->data, "incorrect value after add");
        current = current->next;
    }

    newVal = 22;
    (void)AddNodeToSll(newVal);
    listSize = GetSllListSize();
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(2, listSize, "incorrect size");
    current = GetSllHead();
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


    TEST_ASSERT_EQUAL_INT8_MESSAGE(1, RemoveNodeFromSll(5), "return value is incorrect");
    listSize = GetSllListSize();
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(1, listSize, "incorrect size");
    current = GetSllHead();
    while (current != NULL_PTR)
    {
        /* there should only be 1 value in the list and it should have a value of 22 */
        TEST_ASSERT_EQUAL_INT16_MESSAGE(22, current->data, "incorrect value after remove");
        current = current->next;
    }


    TEST_ASSERT_EQUAL_INT8_MESSAGE(1, RemoveNodeFromSll(22), "return value is incorrect");
    listSize = GetSllListSize();
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(0, listSize, "incorrect size");
    current = GetSllHead();
    while (current != NULL_PTR)
    {
        /* there shouldn't be any values in the list */
        TEST_ASSERT_MESSAGE(0, "list should not contain any values");
        current = current->next;
        listSize--;
    }


    TEST_ASSERT_EQUAL_INT8_MESSAGE(0, RemoveNodeFromSll(22), "return value is incorrect");
    listSize = GetSllListSize();
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(0, listSize, "incorrect size");
    current = GetSllHead();
    while (current != NULL_PTR)
    {
        /* there shouldn't be any values in the list */
        TEST_ASSERT_MESSAGE(0, "list should not contain any values");
        current = current->next;
        listSize--;
    }


    newVal = 10;
    (void)AddNodeToSll(newVal);
    (void)InsertNodeToSll(9, 0);
    (void)InsertNodeToSll(11, 1);
    (void)InsertNodeToSll(13, 2);
    (void)InsertNodeToSll(12, 2);
    listSize = GetSllListSize();
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(5, listSize, "incorrect size");
    current = GetSllHead();
    while (current != NULL_PTR)
    {
        /* there should be 5 values in the list [9, 10, 11, 12, 13] */
        if (listSize == 5) {
            /* first value should be 9 */
            TEST_ASSERT_EQUAL_INT16_MESSAGE(9, current->data, "incorrect value after add");
        } else if (listSize == 4) {
            /* second value should be 10 */
            TEST_ASSERT_EQUAL_INT16_MESSAGE(10, current->data, "incorrect value after add");
        } else if (listSize == 3) {
            /* third value should be 11 */
            TEST_ASSERT_EQUAL_INT16_MESSAGE(11, current->data, "incorrect value after add");
        } else if (listSize == 2) {
            /* fourth value should be 12 */
            TEST_ASSERT_EQUAL_INT16_MESSAGE(12, current->data, "incorrect value after add");
        } else if (listSize == 1) {
            /* fifth value should be 13 */
            TEST_ASSERT_EQUAL_INT16_MESSAGE(13, current->data, "incorrect value after add");
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