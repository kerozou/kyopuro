#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N,W;cin >> N >> W;
    vector<LL> w(N);
    vector<LL> v(N);
    rep(i,N)cin >> w[i] >> v[i];
    LL dp[110][111111] = {0};           // なんか添え字の番号を変数で読み込ませたらばぐった。静的配列は実数地でないとだめ？

    rep(i,N){   // 何個目のアイテムまで選択済みにしたかのループ
        for(int sum_w = 0;sum_w <= W;sum_w++){  // 容量の上限をインクリメントしていくループ
            
            if(sum_w - w[i] >= 0){  //i番目を入れるとき
                chmax(dp[i+1][sum_w],dp[i][sum_w - w[i]] + v[i]);
            }

            chmax(dp[i+1][sum_w],dp[i][sum_w]); //i番目を入れないとき
        }
    }

    // 上のループによって、縦軸がアイテムの2^Ω、横軸が各タイミングの容量限界、というような高々　N*M(*2)　のループが完成。
    // これをDPテーブルとする。

    LL ans = dp[N][W];  // i = 0 はそもそもアイテムが無く虚無なので、N-1　ではなく、Nになる。
    cout << ans << endl;
}

