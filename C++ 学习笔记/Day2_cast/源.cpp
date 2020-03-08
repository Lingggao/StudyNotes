/*
	Day_2_6_20200212
	C++ 强制类型转换
*/
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

void Function(int& a)
{
	cout << "Function: " << a << endl;
	return;
}

int main()
{
	/*
	    1.C 强制类型转换: type val = (type)xxx;
		2.C++ 强制类型转换：
		    1) static_cast    对于隐式类型,可用此转换
			2) dynamic_cast    *暂时不学* 主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换
			3) reinterpret_cast    无隐式的类型,无法使用 static_cast,需要使用此转换
			4) const_cast    用于摆脱常量,只能应用于指针和引用
		3.不建议轻易使用强制类型转换

	*/

	float a = 5.5;
	int b = 6;

	/* 隐式类型转换 */
	b = static_cast<int>(a);
	a = static_cast<float>(b);

	/* 半可转情况可以使用 static_cast */
	void* p = NULL;
	int* q = NULL;
	p = q;
	//q = p;    Error 0513 不能将 "void *" 类型的值分配到 "int *" 类型的实体
	p = static_cast<void*>(q);    //Ok
	q = static_cast<int*>(p);    //Ok

	/* 实例 1 */
	int x = 10;
	int y = 3;
	float z = x / y;    //期望值为 3.333...,实际为 3
	cout << "z = " << z << endl;
	cout << "z = " << static_cast<float>(x) / y << endl;    //Ok

	/* 实例 2 */
	//char* c = malloc(100);    Error 0144 "void *" 类型的值不能用于初始化 "char *" 类型的实体
	char* c = static_cast<char*>(malloc(100));    //Ok


	/* 无隐式类型转换 */
	int s[5] = { 1,2,3,4,5 };
	//int* ip = (int*)((int)a + 1);    Error
	int* ip = reinterpret_cast<int*>((reinterpret_cast<int>(s) + 1));    //Ok


	/* 摆脱常量 */
	//const 一定不可改
	const int co = 5;
	//int* cop = static_cast<int*>(&co);    Error 0694 static_cast 无法丢掉常量或其他类型限定符

	//Function(co);    Error 0433 将 "int &" 类型的引用绑定到 "const int" 类型的初始值设定项时，限定符被丢弃
	Function(const_cast<int&>(co));    //脱常,Ok

	int& rco = const_cast<int&>(co);
	rco = 7;
	cout << "rco = " << rco << endl;    //rco 改为 7
	cout << "co = " << co << endl;    //co 仍然为 5
	cout << "&rco = " << &rco << "\t&co = " << &co << endl;    //但 rco 与 co 两者地址相同

	/*
	    Depending on the type of the referenced object,
		a write operation through the resulting pointer,
		reference, or pointer to data member might produce undefined behavior.
	*/
	
	return 0;
}
