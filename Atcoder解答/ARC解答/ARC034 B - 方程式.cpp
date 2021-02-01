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

bool cal(LL x,int f){
    string s = to_string(x);
    int ch = 0;
    for(auto t : s){
        int c = t - '0';
        ch += c;
    }
    if(f == ch)return true;
    else return false;
}

int main() {
    LL N;cin >> N;
    vector<LL> ans;

    rep(i,154){
        LL tmp = N - i;
        if(cal(tmp,i)){
            ans.push_back(tmp);
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    for(auto t : ans)cout << t << endl;
    
}


// ARC034 B - 方程式

/*
    9 * 17 桁 = 153なので、　f(x) = 0 ~ 153 として　N - f(x) を決め打つ.
    x = N - f(x) なので、生成されたxが f(x) = i を満たすかをチェックして、満たすならOK。
*/