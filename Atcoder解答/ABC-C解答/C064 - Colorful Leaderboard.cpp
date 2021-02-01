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
    vector<bool> a(8,false);
    int tmp;
    int ct = 0;
    rep(i,N){
        cin >> tmp;
        tmp /= 400;
        if(tmp >= 8)ct++;
        else a[tmp] = true;
    }
    int min = 0;
    int max = 0;
    rep(i,8)if(a[i])min++;
    if(min == 0){
        min = 1;
        max = ct;
    }
    else{
        max = min + ct;
    }
    cout << min << " " << max << endl;
}

// 全部3200以上の時を忘れてた(1敗)