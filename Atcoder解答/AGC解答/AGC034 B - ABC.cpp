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
    string s;cin >> s;
    string q;

    rep(i,s.size()){
        if(s[i] == 'B'){
            if(i+1 < s.size()){
                if(s[i+1] == 'C'){
                    q += 'D';
                    i++;
                }
                else{
                    q += 'B';
                }
            }
            else{
                q += 'B';
            }
        }
        else{
            q += s[i];
        }
    } 

    int lim = q.size();
    bool ok = false;
    LL ans = 0;
    LL ct = 0;
    rep(i,lim){
        if(q[i] == 'A'){
            ct++;
            if(i+1 < lim){
                if(q[i+1] == 'D'){
                    ans += ct;
                    ct--; 
                    q[i+1] = 'A';
                }
            }
        }
        else{
            ct = 0;
        } 
    }

    cout << ans << endl;
}

// AGC034 B - ABC

/*
    BC を D で置換。
    そのあとはrep内の処理をする。
*/