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
    string S; cin >> S;
//bit_flag集をvectorに格納
//
    vector<int> bit_flag(10);
    rep(i,10){
        bit_flag[i] = (1 << i);
    }

    int N = S.size(); // N = 10
    LL ans = 0;
    LL tmp = 1;
    // {0, 1, ..., n-1} の部分集合の全探索   n-1 = 8
    for (LL bit = 0; bit < (1<<N-1); ++bit){  // N-1 = 9
        tmp = 1;
        rep(i,N){
            if(bit_flag[i] & bit){
                ans += (S[N-1-i] - '0') * tmp;
                tmp = 1; 
            }
            else{
                ans += (S[N-1-i] - '0') * tmp;
                tmp *= 10;
            }
        }
    }
    cout << ans << endl;
}

// 数字の隙間が最大9個なので、bit全探索で調べて、bitが立ってるところで１０の倍数をリセットしながら足してく。