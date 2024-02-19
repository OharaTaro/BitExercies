#include <iostream>

// ��蕶��main()���ɂ���̂ŎQ�Ƃ��邱��
// BitExercies00�������Ă���O��ł̖��Ȃ̂ŉ����Ă���s������


namespace
{
	// �V���ɒǉ�������`
	constexpr int kPartyNum = 4;

	////////////////////////////////////////////////////////////
	// �ȉ��̒�`�͂�BitExercies00�Ƌ���
	////////////////////////////////////////////////////////////

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

// �ۑ�1	�w�肵���ԍ��̃v���C���[�ɏ�Ԉُ��������
// status:		�t���O��ݒ肷��ϐ�
// no:			��Ԉُ�ɂ�����v���C���[�̔ԍ����w�肷��
// addStatus:	�������Ԉُ�̎�ނ��w�肷��
void setStatus(uint32_t& status, int no, Status addStatus)
{

}

// �ۑ�2	�w�肵���v���C���[�̏�Ԉُ��S�ĕ\������
// status:		�t���O���ݒ肳�ꂽ�ϐ�
// no:			��Ԉُ�̓��e��\������l
void dispStatus(uint32_t status, int no)
{
	std::cout << no << "�Ԃ߂̐l�̏�Ԉُ�" << std::endl;
	// �ȉ��Ɏw�肳�ꂽ�ԍ��̐l�̏�Ԉُ�����ׂĕ\������
	
}

int main()
{
	// BitExercies00�ł̓v���C���[��l���̃X�e�[�^�X�ُ��
	// 1�o�C�g�̕ϐ���ŕ\������

	// �����4�l�p�[�e�B�[�̏�Ԉُ����̕ϐ��ŊǗ�������
	// ��Ԉُ�̐�8���*4�l�̍��v32�r�b�g(4�o�C�g)�ŊǗ��\�Ȃ͂��ł���


	// 4�o�C�g�̕ϐ���p�ӂ���
	// ���̕ϐ�1��4�l���̏�Ԉُ���Ǘ��ł���悤�ȉ��̉ۑ�ɂ���������s��
	// ����̉ۑ�ł͕K�v�ɉ����Ē萔�̒�`��ǉ����Ă��\��Ȃ�(�ǉ����Ȃ��Ă��悢)
	uint32_t status = 0;	// �S���X�e�[�^�X�ُ�Ȃ��ŏ�����

	// �ۑ�1.setStatus�֐��̒��g����������
	// �����̎d�l�͊֐���`�����ɂ���
	setStatus(status, 0, kStatusBurn);	// 0�Ԗڂ̐l���₯�ǂ�
	setStatus(status, 1, kStatusSleep);	// 1�Ԗڂ̐l�𐇖���
		// 2�Ԗڂ͔�΂���
	setStatus(status, 3, kStatusPoizon);	// 3�Ԗڂ̐l��ŁA
	setStatus(status, 3, kStatusOther2);	// ���̑�2��

	// �ۑ�2.dispStatus�֐��̒��g����������
	// �����̎d�l�͊֐���`�����ɂ���
	for (int i = 0; i < kPartyNum; i++)
	{
		dispStatus(status, i);
	}

	return 0;
}