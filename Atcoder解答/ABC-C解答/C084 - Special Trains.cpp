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
    int N;cin >> N;
    vector<LL> C(N-1);
    vector<LL> S(N-1);
    vector<LL> F(N-1);
    rep(i,N-1)cin >> C[i] >> S[i] >> F[i];
    vector<LL> ans(N,0);
    LL t;
    rep(i,N-1){
        t = S[i];
        for(int j = i;j<N-1;j++){
            if(t >= S[j]){
                if((t-S[j]) % F[j] == 0){
                    t += C[j];
                }
                else{
                    t += F[j] - (t % F[j]) + C[j];
                }
            }
            else{
                t = S[j] + C[j];
            }
        }
        ans[i] = t;
    }

    rep(i,N)cout << ans[i] << endl;
}

// ABC084 C - Special Trains
// ・始発Sと次のタイミングFと現在時刻tによってのみ、電車の乗り方が変わるので、O(N^2)で楽勝で間に合うので適当に計算するだけ。

// 各駅スタート時は t = S[i] であり、基本はこれにC[j]を足していけばいいのだが、電車がないタイミングでついてしまったときは現在時刻ｔに次の発車時刻までの端数を足して出発。
// また、始発前についてしまったら始発まで待つ。