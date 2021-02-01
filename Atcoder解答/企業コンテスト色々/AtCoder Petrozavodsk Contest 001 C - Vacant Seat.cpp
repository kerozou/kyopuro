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

bool ch(int lb,int mid,string l,string m){
    int ld = mid - lb;
    if(ld % 2 == 1 && l == m)return false;
    else if(ld % 2 == 0 && l != m)return false;
    else return true;
}

int main() {
    int N;cin >> N;

    int lb = 0; int ub = N-1;
    cout << lb << endl;
    string l;cin >> l;
    cout << ub << endl;
    string r;cin >> r;
    bool ok = true;
    if(l == "Vacant" || r == "Vacant")ok = false;

    while(ok && ub - lb > 1){

        int mid = (ub+lb)/2;
        cout << mid << endl;
        string m;cin >> m;
        if(m == "Vacant")break;


        if(ch(lb,mid,l,m)){
            lb = mid;    // lb,ubは適宜変更
            l = m;
        }
        else{
            ub = mid;
            r = m;
        }
    }
       
}

// AtCoder Petrozavodsk Contest 001 C - Vacant Seat

/*
    単調でない二分探索
*/