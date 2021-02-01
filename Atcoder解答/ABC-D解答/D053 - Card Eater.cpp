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
    int N;cin >> N;
    map<int,int> A;
    rep(i,N){
        int a;cin >> a;
        A[a]++;
    }
    int even = 0;
    int odd = 0;
    for(auto b : A){
        int c = b.S;
        if(c % 2 == 0)even++;
        else odd++;
    }
    if(even == 0)cout << odd << endl;
    else if(even % 2 == 0)cout << even + odd << endl;
    else cout << even + odd - 1 << endl;
}

// ABC053 D - Card Eater

// カードから「任意」で3枚選んで二枚消す操作の時、実質二枚好きなもの消すのと同じ操作。
// この時、偶数個ある数字は2個まで同じ数を消し続けることで達成可能。
// 奇数枚なら1個まで行ける。
// なので、偶数個が偶数個あるときは、偶数個ある数同士で丁度よく打ち消しあって全部一個にできる。
// 偶数個が奇数個の時は一個余る。