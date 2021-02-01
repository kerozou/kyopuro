#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

double P;
double eps = 1e-9;


double f(double x,double p){
    return x + p/pow(2,x/1.5);
}


double sanbun(double& lb,double& ub){
    while(ub - lb > eps){
        double lmid = 2*lb/3 + ub/3;
        double rmid = lb/3 + 2*ub/3;
        if(f(lmid,P) > f(rmid,P)) lb = lmid;
        else ub = rmid;
    }
    return f(lb,P);
}

int main() {
    cin >> P;
    double lb = 0;
    double ub = 100;
    double ans = sanbun(lb,ub);
    cout << std::fixed << std::setprecision(15) << ans << endl;
}