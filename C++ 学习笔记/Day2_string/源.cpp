/*
	Day_2_10_20200213
	C++ 系统 string 类
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string operator- (string, string);

int main()
{
	/* string 不是 C++ 关键字，而是一个类 */
	string es;
	cout << es << "*" << endl;    //空 string 输出为空,而不是输出空格

	/* 初始化方法 */
	string str1("Microsoft");
	string str2 = "Google";

	string str3;
	str3 = "Apple";

	string str4(str3);    //== string str4 = str3;
	str4 = str3;    //可以直接 =,不必使用 strcpy()

	cout << str1 << "  " << str2 
		 << "  " << str3 << "  " << str4 << endl;

	/* 字节数 */
	cout << sizeof(string) << endl;    //64 位:40、32 位:28,平台不同字节数可能不同,一般 >= 4

	/* 输入 string */
	string cinstr;
	cin >> cinstr;
	cout << cinstr << endl;

	/* string 操作 */
	str4 = str3;    //字符串复制
	str4 += str3;    //字符串追加

	cout << str4.size() << endl;    //string.size() 字符串长度

	//string 比较
	if (str3 > str4)
		cout << "str3 > str4" << endl;
	else
		cout << "str3 <= str4" << endl;

	cout << str4[2] << endl;    //下标操作

	str3.swap(str4);    //字符串交换

	/* 返回 C 字符串 */
	char buffer[100];
	string bstr = "Microsoft";
	strcpy_s(buffer, 10, bstr.c_str());    //string.c_str() 返回 C 字符串
	cout << buffer << endl;

	/* string 查找 */
	int n = str3.find('l', 0);
	cout << str3 << endl;
	cout << n << endl;

	/* 测试 string 减号运算符重载 */
	string test1 = "abcdefgh";
	string test2 = "cde";
	string test3 = test1 - test2;
	cout << test3 << endl;
	
	/*
	    C++ 之父建议
		1.不需要使用宏
		2.需要变量时再声明,立即初始化
		3.不使用 malloc,改用 new
		4.避免使用强制转换
		5.避免使用数组与 C 字符串,改用 string 和 vector
	*/

	/* 删除字符串头尾空格 */
	string deletee = "   abcde    ";
	cout << deletee << "*" << endl;
	deletee.erase(0, deletee.find_first_not_of(' '));
	cout << deletee << "*" << endl;
	deletee.erase(deletee.find_last_not_of(' '));
	cout << deletee << "*" << endl;


	return 0;
}

string operator- (string a, string b)
{
	string ans;

	if (a.find(b) == -1)    //如果无法相减,则不相减
		return a;

	bool flag = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b[0])
		{
			flag = true;    //判断器置 true
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i + j] != b[j])
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				i += (b.size() - 1);
		}
		else
			ans += a[i];
	}

	return ans;
}
