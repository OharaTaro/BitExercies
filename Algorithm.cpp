#include <iostream>

// ビット演算を使用した定番アルゴリズム
// 覚える必要はないがソースを見て
// 何をするアルゴリズムなのかを検証する時間を
// 節約するため知識として持っておく

// XOR交換アルゴリズム
// x,yの参照先の数値を入れ替える
void XorSwap(int* x, int* y)
{
	if (x && y)	// nullptrをはじく
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

// ビットカウント
// 立っているビットの数を数える
// 理屈を知りたい人は調べよう
int BitCount(int n)
{
	n = (n & 0x55555555) + (n >> 1 & 0x55555555);
	n = (n & 0x33333333) + (n >> 2 & 0x33333333);
	n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
	n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
	return n;
}

int main(void)
{
	int test0 = 123;
	int test1 = 456;

	// test0 と test1 の中身を入れ替える
	XorSwap(&test0, &test1);
	std::cout << "test0:" << test0 << std::endl;
	std::cout << "test1:" << test1 << std::endl;

	// ↓32個のビットが立っている
	test0 = 0xffffffff;		// 1111 1111 1111 1111 1111 1111 1111 1111
	std::cout << "test0 BitCount:" << BitCount(test0) << std::endl;

	// ↓13個のビットが立っている
	test0 = 0xf0123456;		// 1111 0000 0001 0010 0011 0100 0101 0110
	std::cout << "test0 BitCount:" << BitCount(test0) << std::endl;

	// ↓0個のビットが立っている
	test0 = 0x00000000;		// 0000 0000 0000 0000 0000 0000 0000 0000
	std::cout << "test0 BitCount:" << BitCount(test0) << std::endl;

	return 0;
}