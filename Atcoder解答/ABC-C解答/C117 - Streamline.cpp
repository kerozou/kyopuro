#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート

// Answer 方針
// 0.N < M の場合だけ考える。N >= M の時は操作しないでも終わってるので０でいい。
// 1.X[]をソート
// 2.L[i] = X[i+1] - X[i] とする。これは、各ポイント間の距離
// 3.L[]を降順でソートし、大きいほうからN-1個入手して加算
// 4.X[M-1] - X[0] - Lsum これで全体の長さから、移動しなくても良い隙間の合計を引いたことになる。

// 以上で、結論が出る

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> X(M);

    if(N >= M){
        cout << 0 << endl;
    }
    else {
    rep(i,M){
        cin >> X[i];
    }

    sort(all(X));


    vector<int> L(M);

    rep(j,M-1){
        L[j] = abs(X[j+1] - X[j]);
    }

    sort(rall(L));

    int sum = 0;
    rep(k,N-1){
        sum += L[k];
    }
    int temp = X[M-1] - X[0];
    cout << temp - sum << endl;
    }

}
// 20190528 AC
