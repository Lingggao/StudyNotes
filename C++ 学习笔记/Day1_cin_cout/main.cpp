#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float a = 123.45678999;
	printf("%.3f\n", a);
	printf("%f\n", a);
	cout << setiosflags(ios::left) << setfill('*') << setw(15) << a << endl;
	cout << setiosflags(ios::right) << setw(15) << a << endl;
	cout << setprecision(6) << setiosflags(ios::fixed) << a << endl;
	cout << oct << 123 << endl;
	return 0;
}