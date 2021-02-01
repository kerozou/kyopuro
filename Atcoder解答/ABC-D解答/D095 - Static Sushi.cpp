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
    LL N,C;cin >> N >> C;
    vector<LL> x(N);
    vector<LL> v(N);
    rep(i,N)cin >> x[i] >> v[i];

    vector<LL> a(N);
    vector<LL> b(N);
    vector<LL> DPa(N);
    vector<LL> DPb(N);
    vector<LL> rui(N);
    vector<LL> Rrui(N);
    rep(i,N){
        if(i == 0){
            rui[0] = v[i];
            Rrui[N-1] = v[N-1];
            continue;
        }
        rui[i] = rui[i-1] + v[i];
        Rrui[N-1-i] = Rrui[N-i] + v[N-1-i];
    }


    rep(i,N){
        a[i] = rui[i] - 2*x[i];
        b[i] = Rrui[i] - (C - x[i]);
        DPa[i] = a[i];
        DPb[i] = b[i];
    }
    for(int i = 1;i <= N-1;++i)chmax(DPa[i],DPa[i-1]);            // i番目までの時計回りのスコアの最大値
    for(int i = N-2;i >= 0;--i)chmax(DPb[i],DPb[i+1]);  // i番目以降の反時計回りのスコアの最大値

    LL ans_1 = 0;
    rep(i,N){
        if(i != N-1)chmax(ans_1,DPa[i] + DPb[i+1]);           // 時計と反時計のDP同士の和のmax
        else chmax(ans_1,DPa[i]);
    }
    rep(i,N)chmax(ans_1,rui[i]-x[i]);                     // 時計回りで片道だけ
    rep(i,N)chmax(ans_1,Rrui[i]-(C-x[i]));            // 反時計周りで片道だけ       これらはどっちか片っぽやっとけばいいぞ
    



///// ここから反時計


    vector<LL> c(N);
    vector<LL> d(N);
    vector<LL> DPc(N);
    vector<LL> DPd(N);
    rep(i,N){
        c[i] = rui[i] - x[i];
        d[i] = Rrui[i] - 2*(C - x[i]);
        DPc[i] = c[i];
        DPd[i] = d[i];
    }
    for(int i = 1;i <= N-1;++i)chmax(DPc[i],DPc[i-1]);
    for(int i = N-2;i >= 0;--i)chmax(DPd[i],DPd[i+1]);

    LL ans_2 = 0;
    rep(i,N){
        if(i != 0)chmax(ans_2,DPc[i-1] + DPd[i]);
        else chmax(ans_2,DPd[i]);
    }
    LL ans = max(ans_1,ans_2);
    cout << ans << endl;

}

