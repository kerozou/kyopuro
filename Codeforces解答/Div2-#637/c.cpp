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


bool calc(int n,int ct,vector<int>& nind,vector<int>& p){
    if(ct == n){
        return true;
    }

    int ctmp = ct;
    for(int i = n-1-ct;i >= 0;i--){
        if(p[i] == ctmp+1){
            ctmp++;
        }
        else{
            break;
        }
    }

    if(ctmp == n){
        return true;
    }

    int start = nind[ctmp+1];
    int tmpp = ctmp;
    for(int i = start;i < n-tmpp;i++){
        if(p[i] == ctmp+1){
            ctmp++;
        }
        else{
            return false;
        }
    }

    return calc(n,ctmp,nind,p);
}

int main() {
    int t;cin >> t;
    rep(k,t){
        int n;cin >> n;vector<int> p(n);
        rep(i,n)cin >> p[i];

        vector<int> nind(n+1);
        rep(i,n){
            nind[p[i]] = i;
        }

        if(calc(n,0,nind,p))cout << "Yes" << endl;
        else cout << "No" << endl;

       
    }
}