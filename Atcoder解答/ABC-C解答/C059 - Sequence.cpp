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
    LL N;cin >> N;
    vector<LL> a(N);
    rep(i,N)cin >> a[i];
    vector<LL> rui(N);
    rep(i,N){
        if(i == 0)rui[i] = a[i];
        else {
            rui[i] = rui[i-1] + a[i];
        }
    }
    LL tmp1 = 0;
    LL ct1 = 0;
    LL tmp2 = 0;
    LL ct2 = 0;
    LL now = 0;
    rep(i,N){   //スタートが正
        if(i%2==0){ // 正であるべき
            if(rui[i]+tmp1 > 0)continue;
            else if(rui[i]+tmp1 == 0){
                now = rui[i] + tmp1;
                tmp1 += 1;
                ct1 += 1;
            }
            else{
                now = rui[i] + tmp1;
                tmp1 += abs(now)+1;
                ct1 += abs(now)+1;
            }
        }
        else {  // 負であるべき
            if(rui[i]+tmp1 < 0)continue;
            else if(rui[i]+tmp1 == 0){
                tmp1 -= 1;
                ct1 += 1;
            }
            else{
                now = rui[i] + tmp1;
                tmp1 += -(abs(now)+1);
                ct1 += abs(now)+1;
            }
        }
    }
        rep(i,N){   //スタートが負
        if(i%2==0){ // 負であるべき
            if(rui[i]+tmp2 < 0)continue;
            else if(rui[i]+tmp2 == 0){
                tmp2 -= 1;
                ct2 += 1;
            }
            else{
                now = rui[i] + tmp2;
                tmp2 += -(abs(now)+1);
                ct2 += abs(now)+1;
            }
        }
        else {  // 正であるべき
            if(rui[i]+tmp2 > 0)continue;
            else if(rui[i]+tmp2 == 0){
                tmp2 += 1;
                ct2 += 1;
            }
            else{
                now = rui[i] + tmp2;
                tmp2 += (abs(now)+1);
                ct2 += abs(now)+1;
            }
        }
    }
    LL ans = min(ct1,ct2);
    cout << ans << endl;
}

// 累積和を作って、それに現在地までに行った操作を足してを繰り返していく。
// スタートが正負の二パターンあることを考慮する。