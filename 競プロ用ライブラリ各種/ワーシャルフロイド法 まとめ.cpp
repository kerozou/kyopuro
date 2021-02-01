//  ワーシャルフロイド法 まとめ

//  最短経路問題で使われるアルゴリズムの１つ。負の閉路がない限り、負の辺があっても使える。
//  グラフ上の全ての頂点間の最短経路を探すので、計算量はO(V^3)となる。

//　まずはワーシャルフロイド法のコードを見てみる。

void WF(int n,vector<vector<LL>> &d) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

/*
    上記がC++によるワーシャルフロイド法の実装だ。グラフの表現は隣接行列。
    配列d[a][b]には頂点a,b間の辺のコストを入れておき、a=bの時は０を、a,b間の辺が存在しないときはINFを入れておく。
    アルゴリズムとしては、頂点iから頂点jへの経路と、頂点kを経由した場合の経路とを比較してよりコストの合計が小さい方を配列に入れる動的計画法を使っている。
*/

// https://qiita.com/okaryo/items/8e6cd73f8a676b7a5d75 参考

// V <= 200　くらいまでいける