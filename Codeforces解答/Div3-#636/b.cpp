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

int main() {
    int t;cin >> t;
    rep(k,t){
        LL n;cin >> n;
        if(n == 2 || ((n/2) % 2 == 1))cout << "NO" << endl;
        else{
            LL sum = (n/2)*((n/2)+1);
            vector<LL> ev;
            for(LL i = 0;i < n/2;i++)ev.push_back(2*(i+1));

            vector<LL> od;
            LL tmp = 0;
            for(LL i = 0;i < n/2-1;i++){
                od.push_back(2*(i+1)-1);
                tmp += (2*(i+1)-1);
            }
            if(sum-tmp > 1e9){
                cout << "NO" << endl;
                continue;
            }
            od.push_back(sum-tmp);

            cout << "YES" << endl;
            for(auto t : ev)cout << t << " ";
            for(auto t : od)cout << t << " ";
            cout << endl;
        }
    }
}