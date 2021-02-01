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
    vector<int> a(N+1);
    a[0] = 0;
    rep(i,N)cin >> a[i+1];

    vector<int> ans(N+1);
    ans[N] = 0;

    for(int i = N;i >= 1;--i){
        int tmp = 0;
        for(int j = 1;j*i <= N;++j){
            tmp += ans[j*i];
        }
        tmp %= 2;
        if(tmp == a[i])ans[i] = 0;
        else ans[i] = 1;
    }
    int ct = 0;
    rep(i,N+1)if(ans[i])ct++;
    cout << ct << endl;
    int ct2 = 0;
    for(int i = 1;i <= N;++i){
        if(ct2 <= ct && ans[i]){
            cout << i << " ";
            ct2++;
        }
    }
}

// ABC-134 D - Preparing Boxes

// iの倍数を見ていくとき、ans[i] は後ろに続く i の倍数のans[i]を全て知らなければ配置のしようがない。
// しかし、後ろからボールを詰めてけば、i の倍数の最後尾は一意に決定できる。
// つまり、俗にいう「後ろから貪欲」ってやつ。
// このとき、 i を N から順にいれてくと、その調べる個数は N/i 個になり、総数は (N/1 + N/2 + ... + N/N) 
// となる。
// これは調和級数で、 N * logN になるらしい。ので、O(NlogN)でいける。
