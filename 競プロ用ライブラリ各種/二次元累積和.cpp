#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力: H × W のグリッド
    int H, W; cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];

    // 二次元累積和
    vector<vector<int> > s(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }
}   



// 二次元累積和については
// http://tutuz.hateblo.jp/entry/2018/08/19/064525
// https://qiita.com/drken/items/56a6b68edef8fc605821#4-%E4%BA%8C%E6%AC%A1%E5%85%83%E7%B4%AF%E7%A9%8D%E5%92%8C
// を参照。

// 上の [ ) の関係から、x2,y2は一個大きく用意しておく必要あるかも。