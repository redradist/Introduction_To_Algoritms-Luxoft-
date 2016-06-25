#include <iostream>
#include "TestCase.h"

TestCase::TestData TestCase::test1 = { 10, 34,     2, { 21, 23, 34, 38, 42, 50, 60, 67, 72, 88 } };
TestCase::TestData TestCase::test2 = { 10, 94,     8, { 1, 2, 5, 6, 15, 35, 76, 83, 94, 100 } };
TestCase::TestData TestCase::test3 = { 10, 100,   -1, { 1, 2, 35, 6, 15, 7, 3, 0, 23, 45 } };
int TestCase::arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

void TestCase::checkSearch(int(*func)(int A[], int size, int key))
{
   if (test1.resultIndex == func(test1.array, test1.size, test1.key))
   {
      std::cout << "First search test passed successfully" << std::endl;
      std::cout << "   key =" << test1.key << ", resultIndex = " << test1.resultIndex << std::endl;
   }
   else
   {
      std::cout << "First search test did not pass" << std::endl;
      std::cout << "   resultIndex = " <<
         func(test1.array, test1.size, test1.key) << std::endl;
   }
   if (test2.resultIndex == func(test2.array, test2.size, test2.key))
   {
      std::cout << "Second search test passed successfully" << std::endl;
      std::cout << "   key =" << test2.key << 
         ", resultIndex = " << test2.resultIndex << std::endl;
   }
   else
   {
      std::cout << "Second search test did not pass" << std::endl;
      std::cout << "   resultIndex = " << 
         func(test2.array, test2.size, test2.key) << std::endl;
   }
   if (test3.resultIndex == func(test3.array, test3.size, test3.key))
   {
      std::cout << "Third search test passed successfully" << std::endl;
      std::cout << "   key =" << test3.key << 
         ", resultIndex = " << test3.resultIndex << std::endl;
   }
   else
   {
      std::cout << "Third search test did not pass" << std::endl;
      std::cout << "   resultIndex = " <<
         func(test3.array, test3.size, test3.key) << std::endl;
   }
   std::cout << "Forth search test started" << std::endl;
   bool success = true;
   int arrSize = sizeof(arr)/2;
   for (int i = 0; i < arrSize; i++)
   {
      int key = arr[i];
      int index = func(arr, arrSize, key);
      std::cout << "key: " << key << " index:" << index << std::endl;
   }
   std::cout << "Forth search test " << 
      ((success) ? "success" : "fail") << std::endl;
}

void TestCase::checkSearchAlt(int(*func)(int A[], int begin, int end, int key))
{
   if (test1.resultIndex == func(test1.array, 0, test1.size, test1.key))
   {
      std::cout << "First search test passed successfully" << std::endl;
      std::cout << "   key =" << test1.key << ", resultIndex = " << test1.resultIndex << std::endl;
   }
   else
   {
      std::cout << "First search test did not pass" << std::endl;
      std::cout << "   resultIndex = " <<
         func(test1.array, 0, test1.size, test1.key) << std::endl;
   }
   if (test2.resultIndex == func(test2.array, 0, test2.size, test2.key))
   {
      std::cout << "Second search test passed successfully" << std::endl;
      std::cout << "   key =" << test2.key <<
         ", resultIndex = " << test2.resultIndex << std::endl;
   }
   else
   {
      std::cout << "Second search test did not pass" << std::endl;
      std::cout << "   resultIndex = " <<
         func(test2.array, 0, test2.size, test2.key) << std::endl;
   }
   if (test3.resultIndex == func(test3.array, 0, test3.size, test3.key))
   {
      std::cout << "Third search test passed successfully" << std::endl;
      std::cout << "   key =" << test3.key <<
         ", resultIndex = " << test3.resultIndex << std::endl;
   }
   else
   {
      std::cout << "Third search test did not pass" << std::endl;
      std::cout << "   resultIndex = " <<
         func(test3.array, 0, test3.size, test3.key) << std::endl;
   }
   std::cout << "Forth search test started" << std::endl;
   bool success = true;
   int arrSize = sizeof(arr)/(2*sizeof(int));
   for (int i = 0; i < arrSize; i++)
   {
      int key = arr[i];
      int index = func(arr, 0, arrSize, key);
      std::cout << "key: " << key << " index:" << index << std::endl;
   }
   std::cout << "Forth search test " <<
      ((success) ? "success" : "fail") << std::endl;
}