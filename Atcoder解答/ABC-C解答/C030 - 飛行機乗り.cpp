#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N,M;cin >> N >> M;
    LL X,Y;cin >> X >> Y;

    vector<LL> a(N);
    vector<LL> b(M);
    rep(i,N)cin >> a[i];
    rep(i,M)cin >> b[i];

    int now = 0;
    int ct = 0;
    bool AtoB = true;
    LL tmp = -1;
    while(true){
        if(AtoB){
            if(now > N-1)break;
            tmp = a[now] + X;
            now = lower_bound(all(b), tmp) - b.begin();
            AtoB = false;
        }
        else{
            if(now > M-1)break;
            tmp = b[now] + Y;
            now = lower_bound(all(a), tmp) - a.begin();
            ct++;
            AtoB = true;
        }
    }   

    cout << ct << endl;
}

// ABC030 	C - 飛行機乗り

/*
    基本的に現在から一番早いタイミングで乗れるものに乗っていくのが最適解。
    なぜなら、飛行機に乗っている時間はどの便も変わらないため。
    これが可変式だと厄介。

    なので、whileループ内のように、現在から最も近い便番号を控えて、二分探索で次の便を調べていく。
    Bから帰ってこれたら　+1　する。
    あとは、現在の便番号がNとMからはみ出したら終わり。
*/