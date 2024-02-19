#include <iostream>

// 問題文はmain()内にあるので参照すること
// BitExercies00が解けている前提での問題なので解いてから行うこと


namespace
{
	// 新たに追加した定義
	constexpr int kPartyNum = 4;

	////////////////////////////////////////////////////////////
	// 以下の定義ははBitExercies00と共通
	////////////////////////////////////////////////////////////

	// 状態異常
	enum Status
	{
		kStatusPoizon,	// 毒
		kStatusSleep,	// 睡眠
		kStatusBurn,	// やけど
		kStatusStone,	// 石化

		kStatusOther0,	// その他	ステータス異常の数を8個にしたいので適当に名前付け
		kStatusOther1,	// その他
		kStatusOther2,	// その他
		kStatusOther3,	// その他

		kStatusNum
	};

	const char* const kStatusName[] =
	{
		"毒",
		"睡眠",
		"やけど",
		"石化",
		"その他0",
		"その他1",
		"その他2",
		"その他3",
	};
	static_assert(_countof(kStatusName) == kStatusNum);
}

// 課題1	指定した番号のプレイヤーに状態異常をかける
// status:		フラグを設定する変数
// no:			状態異常にかかるプレイヤーの番号を指定する
// addStatus:	かかる状態異常の種類を指定する
void setStatus(uint32_t& status, int no, Status addStatus)
{

}

// 課題2	指定したプレイヤーの状態異常を全て表示する
// status:		フラグが設定された変数
// no:			状態異常の内容を表示する人
void dispStatus(uint32_t status, int no)
{
	std::cout << no << "番めの人の状態異常" << std::endl;
	// 以下に指定された番号の人の状態異常をすべて表示する
	
}

int main()
{
	// BitExercies00ではプレイヤー一人分のステータス異常を
	// 1バイトの変数一つで表現した

	// 今回は4人パーティーの状態異常を一つの変数で管理したい
	// 状態異常の数8種類*4人の合計32ビット(4バイト)で管理可能なはずである


	// 4バイトの変数を用意した
	// この変数1つで4人分の状態異常を管理できるよう以下の課題にある実装を行え
	// 今回の課題では必要に応じて定数の定義を追加しても構わない(追加しなくてもよい)
	uint32_t status = 0;	// 全員ステータス異常なしで初期化

	// 課題1.setStatus関数の中身を実装せよ
	// 引数の仕様は関数定義部分にある
	setStatus(status, 0, kStatusBurn);	// 0番目の人をやけどに
	setStatus(status, 1, kStatusSleep);	// 1番目の人を睡眠に
		// 2番目は飛ばして
	setStatus(status, 3, kStatusPoizon);	// 3番目の人を毒、
	setStatus(status, 3, kStatusOther2);	// その他2に

	// 課題2.dispStatus関数の中身を実装せよ
	// 引数の仕様は関数定義部分にある
	for (int i = 0; i < kPartyNum; i++)
	{
		dispStatus(status, i);
	}

	return 0;
}