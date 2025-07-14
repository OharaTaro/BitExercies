#include <iostream>

// �r�b�g���Z���g�p������ԃA���S���Y��
// �o����K�v�͂Ȃ����\�[�X������
// ��������A���S���Y���Ȃ̂������؂��鎞�Ԃ�
// �ߖ񂷂邽�ߒm���Ƃ��Ď����Ă���

// XOR�����A���S���Y��
// x,y�̎Q�Ɛ�̐��l�����ւ���
void XorSwap(int* x, int* y)
{
	if (x && y)	// nullptr���͂���
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

// �r�b�g�J�E���g
// �����Ă���r�b�g�̐��𐔂���
// ������m�肽���l�͒��ׂ悤
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

	// test0 �� test1 �̒��g�����ւ���
	XorSwap(&test0, &test1);
	std::cout << "test0:" << test0 << std::endl;
	std::cout << "test1:" << test1 << std::endl;

	// ��32�̃r�b�g�������Ă���
	test0 = 0xffffffff;		// 1111 1111 1111 1111 1111 1111 1111 1111
	std::cout << "test0 BitCount:" << BitCount(test0) << std::endl;

	// ��13�̃r�b�g�������Ă���
	test0 = 0xf0123456;		// 1111 0000 0001 0010 0011 0100 0101 0110
	std::cout << "test0 BitCount:" << BitCount(test0) << std::endl;

	// ��0�̃r�b�g�������Ă���
	test0 = 0x00000000;		// 0000 0000 0000 0000 0000 0000 0000 0000
	std::cout << "test0 BitCount:" << BitCount(test0) << std::endl;

	return 0;
}