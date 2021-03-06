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

std::vector<bool> IsPrime;
void sieve(LL max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(LL i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(LL j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}


int main(){
    int N;cin >> N;
    sieve(55555);
    vector<int> num;
    rep(i,IsPrime.size())if(IsPrime[i])if(i % 5 == 1)num.push_back(i);
    rep(i,N)cout << num[i] << " ";
    cout << endl;
}

// ABC096 D - Five, Five Everywhere

// 素数の剰余類で MOD 5 になるものを　N個　表示するだけ。
// 学びとしては、「合成数になる」という条件と「5個の整数を選ぶ」ってところで「5の剰余類を5つとると5の倍数になる」ということに気づくことだった。
