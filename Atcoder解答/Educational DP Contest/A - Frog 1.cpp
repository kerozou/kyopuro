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

int main(){
    //input
    int N;cin >> N;
    const LL big = 1LL << 60; 
    vector<int> h(N);
    rep(i,N)cin >> h[i];

    //DP初期化
    LL DP[100010];
    rep(i,100010)DP[i] = big;

    //初期条件
    DP[0] = 0;

    //roop
    rep(i,N){
        if(i == 0)continue;
        if(i == 1)DP[1] = abs(h[1] - h[0]);
        chmin(DP[i],DP[i-1] + abs(h[i] - h[i-1]));
        chmin(DP[i],DP[i-2] + abs(h[i] - h[i-2]));
    }

    cout << DP[N-1] << endl;
}