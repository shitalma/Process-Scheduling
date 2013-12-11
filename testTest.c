#include "testUtils.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void test_for_create_a_new_process(){
	scheduler *q;
	scheduler expected = {NULL,0};
    q = create();
    ASSERT(q->front == expected.front);
    ASSERT(q->length == expected.length);
    free(q);
}

void test_for_adding_front_process(){
	scheduler *q;
	scheduler expected = {NULL,0};
    condition status = {0,1,0};
    pro firstProcess = {"firstProcess",3000,status,7,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess));
    ASSERT(q->front == &firstProcess);
    ASSERT(q->front->next == NULL);
    free(q);
}
void test_for_adding_process_that_have_high_priority_rather_than_first(){
	scheduler *q;
	scheduler expected = {NULL,0};
    condition status = {0,1,0};
    pro firstProcess = {"firstProcess",3000,status,7,NULL};
    pro secondProcess = {"secondProcess",900,status,1,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess));
    ASSERT(2 == insert(q, &secondProcess));
    ASSERT(q->front == &secondProcess);
    ASSERT(q->front->next == &firstProcess);
    free(q);
}

void test_add_process_with_priority_in_between_process_queue(){
	scheduler *q;
	scheduler expected = {NULL,0};
    condition status = {0,1,0};
    pro *second,*third;
    pro firstProcess = {"First Process",3000,status,7,NULL};
    pro secondProcess = {"Second Process",900,status,1,NULL};
    pro thirdProcess = {"Third Process",400,status,2,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess));
    ASSERT(2 == insert(q, &secondProcess));
    ASSERT(3 == insert(q, &thirdProcess));
    ASSERT(q->front == &secondProcess);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &thirdProcess);
    ASSERT(third == &firstProcess);
    ASSERT(third->next == NULL);
    free(q);
}