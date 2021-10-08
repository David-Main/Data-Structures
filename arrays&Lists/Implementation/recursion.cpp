#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int fib(int n)
{
	if(0 == n) return 1;
	else if(1 == n) return 0;
	else
	{
		return (fib(n-1) + fib(n-2));
	}
}

size_t fibn(int n)
{
	if(1 == n) return 0;
	if(2 == n) return 1;

	size_t c, a = 0, b = 1;
	for(int i = 0; i < n-2; ++i)
	{
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

size_t fact(int n)
{
	if(0 == n ) return 1;
	else 
		return fact(n-1) * n;
}

int main()
{
	// int n = 195;

	// int length = to_string(n).length();

	// for (int i = 1; i <= n; ++i)
	// {
	// 	cout << setw(length * length * int(log(n))) << fibn(i) ;
	// }

	cout << fact(5);
}