#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

// O(NlogN)程度で通さないといけないので、ループは1重しかできない。
// なので、東、西を向いてる人をindexでカウントする配列を作って、そこから累積和（i番目の左まで何人、右まで何人）を作りたい。
// ただ、リーダーの左側にいる人たちは　西→東　にしか向かず、右側にいる人たちは　東→西　にしか向かないので、累積和配列は　左の西向き　と　右の東向き　の二つあればいい。

int main(){
    int N;cin >> N;
    string S;cin >> S;
    vector<int> East(N);
    vector<int> West(N);

    rep(i,N){               // どこの誰が東西を向いているかの配列。
        if(S[i] == 'E')East[i] = 1;
        else West[i] = 1;
    }     
    vector<int> right_E(N); // 累積和たち(i番目までに左or右にいるEorWの人数。)
    vector<int> left_W(N);

    rep(i,N){               // 左累積和
        if(i == 0){
            left_W[0] = 0;
        }
        else{
            left_W[i] = left_W[i-1] + West[i-1];
        }
    }
    for(int i = N-1;i >= 0;i--){    // 右累積和
        if(i == N-1){
            right_E[N-1] = 0;
        }
        else{
            right_E[i] = right_E[i+1] + East[i+1];
        }
    }
    
    int ans = 1 << 30;  //INF
    rep(i,N){
        ans = min(ans,left_W[i] + right_E[i]);  //累積和をそれぞれ足したもので最小値更新
    }

    cout << ans << endl;
}