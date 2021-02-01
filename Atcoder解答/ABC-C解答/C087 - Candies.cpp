#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    // 入力
    int N;cin >> N;
    vector<int> A(N),B(N);
    rep(i,N)cin >> A[i];        //見やすさのため上段と下段でわける。
    rep(i,N)cin >> B[i];

    vector<int> sum_A(N),sum_B(N);
    rep(i,N){                   //左累積和
        if(i == 0)sum_A[0] = A[0];
        else sum_A[i] = sum_A[i-1] + A[i];
    }                           //右累積和
    for(int i = N-1;i>=0;i--){
        if(i == N-1)sum_B[N-1] = B[N-1];
        else sum_B[i] = sum_B[i+1] + B[i];
    }

    int ans = 0;
    rep(i,N) ans = max(ans,sum_A[i]+sum_B[i]);      //答え
    cout << ans << endl;
}

// ABC087 C - Candies
// ・左からi番目で一度下に移動するというところがポイントで、上段はそれ以前を、下段はそれ以降を掃くことがわかる。

// つまり、上と下で左累積和と右累積和を作ればよい。
// i番目も含めて作り、rep(i,N) ans = max(ans,L[i]+R[i]);　で終わり。
// このとき、ans = 0　で初期化しておかないとメモリ読んだりしてえらいことになるから注意。
// また、この解はN==1とかの場合もいける。