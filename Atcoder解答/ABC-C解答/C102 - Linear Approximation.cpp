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

//  まず、B[i] = A[i] - i とすることで、入力順を無視することができる。つまり、ソートが可能になる。
//  これによって、B[i]を昇順に二次元のグラフ上に移して考えると、あるi番目の数値を境にその上下にある要素の数が ≒ N/2　となる場所がある。
//  この時、ｂを＋１すると、b以下の数値集合はそれぞれabsを1ずつへらす。しかし、b以上の数値集合はそれぞれabsを1ずつ増やす。
//  ≒　N/2個の時、合計で増減するabsは0になるはず。その瞬間のbはNの偶奇によると考えられるが、
//  この場合 b =　B[N/2]　でNが奇数の時は境界いっぱいに収まり、Nが偶数の時も境界の上限いっぱいに収まる。


int main(){
    int N;cin >> N;
    vector<LL> A(N);
    rep(i,N){
        cin >> A[i];
        A[i] -= (i+1);
    }
    sort(all(A));
    LL b = A[N/2];
    LL ans;
    rep(i,N){
        ans += abs(A[i] - b);
    }
    cout << ans << endl;
}