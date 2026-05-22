#include <iostream>

// Piece02

// Piece00が解けている前提での問題なので解いてから行うこと
// Piece00で行った修正を行っていない状態で例を示すので
// 修正後のPiece00等に追記する等の形で対応するのをおすすめする

namespace
{
	// ピースの大きさ
	constexpr int kSize = 4;
	// ピースの配置情報
	constexpr bool kPiece00[kSize][kSize] =
	{
		{ false, false, false, false },
		{ false, true , false, false },
		{ false, true , true , false },
		{ false, false, false, false },
	};

	constexpr bool kPiece01[kSize][kSize] =
	{
		{ false, true , true , true  },
		{ false, false, false, true  },
		{ false, false, false, true  },
		{ false, false, false, false },
	};
}

int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////
	// 前置き
	///////////////////////////////////////////////////////////////////////////////////////////

	// 例によってビット演算への変更前のソースコードを示す
	// 何をやっているかの確認が終わったら
	// 過去の流用でかまわないのでビット演算を使用した形に変更してから作業する

	///////////////////////////////////////////////////////////////////////////////////////////
	// ここからが課題
	///////////////////////////////////////////////////////////////////////////////////////////
	
	// ピースを2つ用意した
	
	// 2つのピースを比較して同じ場所にピースが置かれていれば
	// ピースを重ねることができない旨表示を行う
	// 同じ場所に置かれているピースがなければ2つのピースを重ねた形状を表示する

	// 配列でデータを持つと重なっているかどうかの判定は
	// 4 * 4 = (最大)16回チェックが必要だが
	// ビット演算を使用すれば1回のビット演算で判定を行うことができる
	// ビット演算を使用した重なり判定に修正せよ

	// また重ねたピースの作成もビット演算1回で可能である
	// ビット演算を使用して重ねたピースの情報を生成せよ

	// ※ピースの形状を変更して重ねられる/重ねられないパターンを検証すること

	// ピースの形状を表示
	std::cout << "1つ目のピース" << std::endl;
	for (int y = 0; y < kSize; y++)
	{
		for (int x = 0; x < kSize; x++)
		{
			if (kPiece00[y][x])	{ std::cout << "■"; }
			else				{ std::cout << "□"; }
		}
		std::cout << std::endl;
	}
	std::cout << "2つ目のピース" << std::endl;
	for (int y = 0; y < kSize; y++)
	{
		for (int x = 0; x < kSize; x++)
		{
			if (kPiece01[y][x]) { std::cout << "■"; }
			else { std::cout << "□"; }
		}
		std::cout << std::endl;
	}

	// 2つのピースで同じ場所に置かれているピースがないかを判定する
	bool isOverlap = false;
	for (int y = 0; y < kSize; y++)
	{
		for (int x = 0; x < kSize; x++)
		{
			if (kPiece00[y][x] && kPiece01[y][x])
			{
				isOverlap = true;
				break;
			}
		}
		if (isOverlap)	break;
	}

	if(isOverlap)
	{
		std::cout << "ピースを重ねることができません" << std::endl;
	}
	else
	{
		// 重ねたピースの情報を生成
		bool pieceResult[kSize][kSize];
		for (int y = 0; y < kSize; y++)
		{
			for (int x = 0; x < kSize; x++)
			{
				pieceResult[y][x] = kPiece00[y][x] || kPiece01[y][x];
			}
		}
		std::cout << "重ねた！" << std::endl;
		for (int y = 0; y < kSize; y++)
		{
			for (int x = 0; x < kSize; x++)
			{
				if (pieceResult[y][x]) { std::cout << "■"; }
				else { std::cout << "□"; }
			}
			std::cout << std::endl;
		}
	}

	return 0;
}