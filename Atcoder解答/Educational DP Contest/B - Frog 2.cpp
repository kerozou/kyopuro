#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ


//  今回は前回の　A.frog1　と違い　K回ほどchminを回さなければいけないので、
//  rep内にforを置いて対応。
//  この時、貰うDPでは、DP[K-1]まであらかじめ初期化しておかなければならなくなるので、配るDPでやるのが最適。
//  実際、広めにhとDPを取っておけば、i > N に関してはDPがめちゃくちゃな値になっても答えに影響が出ないのでおｋ。

//  計算量は各ノードにつき高々 K 通りの遷移があるので、O(NK)

int main(){
    //input
    int N,K;cin >> N >> K;
    const LL inf = 1LL << 60;
    vector<LL> h(N+101);
    rep(i,N)cin >> h[i];

    //DP_stand
    vector<LL> DP(N+101,inf);
    DP[0] = 0;

    rep(i,N) for(int j = 1;j <= K;j++){
        chmin(DP[i+j],DP[i] + abs(h[i] - h[i+j]));
    }

    cout << DP[N-1] << endl;
}