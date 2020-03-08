/*
	Day_2_3_20200212
	C++ 内存管理
*/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	/* new,delete (Keywork 关键字) >= malloc,free (库函数) */

	/* 开辟单变量空间 */

	//C
	int* p = (int*)malloc(sizeof(int));
	int* q = static_cast<int*>((int*)malloc(sizeof(int)));    //C++强制类型转换

	//C++
	//int
	int* m = new int(3);
	cout << *m << endl;
	*m = 5;
	cout << *m << endl;

	//string
	string* mm = new string("Hello ");
	cout << *mm;
	*mm = "World!";
	cout << *mm << endl;

	//struct
	struct Student {
		int age;
		string name;
	};
	Student* gkx = new Student{ 19,"Ling Gao" };
	cout << "\nStudent\nName:" << gkx->name << "\nAge:" << gkx->age << endl;

	/* 开辟多变量空间 */
	//char array
	char* ap = new char[20];
	/* 
	errno_t __cdecl strcpy_s(
        _Out_writes_z_(_SizeInBytes) char*       _Destination,
        _In_                         rsize_t     _SizeInBytes,
        _In_z_                       char const* _Source
        );
	*/
	strcpy_s(ap, 20, "ABCDEFG");    //strcpy_s() 比 strcpy() 更安全
	cout << ap << endl;

	//int array
	int* ip = new int[3];
	memset(ip, 0, sizeof(int[3]));
	for (int i = 0; i < 3; i++)
		cout << ip[i] << endl;

	//指针数组
	int** pp = new int* [3];
	
	//int[][] 多维数组
	//int* p = new int[3][4];    Error E0144 "int (*)[4]" 类型的值不能用于初始化 "int *" 类型的实体
	int(*ppa)[4] = new int[3][4]{ {0} };
	for (int i = 0; i < sizeof(int[3][4]) / sizeof(int[4]); i++)
		for (int j = 0; j < 4; j++)
			cout << ppa[i][j] << " ";


	/* 释放内存空间 */
	int* dp = new int[100];
	delete []dp;    //不能使用 delete dp,否则只释放数组第一个元素。多维数组释放时也只写一个[]

	/* malloc 开辟的内存空间不要使用 delete 释放,new 开辟的空间不要使用 free 释放 */

	/* 异常 */
	try
	{
		int* f = new int[100];
		delete []f;
	}
	catch (const std::bad_alloc e) {
		cout << "new Error" << endl;
		cout << e.what() << endl;
		return -1;
	}

	//不建议使用上述的 C++ 异常功能
	int* ff = new (std::nothrow) int[10];    //不抛出异常
	if (ff == NULL)    //如果分配失败,终止运行程序
		return -1;
	

	//程序运行结束前，释放掉所有内存空间
	free(p);
	free(q);
	delete m;
	delete mm;
	delete gkx;
	delete []ap;
	delete []ip;
	delete []pp;
	delete []ppa;
	delete []ff;
	return 0;
}
