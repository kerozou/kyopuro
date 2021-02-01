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
    LL N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    vector<LL> rui(N+1);
    rui[0] = 0;
    rep(i,N)rui[i+1] = rui[i] + A[i];

    LL ans = INF;

    for(int i = 2;i <= N-2;i++){
        LL ub = i;
        LL lb = 1;
        while(ub - lb > 1){
            LL mid = (ub+lb)/2;
            if(rui[mid] > rui[i] - rui[mid])ub = mid;
            else lb = mid;
        }
        LL p1 = rui[ub]; 
        LL p2 = rui[i] - rui[ub];
        LL q1 = rui[lb];
        LL q2 = rui[i] - rui[lb];
        LL left_min = min(q1,q2);
        LL left_max = max(q1,q2);
        if(abs(p1-p2) < abs(q1-q2)){
            left_min = min(p1,p2);
            left_max = max(p1,p2);
        }

        ub = N;
        lb = i;
        while(ub - lb > 1){
            LL mid = (ub+lb)/2;
            if(rui[mid] - rui[i] > rui[N] - rui[mid])ub = mid;
            else lb = mid;
        }
        LL p3 = rui[lb] - rui[i];
        LL p4 = rui[N] - rui[lb];
        LL q3 = rui[ub] - rui[i];
        LL q4 = rui[N] - rui[ub];
        LL right_min = min(q3,q4);
        LL right_max = max(q3,q4);
        if(abs(p3-p4) < abs(q3-q4)){
            right_min = min(p3,p4);
            right_max = max(p3,p4);
        }

        LL tmp1 = min(right_min,left_min);
        LL tmp2 = max(right_max,left_max);
        LL tmp = abs(tmp1-tmp2);
        ans = min(ans,tmp);

    }
    cout << ans << endl;
}

// ARC100 D - Equal Cut

/*
    P,Q,R,Sを分かつ3か所を全探索するとオーダーは10^16位になってしまう。
    なので、どれか一点を固定して残りの二つを見つけ出す必要がある。
    
    A[i] > 0 なので、累積和は単調増加になり二分探索や尺取り法が使える。
    今回は二分探索でといた。

    数字と数字の間の数と認識して、P,Q　と R,S の間をiとして固定していく。
    4つの塊の和の絶対値の最小を見つけたいので、P,Q と R,S　はそれぞれほぼ同じ数になるはず。
    なので、P < Q　を満たす境界とR < S を満たす境界を二分探索で探す。
    この時、累積和が単調増加とはいえ ub と lb は一個ずれなのでどちらを採用したかによって P,Q の値が若干ずれる。
    しかし、単調増加であるがゆえに P,Q の候補はub,lbのどちらかでカットした時の2種類のペアに絞れる。
    そこで、ub,lb　どちらの場合でもP,Qを生成してみて判断する。

    以上の手続きをR,Sについても行い、最後に集計してみて最小になったものをansにとればいい。
*/