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
    LL N,M;cin >> N >> M;
    if(N >= M/2)cout << M/2 << endl;
    else {
        LL ub=M,lb=0;
        while(ub-lb>1){
            LL mid=(ub+lb)/2;
            if(N+mid<=M/2-mid)lb = mid;     // mid を何個引いてるか
            else ub = mid;
        }
        cout << N + lb << endl;
    }
}

//ABC055
// Sの数NとCの数Mを使って、
// N>=M/2の時はM/2が答え。
// N<M/2の時はN+i<=M/2 -iが成り立つまでループして、N+iが答え。
// しかし、N,Mは10^12なので、N=1,M=10^12とかの時に5*10^12回ループして死ぬ。
// なので、上の条件式が成り立つかどうかを確認する二分探索に持ち込む。
// Cは余っていてもiが小さい時に条件式が成り立つので、真偽の単調性が確認できる。
// よって、二分探索でiを求めて終わり。