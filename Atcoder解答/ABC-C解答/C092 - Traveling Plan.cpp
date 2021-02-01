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

int main(){
    int N;cin >> N;
    vector<int> A(N),L(N),R(N);
    rep(i,N)cin >> A[i];
    rep(i,N){       // 左累積和　L 作成
        if(i == 0)L[0] = 0;
        else if(i == 1)L[1] = abs(A[0]);
        else{
            L[i] = L[i-1] + abs(A[i-1] - A[i-2]);       // L は　i番目以前の累積和なので、absの中がA[i-1]-A[i-2]になる。
        }
    }
    for(int i = N-1;i>=0;i--){  // 右累積和　R　作成
        if(i == N-1)R[N-1] = 0;
        else if(i == N-2)R[N-2] = abs(A[N-1]);
        else{
            R[i] = R[i+1] + abs(A[i+1] - A[i+2]);
        }
    }
    rep(i,N){
        if(i == 0){
            cout << L[0] + R[0] + abs(A[1]) << endl;
        }
        else if(i == N-1){
            cout << L[i] + R[i] + abs(A[N-2]) << endl;
        }
        else{
            cout << L[i] + R[i] + abs(A[i-1] - A[i+1]) << endl;
        }
    }
}

// ABC C-092 Traveling Plan
// ・配列中から一個抜きの時は、左右累積和をおけないか考えるのがポイント（だと思ってる）

// 1. Aiの配列入力
// 2. 左右累積和L,Rを作る。
// 3. 一般解として L[i] + R[i] + abs(A[i-1] + A[i+1]) が候補に挙がる。
// 4. しかし、左端と右端でいろいろ厄介なことになるので、i==0,N-1 を例外にする。