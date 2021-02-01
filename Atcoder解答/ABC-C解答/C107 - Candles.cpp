#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
//sort(all(x))とするとソートできるよ

//  Kの範囲だけ帯状で動かしてクリアできればシンプルに実装できそう。
//  なので、- + ,++ , -- , 0含む　のいずれでも行けるようなmin式を書けばいい。それが下記のmin式。

int main(){
    int N,K; cin >> N >> K;
    vector<LL> x(N);
    rep(i,N){
        cin >> x[i];
    }
    LL res = 1LL<<60;
    for(int i = 0;i + K - 1 < N;i++){
        LL left = x[i], right = x[i+K-1];
        res = min(res,min(abs(left),abs(right)) + right - left);
    }
    cout << res << endl;
}