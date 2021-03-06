#include "cutest/CuTest.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
    
/* 
 * Add your tests here
 * A few sample tests 
 * are provided
 */

void TestHeap(CuTest *tc) {
  Heap* h = makeHeap(10);
  CuAssertIntEquals(tc, 0, h->size);
  cleanupHeap(h);
}

void TestOne(CuTest *tc) {
  int two = 2;
  int four = 4;
  CuAssertIntEquals(tc, four, two+two);
}

void TestTwo(CuTest *tc) {
  char* lol = "lol";
  char* alsoLol = "lol";
  CuAssertStrEquals(tc, lol, alsoLol);
}

void TestMakeHeap(CuTest *tc) {
	Heap* h = makeHeap(10);
	CuAssertIntEquals(tc, 10, h->capacity);
	CuAssertIntEquals(tc, 0, h->size);
	cleanupHeap(h);
	Heap* h2 = makeHeap(1);
	CuAssertIntEquals(tc, 1, h2->capacity);
	cleanupHeap(h2);
}

void TestAdd(CuTest *tc) {
	Heap* h = makeHeap(3);
	add(h, 2, "3");
	CuAssertIntEquals(tc, 3, h->capacity);
	add(h, 1, "1");
	add(h, 0, "0");
	CuAssertIntEquals(tc, 3, h->capacity);
	add(h, 2, "2");
	CuAssertIntEquals(tc, 6, h->capacity);
	CuAssertIntEquals(tc, 0, h->elements[0].key);
	CuAssertStrEquals(tc, "0", h->elements[0].value);
	CuAssertIntEquals(tc, 1, h->elements[2].key);
	CuAssertStrEquals(tc, "1", h->elements[2].value);
	CuAssertIntEquals(tc, 2, h->elements[1].key);
	CuAssertStrEquals(tc, "2", h->elements[1].value);
	CuAssertIntEquals(tc, 2, h->elements[3].key);
	CuAssertStrEquals(tc, "3", h->elements[3].value);
	cleanupHeap(h);
}

void TestRemoveMin(CuTest *tc) {
	Heap* h = makeHeap(3);
	CuAssertStrEquals(tc, NULL, removeMin(h));
	add(h, 2, "3");
	CuAssertStrEquals(tc, "3", removeMin(h));
	add(h, 2, "3");
	add(h, 2, "1");
	add(h, 0, "0");
	add(h, 2, "2");
	add(h, 5, "5");
	CuAssertStrEquals(tc, "0", removeMin(h));
/*	int i;
	for (i = 0; i < h->size; i += 1){
		printf("%s\n", h->elements[i].value);
	}*/
	CuAssertIntEquals(tc, 2, h->elements[0].key);
	CuAssertStrEquals(tc, "2", h->elements[0].value);
	CuAssertIntEquals(tc, 2, h->elements[1].key);
	CuAssertStrEquals(tc, "3", h->elements[1].value);
	CuAssertIntEquals(tc, 2, h->elements[2].key);
	CuAssertStrEquals(tc, "1", h->elements[2].value);
	CuAssertIntEquals(tc, 5, h->elements[3].key);
	cleanupHeap(h);
	Heap* h2 = makeHeap(10);
	add(h2, 1, "a");
	add(h2, 2, "b");
	add(h2, 3, "c");
	add(h2, 4, "d");
	add(h2, 5, "e");
	add(h2, 6, "f");
	add(h2, 7, "g");
	add(h2, 8, "h");
	CuAssertStrEquals(tc, "a", removeMin(h2));
	CuAssertIntEquals(tc, 7, size(h2));
	CuAssertStrEquals(tc, "b", removeMin(h2));
	CuAssertIntEquals(tc, 6, size(h2));
	CuAssertIntEquals(tc, 3, h2->elements[0].key);
	CuAssertIntEquals(tc, 4, h2->elements[1].key);
	CuAssertIntEquals(tc, 6, h2->elements[2].key);
	CuAssertIntEquals(tc, 8, h2->elements[3].key);
	CuAssertIntEquals(tc, 5, h2->elements[4].key);
	CuAssertIntEquals(tc, 7, h2->elements[5].key);
	cleanupHeap(h2);
	Heap* h3 = makeHeap(3);
	add(h3, 1, "a");
	add(h3, 3, "b");
	add(h3, 2, "c");
	add(h3, 4, "d");
	add(h3, 8, "e");
	add(h3, 7, "f");
	add(h3, 6, "g");
	CuAssertStrEquals(tc, "a", removeMin(h3));
	CuAssertIntEquals(tc, 2, h3->elements[0].key);
	CuAssertIntEquals(tc, 6, h3->elements[2].key);
	cleanupHeap(h3);
}

void TestPeek(CuTest *tc) {
	Heap* h = makeHeap(3);
	CuAssertStrEquals(tc, NULL, peek(h));
	add(h, 2, "3");
	CuAssertStrEquals(tc, "3", peek(h));
	add(h, 2, "1");
	CuAssertStrEquals(tc, "1", peek(h));
	add(h, 0, "0");
	CuAssertStrEquals(tc, "0", peek(h));
	add(h, 2, "2");
	CuAssertStrEquals(tc, "0", peek(h));
	cleanupHeap(h);
}

void TestSizeAndCapacity(CuTest *tc) {	
	Heap* h = makeHeap(1);
	CuAssertIntEquals(tc, 1, h->capacity);
	CuAssertIntEquals(tc, 0, size(h));
	add(h, 2, "3");
	CuAssertIntEquals(tc, 1, h->capacity);
	CuAssertIntEquals(tc, 1, size(h));
	add(h, 2, "1");
	CuAssertIntEquals(tc, 2, h->capacity);
	CuAssertIntEquals(tc, 2, size(h));
	add(h, 0, "0");
	CuAssertIntEquals(tc, 4, h->capacity);
	CuAssertIntEquals(tc, 3, size(h));
	removeMin(h);
	CuAssertIntEquals(tc, 4, h->capacity);
	CuAssertIntEquals(tc, 2, size(h));
	add(h, 2, "2");
	add(h, 5, "5");
	add(h, 5, "5");
	removeMin(h);
	CuAssertIntEquals(tc, 8, h->capacity);
	CuAssertIntEquals(tc, 4, size(h));
	cleanupHeap(h);
}

CuSuite* StrUtilGetSuite() {
  CuSuite* suite = CuSuiteNew();

  /** ADD YOUR TESTS HERE **/
  SUITE_ADD_TEST(suite, TestHeap);
  SUITE_ADD_TEST(suite, TestOne);
  SUITE_ADD_TEST(suite, TestTwo);
	SUITE_ADD_TEST(suite, TestMakeHeap);
	SUITE_ADD_TEST(suite, TestAdd);
	SUITE_ADD_TEST(suite, TestRemoveMin);
	SUITE_ADD_TEST(suite, TestPeek);
	SUITE_ADD_TEST(suite, TestSizeAndCapacity);
  return suite;
}


// Don't edit below this line

void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();
  CuSuite* ourSuite = StrUtilGetSuite();
  
  CuSuiteAddSuite(suite, ourSuite);

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);

  CuStringDelete(output);
  CuSuiteDelete(suite);
  free(ourSuite);
}

int main(void) {
  RunAllTests();
  return 0;
}
