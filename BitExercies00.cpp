#include <iostream>

// 問題文はmain()内にあるので参照すること

namespace
{
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


int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////
	// 前置き
	///////////////////////////////////////////////////////////////////////////////////////////

	// プレイヤーのステータス異常を管理したい
	// 現在、ステータス異常の種類ごとにbool型でデータを持つため、
	// bool型1Byte * 8種類のステータス異常で合計8バイトのデータを必要としている
	bool isStatus[kStatusNum];
	std::cout << "変更前 合計" << sizeof(isStatus) << "バイト" << std::endl;	// ステータス異常の管理に必要なバイト数を表示
	for (int i = 0; i < kStatusNum; i++)	// 状態異常なしの状態で初期化
	{
		isStatus[i] = false;
	}
	isStatus[kStatusStone] = true;	// 石化のフラグをONにする
	isStatus[kStatusOther2] = true;	// その他2のフラグをONにする
	for (int i = 0; i < kStatusNum; i++)
	{
		if (isStatus[i])
		{
			std::cout << "プレイヤーは" << kStatusName[i] << "しています。" << std::endl;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////
	// ここからが課題
	///////////////////////////////////////////////////////////////////////////////////////////

	// が、それぞれのステータス異常はかかっている、かかっていない、の2つの状態しか存在せず、
	// それぞれ1ビットで表現可能なので理論上8ビット(1バイト)で管理可能なはずである

	// 1バイトの変数を用意した
	// この変数を使用してプレイヤーのステータスを管理できるよう実装を行え
	// ただし定数の定義を追加することは禁止する(もちろんマジックナンバーも不可)
	uint8_t status = 0;	// 状態異常なしで初期化
	std::cout << "変更後 合計" << sizeof(status) << "バイト" << std::endl;	// ステータス異常の管理に必要なバイト数を表示

	// ↓ここ以下を記述

	// プレイヤーを特定の状態異常にする


	// プレイヤーが状態異常になっていたらその内容を表示する
	for (int i = 0; i < kStatusNum; i++)
	{
		if (false)	// ステータス異常にかかっているかをチェックする
		{
			std::cout << "プレイヤーは" << kStatusName[i] << "しています。" << std::endl;
		}
	}

	return 0;
}