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
    LL N,K;
    cin >> N >> K;
    vector<LL> A(N);
    vector<LL> F(N);


    rep(i,N)cin >> A[i];
    rep(i,N)cin >> F[i];

    sort(all(A));

    sort(rall(F));

    vector<LL> AF(N);
    rep(i,N)AF[i] = A[i]*F[i];

    //解の存在範囲を初期化
    LL lb = 0,ub = INF;

//    rep(i,N)cout << A[i] << "|" << F[i] << " ";
    LL sum = 0;
    rep(i,N)sum += A[i];

    if(sum <= K){
        cout << 0 << endl;

    }
    else{

    //解の存在範囲が1より大きい間、繰り返す
  while (ub-lb > 1){
        LL mid = (lb + ub)/2;
        LL cost = 0;

        rep(i,N)if(AF[i] > mid)cost += (AF[i] - mid + F[i] - 1)/F[i];     // (a[i]-b) / F[i] の切り上げ
        if(cost > K){
            lb = mid;
        }
        else{
            ub = mid;
        }

    }

    cout << ub << endl;
    }

}

