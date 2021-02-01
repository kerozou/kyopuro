#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M; cin >> N >> M;

	vector<vector<int>> vec(M);

	for (int i = 0; i < M; ++i) {
		int k; cin >> k;
		vec[i].resize(k); //電球のサイズに作り直す
		for (int j = 0; j < k; ++j) {
			cin >> vec[i][j];
			--vec[i][j]; //後ろの[]に電球とつながるスイッチのリストがはいってる
		}
	}

	vector<int> p(M);
	for (int i = 0; i < M; ++i) cin >> p[i]; //ここまで入力
    //vecに電球とスイッチの配列
    //pはbool


	int ans = 0;
	for (int i = 0; i < (1 << N); ++i) { //2^Nのループ スイッチのON/OFFの形で固定して2^Nパターンまわすということ
		bool ok = true;
		for (int j = 0; j < M; ++j) { //電球の数ループ
			int c = 0;
			for (int id : vec[j]) {  //範囲for文 電球ごとのスイッチリストを回してるはずvec[][]の後ろの[]内を順番に
				if ((i >> id) & 1) { //iは全パターンの数字なので、1000101001とかをidだけ右にずらしたときの1桁目が1と一致
					++c;             //そんで、idはforで取得。vecの中身がスイッチの番号なので、iの右からid番目の桁、つまりi番目のスイッチのフラグをチェックしてる。
				}
			}
			c %= 2;
			if (c != p[j]) {
				ok = false;
			}
		}
		if (ok) {
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}
