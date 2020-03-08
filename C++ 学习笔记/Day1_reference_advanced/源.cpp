/*
	Day_1_7_20200211
	C++ 高级引用知识
*/
#include <iostream>
using namespace std;

int main()
{
	/*1.可以定义指针的引用,不能定义引用的引用*/
	int a = 5;
	int* p = &a;
	int** pp = &p;
	int**& rp = pp;    //Ok
	cout << **rp << endl;
	//int*&& rrp = rp;    Error

	/*2.可以定义指针的指针,不能定义引用的指针*/
	int b = 4;
	int& rb = b;
	int* bp = &rb;    //Ok
	//int&* bpp = &rb;    Error
	//int &* -> Error # int *& -> Ok

	/*3.可以定义指针数组,不能定义引用数组,可以定义数组引用*/
	int m = 1, n = 2, t = 3;
	int* sp[] = { &m,&n,&t };    //Ok
	//int& rp[] = { m,n,t };    Error,原因:int& 首地址为 int&*
	int arr[5] = { 1,2,3,4,5 };
	//int*& rarr = arr;    Error,原因:int* 与 int[X] 不完全等价
	int(&rarr)[5] = arr;    //OK

	return 0;
}
