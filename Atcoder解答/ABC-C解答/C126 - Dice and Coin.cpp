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

int main(){
    int N,K;cin >> N >> K;
    double res = 0.0;
    for(int i = 1;i <= N;i++){
        int n = i;
        double co = 1.0;
        while(n < K)n *= 2,co /= 2.0;
        res += co;
    }
    res /= N;
    cout << fixed << setprecision(10) << res << endl;
}