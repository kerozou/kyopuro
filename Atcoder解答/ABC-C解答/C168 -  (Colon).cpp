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

const double pi = 3.141592653589793;

double dist(double x1,double x2,double y1,double y2){
    double tmp = abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2);
    tmp = sqrt(tmp);
    return tmp;
}
int main() {
    double A,B,H,M;cin >> A >> B >> H >> M;

    double hunth = 90 - M*6;
    double hun = 60 * H + M;
    double zith = 90 - hun*0.5;

    double hx = B*cos(hunth * (pi/180));
    double hy = B*sin(hunth * (pi/180));

    double zx = A*cos(zith * (pi/180));
    double zy = A*sin(zith * (pi/180));

    double ans = dist(hx,zx,hy,zy);
    cout << std::fixed << std::setprecision(15) << ans << endl;
}