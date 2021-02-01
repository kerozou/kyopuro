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
    int N,M;cin >> N >> M;
    int k;
    vector<int> p(M);
    vector<vector<int>> v(M,vector<int>(N));
    rep(i,M){
        cin >> k;
        rep(j,k){
            cin >> v[i][j] ;
        }
    }
    rep(k,M){
        cin >> p[k];
    }

    int co;

    int sum = 0;

    vector<int> bit_flag(11);
    rep(i,N){
        bit_flag[i] = (1 << i);
    }
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<N); ++bit){ // bit全探索

        bool res = true;
        rep(j,M){ // スイッチのパターン一つを一周
            co = 0;
            
            rep(i,N){               // 一つの電球を探索 
                if(v[j][i] == 0)break;      // 0はすなわちスイッチがないことに等しい
                int tmp = v[j][i] - 1;      // スイッチの番号取得
                if(bit & bit_flag[tmp]){     // スイッチがONだとco++
                    co++;
                }
            }

            if(co % 2 != p[j]){     // ONスイッチの数の偶奇チェック
                res = false;
                break;
            }
        }

        if(res)sum++;       // 探索一回終了

    }

    cout << sum << endl;
}