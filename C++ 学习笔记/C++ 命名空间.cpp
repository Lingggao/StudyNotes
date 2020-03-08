/*
	Day_2_8_20200213
	C++ 命名空间
*/
#include <iostream>
#include <algorithm>
#include "Dog.h"
#include "Cat.h"
#include "Apple.h"
using std::cin;
using std::cout;
using std::endl;

//全局无名命名空间
int vi = 5;    //全局变量

/* namespace 是对全局命名空间的再次划分 */
namespace Ling
{
	int a;
	void function()
	{
		cout << "Ling::function();" << endl;
		return;
	}
	//命名空间支持嵌套
	namespace Gaaooo
	{
		int a;
	}
}
namespace Gao
{
	int a;
	void function()
	{
		cout << "Gao::function();" << endl;
		return;
	}
}

/* 两个命名空间重名时将会自动合并,使用此特性可以很方便的进行协作开发 */
namespace Hello
{
	int x;
	//int y;    等价于此情况
}
namespace Hello
{
	int y;
}

int main()
{
	/* 默认 namespace:global、function */
	int* vp = &vi;
	int vi = 55;    //局部变量
	cout << vi << endl;    //局部变量会覆盖全局变量
    cout << *vp << endl;    //但是可以使用指针 "釜底抽薪" 来访问全局变量

	/* :: -> 作用域运算符,运算符前需要添加命名空间 */
	cout << ::vi << endl;    //无名命名空间

	using Ling::a;
	using namespace Gao;
	a = 9;
	cout << "Ling::a = " << Ling::a << endl << "Gao::a = " << Gao::a << endl;

	/* 命名空间支持嵌套 */
	Ling::Gaaooo::a = 8;
	cout << Ling::Gaaooo::a;

	/* 重名命名空间自动合并,便于协作开发 */
	Hello::x = 5;
	Hello::y = 6;

	/* 协作开发 */

	//Dog d;    Error 0020 未定义标识符 "Dog"
	Animal::Dog dog;    //Ok
	Fruit::Apple apple;    //Ok

	return 0;
}
