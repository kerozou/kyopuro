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

//  順当に考えると、高得点から順に解いてけばよさそうだけど、全完ボーナスがあるので面倒くさい貪欲になりそう。
//  しかし、D<=10という甘い制約なので、高々2^10のbit全探索でいけそう。
//  全完ボーナスをゲットする前提で、全完した難易度の数値にbitが立つとする。
//  全完した部分だけでsumが足りていなかったら、埋まってない難易度の高い順に解いていってその都度sumチェックする。
//  この工程で「未全完難易度を完了してしまう」恐れがあるが、もしあるとすればbit全探索の時点でクリアしているはず。（この方法だと全完ボーナスが累積されないため、自動的に淘汰される。）
//  また、0完パターンも全探索で含まれているので、これですべてのパターンが網羅されている。


int main(){
    int D;cin >> D;
    LL G;cin >> G;
    vector<int> p(D);
    vector<int> c(D);

    rep(i,D){
        cin >> p[i] >> c[i];
    }

    vector<int> bit_flag(11);       //簡単のためにbitフラグを定義している。(1<<n)のこと。
    rep(i,10){
        bit_flag[i] = (1 << i);
    }

    LL res = INF;                   //次々と小さい値で更新していくのでINFにセット

    for (int bit = 0; bit < (1<<D); ++bit){     //bit全探索ループ
        LL sum = 0;
        LL num = 0;
        rep(i,D){                               //全桁中bitが立ってるところのボーナスと得点、問題数を加入
            if(bit & bit_flag[i]){
                sum += c[i] + 100*(i+1)*p[i];
                num += p[i];
            }
        }
        if(sum >= G) res = min(res,num);        //全完だけで条件を達成しているかチェック。
        else{
            for(int i = D-1;i>=0;i--){          //足りない点数を高得点順に加算
                if(bit & bit_flag[i])continue;      //すでに全完している難易度は飛ばす
                rep(j,p[i]){
                    if(sum >= G)break;
                    sum += 100*(i+1);           //iは0indexなので、得点にするために1足す
                    num++;
                }
            }
        }
        res = min(res,num);         //bitループの一区切りでresの更新.   if内にかぶりがあるけど、被ったところで問題ないのでスルー
    }
    cout << res << endl;
}

//けんちょんさんの解答　ほぼそのまま