#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1 LL << 60
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
    int K;cin >> K;
    vector<pll> pos(K);
    rep(i,K)cin >> pos[i].F >> pos[i].S;

    vector<int> per(8);
    rep(i,8)per[i] = i;
    do{
        vector<bool> tate(8);
        vector<bool> naname(15);
        vector<bool> gyaku(15);
        vector<vector<char>> ans(8,vector<char>(8,'.'));
        bool ok = true;
        rep(i,8){
            if(tate[per[i]]){
                ok = false;
                break;
            }
            tate[per[i]] = true;
            if(naname[i + per[i]]){
                ok = false;
                break;
            }
            naname[i + per[i]] = true;
            if(gyaku[i + (7 - per[i])]){
                ok = false;
                break;
            }
            gyaku[i + (7 - per[i])] = true;
            ans[i][per[i]] = 'Q';
        }

        rep(i,K){
            if(ans[pos[i].F][pos[i].S] != 'Q'){
                ok = false;
                break;
            }
        }

        if(ok){
            rep(i,8){
                rep(j,8){
                    cout << ans[i][j];
                }
                cout << endl;
            }
            break;
        }
    }while(next_permutation(all(per)));



}