/*
	Day_2_5_20200212
	C++ 内联函数
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define SQR(i) (i)*(i)    //宏函数
/*
    优点:代码内嵌,无需调用函数
	缺点:容易产生歧义、容易使程序 text 段体积增大、不会进行类型检查
*/

int Sqr(int i)    //函数
{
	return i * i;
}
/*
    优点:函数是一段高度抽象的逻辑、不易产生歧义、减少text段体积
	缺点:函数调用时存在压栈与出栈的开销
*/

inline int InlineSqr(int i)    //内联函数
{
	return i * i;
}
//兼有宏函数与函数的优点

/*
    1.不能将所有的函数设定为内联函数
	2.inline 是向编译器提出的建议
	3.加 inline -> 可能会内联 | 不加 inline -> 一定不会内联
	4.Google 标准:函数在 10 行或以下时才可以定义为内联函数
	5.HUAWEI 标准:5 行
*/

int main()
{
	int i = 0;
	while (i < 5)
		cout << SQR(i++) << endl;

	cout << endl;

	i = 0;
	while (i < 5)
		cout << Sqr(i++) << endl;

	cout << endl;

	i = 0;
	while (i < 5)
		cout << InlineSqr(i++) << endl;

	return 0;
}
