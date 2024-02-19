#include <iostream>

// ��蕶��main()���ɂ���̂ŎQ�Ƃ��邱��

namespace
{
	// ��Ԉُ�
	enum Status
	{
		kStatusPoizon,	// ��
		kStatusSleep,	// ����
		kStatusBurn,	// �₯��
		kStatusStone,	// �Ή�

		kStatusOther0,	// ���̑�	�X�e�[�^�X�ُ�̐���8�ɂ������̂œK���ɖ��O�t��
		kStatusOther1,	// ���̑�
		kStatusOther2,	// ���̑�
		kStatusOther3,	// ���̑�

		kStatusNum
	};

	const char* const kStatusName[] =
	{
		"��",
		"����",
		"�₯��",
		"�Ή�",
		"���̑�0",
		"���̑�1",
		"���̑�2",
		"���̑�3",
	};
	static_assert(_countof(kStatusName) == kStatusNum);
}


int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////
	// �O�u��
	///////////////////////////////////////////////////////////////////////////////////////////

	// �v���C���[�̃X�e�[�^�X�ُ���Ǘ�������
	// ���݁A�X�e�[�^�X�ُ�̎�ނ��Ƃ�bool�^�Ńf�[�^�������߁A
	// bool�^1Byte * 8��ނ̃X�e�[�^�X�ُ�ō��v8�o�C�g�̃f�[�^��K�v�Ƃ��Ă���
	bool isStatus[kStatusNum];
	std::cout << "�ύX�O ���v" << sizeof(isStatus) << "�o�C�g" << std::endl;	// �X�e�[�^�X�ُ�̊Ǘ��ɕK�v�ȃo�C�g����\��
	for (int i = 0; i < kStatusNum; i++)	// ��Ԉُ�Ȃ��̏�Ԃŏ�����
	{
		isStatus[i] = false;
	}
	isStatus[kStatusStone] = true;	// �Ή��̃t���O��ON�ɂ���
	isStatus[kStatusOther2] = true;	// ���̑�2�̃t���O��ON�ɂ���
	for (int i = 0; i < kStatusNum; i++)
	{
		if (isStatus[i])
		{
			std::cout << "�v���C���[��" << kStatusName[i] << "���Ă��܂��B" << std::endl;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////
	// �������炪�ۑ�
	///////////////////////////////////////////////////////////////////////////////////////////

	// ���A���ꂼ��̃X�e�[�^�X�ُ�͂������Ă���A�������Ă��Ȃ��A��2�̏�Ԃ������݂����A
	// ���ꂼ��1�r�b�g�ŕ\���\�Ȃ̂ŗ��_��8�r�b�g(1�o�C�g)�ŊǗ��\�Ȃ͂��ł���

	// 1�o�C�g�̕ϐ���p�ӂ���
	// ���̕ϐ����g�p���ăv���C���[�̃X�e�[�^�X���Ǘ��ł���悤�������s��
	// �������萔�̒�`��ǉ����邱�Ƃ͋֎~����(�������}�W�b�N�i���o�[���s��)
	uint8_t status = 0;	// ��Ԉُ�Ȃ��ŏ�����
	std::cout << "�ύX�� ���v" << sizeof(status) << "�o�C�g" << std::endl;	// �X�e�[�^�X�ُ�̊Ǘ��ɕK�v�ȃo�C�g����\��

	// �������ȉ����L�q

	// �v���C���[�����̏�Ԉُ�ɂ���


	// �v���C���[����Ԉُ�ɂȂ��Ă����炻�̓��e��\������
	for (int i = 0; i < kStatusNum; i++)
	{
		if (false)	// �X�e�[�^�X�ُ�ɂ������Ă��邩���`�F�b�N����
		{
			std::cout << "�v���C���[��" << kStatusName[i] << "���Ă��܂��B" << std::endl;
		}
	}

	return 0;
}