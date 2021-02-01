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
    int N;cin >> N;
    vector<int> h(N);
    rep(i,N){
        cin >> h[i];
    }                       //ここまで入力

    vector<int> hcopy(N);   //ソート実験用配列
    bool endo = true;       //while鍵
    int res = 0;            //回数

    while(endo){
        hcopy = h;
        sort(all(hcopy));
        if(hcopy[N-1] == 0){  //全部0だったら終わり
            endo = false;
            break;   
        }
        bool ct = true;
        rep(i,N){                           //一周
            if(ct && h[i] == 0){            //初0遭遇
                continue;
            }
            else if(ct && h[i] != 0){       //初!=0遭遇
                ct = false;
            }
            if(h[i] == 0){                  //二回目0遭遇
                res++;
                break;
            }
            else{                           //水やり
                h[i]--;
                if(i == N-1)res++;
            }
        }
    }

    cout << res << endl;
}