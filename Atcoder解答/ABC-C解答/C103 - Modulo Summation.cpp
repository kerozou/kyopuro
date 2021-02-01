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

//  解答の方針は、
//  m mod a の内最大になるのは　m mod a = a-1 の時であることを利用。
//  m　に制限はないので、　m = (a1)(a2)(a3)....(aN) - 1 とすると、
//  a1~aN　のいずれで割っても　割った法 -1 が余りとして求まる。
//  これは 例えば法をa1としたときに、
//      m = (a1)(a2~aNの積-1) + (a1) - 1
//  とあらわせて、(a1)(a2~aNの積-1)は(a1)で割り切れるので、必然的に余りが(a1)-1になることがわかる。
//  これはすべてのaについて同じことが言えるので、求める答えは
//      ans = a1 + a2 + ... + aN - (N個)
//  である。

int main(){
    int N;cin >> N;
    int ans;
    int a;
    int tmp;
    rep(i,N){
        cin >> a;
        tmp += a;
    }
    ans = tmp - N;
    cout << ans << endl;
}