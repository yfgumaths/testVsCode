#ifndef __TEST__TEMPLATE__H__
#define  __TEST__TEMPLATE__H__
#include <iostream>
using namespace std;

template<typename T1>
void TOutput_E(T1 a)
{
	TOutput(a);
	cout << endl;
};

template<typename T1>
void TOutput(T1 a)
{
	cout << a;
};

template <typename T1, typename T2>
void TOutput_E(T1 a, T2 b)
{
	TOutput(a, b);
	cout << endl;
};

template <typename T1, typename T2>
void TOutput(T1 a, T2 b)
{
	cout << a << " " << b;
};

template <typename T1, typename T2, typename T3>
void TOutput_E(T1 a, T2 b, T3 c)
{
	TOutput(a, b, c);
	cout << endl;
};

template <typename T1, typename T2, typename T3>
void TOutput(T1 a, T2 b, T3 c)
{
	cout << a << " " << b << " " << c;
};

template <typename T1, typename T2, typename T3, typename T4>
void TOutput_E(T1 a, T2 b, T3 c, T4 d)
{
	TOutput(a, b, c, d);
	cout << endl;
};

template <typename T1, typename T2, typename T3, typename T4>
void TOutput(T1 a, T2 b, T3 c, T4 d)
{
	cout << a << " " << b << " " << c << " " << d;
};

template <typename T1>
void TOutputHex(T1& data)
{
	int nFlag[70];
	int nSize = 0;
	memset(nFlag, 0, sizeof(nFlag));
	int nowData = data;
	while (nowData > 0)
	{
		nFlag[nSize++] = nowData % 2;
		nowData /= 2;
	}
	cout << "OutputHex " << data << " = ";
	for (int i = nSize - 1; i >= 0; i--)
	{
		cout << nFlag[i];
	}
};

template <typename T1>
void TOutputHex_E(T1& a)
{
	TOutputHex(a);
	cout << endl;
}

#endif // !__TEST__TEMPLATE__H__

