#pragma once

class TestCase
{
	struct TestData
	{
		int size;
		int key;
		int resultIndex;
		int array[20];
	};

public:
   static void checkSearch(int(*func)(int A[], int size, int key));
   static void checkSearchAlt(int(*func)(int A[], int begin, int end, int key));

private:
	static TestData test1;
	static TestData test2;
	static TestData test3;
   static int arr[];
};

