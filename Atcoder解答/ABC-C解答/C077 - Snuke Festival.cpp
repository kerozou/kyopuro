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
    vector<LL> A(N),B(N),C(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    rep(i,N)cin>>C[i];
    sort(all(A));
    sort(all(B));
    sort(all(C));
    vector<LL> As(N);
    vector<LL> Cl(N);
    LL ub;
    LL lb;
    rep(i,N){   // 二分探索をA,Cに施す
        ub = N-1,lb = 0;   
        if(A[0]>=B[i])As[i] = 0;
        else if(A[N-1]<B[i])As[i] = N;
        else{  
         while(ub - lb > 1){ // Asmall
            LL mid = (ub + lb)/2;
            if(A[mid] < B[i])lb = mid;      //  if内を満たす者のうち最大のもの
            else ub = mid;  // ifを満たさないもので最小のもの
         }
        As[i] = lb + 1;
        }

        ub = N-1,lb = 0;
        if(C[N-1]<=B[i])Cl[i] = 0;
        else if(C[0]>B[i])Cl[i] = N;
        else{
         while(ub - lb > 1){ // Clarge
            LL mid = (ub + lb)/2;
            if(C[mid] > B[i])ub = mid;  // 条件を満たすうち最小のもの
            else lb = mid;  // 条件を満たさないもののうち最大のもの
         }
        Cl[i] = N - ub;
        }
    }
    LL ans = 0;
    rep(i,N)ans += As[i]*Cl[i];
    cout << ans << endl;
}
// mid = (ub - lb)/2 としないように注意（1敗）
// 二分探索は具体例を書いて、毎回取り出す値を正確に決めないといけない。