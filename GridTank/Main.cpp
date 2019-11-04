
# include <Siv3D.hpp> // OpenSiv3D v0.4.1

class Field
{
public:
	Field()
	{
		_field = Grid<int>(10, 10);
	}

	void Draw(int size, Size offset)
	{
		for (auto y : step(_field.height()))
		{
			for (auto x : step(_field.width()))
			{
				Rect(x * size, y * size, size).movedBy(offset).drawFrame();
			}
		}
	}

private:
	Grid<int> _field;
};

void Main()
{
	Field field;

	while (System::Update())
	{
		field.Draw(50, { 10, 10 });
	}
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D Slack (ユーザコミュニティ) への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
