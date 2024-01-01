#include <stdio.h>

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
    TEST_ASSERT_UINT8_WITHIN_MESSAGE(0, 1, 1, "failed");
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