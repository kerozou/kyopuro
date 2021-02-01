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
    int N;cin >> N;
    vector<LL> A(N);rep(i,N)cin >> A[i];
    sort(all(A));
    
    vector<LL> ct(N);
    vector<LL> ctr(N);
    LL tmp = 1;
    rep(i,N){
        if(i == 0){
            ct[0] = 1;
            tmp *= (-1);
        }
        else if(i == N-1){
            ct[N-1] = tmp;
        }
        else{
            ct[i] = 2*tmp;
            tmp *= -1;
        }
    }
    rep(i,N){
        ctr[i] = ct[i]*(-1);
    }
    sort(all(ct));
    sort(all(ctr));

    LL ans1 = 0;
    LL ans2 = 0;
    rep(i,N){
        ans1 += (ct[i]*A[i]);
        ans2 += (ctr[i]*A[i]);
    }

    LL ans = max(ans1,ans2);
    cout << ans << endl;
 
}

// Tenka1 Programmer Beginner Contest C - Align

/*
    editorial通りに解いた。
    解説が頭良すぎ。
    p1 < p2 < p3 となる並びや、 p1 > p2 > p3 となる並びに意味がないことに気づくところが本質。
    この問題からは「間の数字を一つ取り除いても結果が変わらない場合」を見つけることの大切さを学びたい。
    
    例えば、[1,2,3]のとき、[1,3]でも答えが変わらないことには試してみれば気づくはず。
    これを見つけられたら[1,3,2]を試してみて答えが大きくなることに気づきたい。
    すると、一般化して p1 < p2 > p3 もしくは　p1 > p2 < p3 が最適解になることが導ける。
    あとはこれを数式に起こせれば答えは見えるはず。


    dequeで　小大小大小　ってやったけど駄目だった。

    解答は >< の時は　<> の符号逆転になることを利用している。
    p1 - 2p2 + 2p3 - 2p4 ....... +2pn -pn+1 てな具合になるので、この係数をvectorに入れてソートして、順にA[i]とかけたものを足してく。
    この時のpiがA[i]と同じ。
*/