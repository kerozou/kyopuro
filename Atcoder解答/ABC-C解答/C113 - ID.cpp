#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
typedef pair<pair<int,LL>,int> P;

// 二重pairを定義する時は＜＞の入れ子構造に気を配る必要あり。＞＞＞の数が足りなかったり、余計な＜がついててしばらくエラーと格闘した。
// あと、ゼロ埋めはsetfillを使うとすげえべんり。intをcharに変えたりしなくてすむし、エラーも出ない。

unsigned GetDigit(unsigned num){
    return log10(num)+1;
}

int main(){
    int N,M; cin >> N >> M;
    vector<P> L(M);
    LL y;

    rep(i,M){
        cin >> L[i].first.first >> L[i].first.second ;
        L[i].second = i ;
    }

    sort(all(L));

    vector<pair <int, pair<int,int> > > L2(M);
    int temp = 1;
    int birth = 1;

    rep(j,M){
        if(L[j].first.first != temp){
            temp = L[j].first.first;
            birth = 1;
        }
        L2[j].first = L[j].second;
        L2[j].second.first = temp;
        L2[j].second.second = birth;
        birth++;
    }

    sort(all(L2));

    rep(k,M){
        /*
        vector<int> res1(6,0);
        vector<int> res2(6,0);
        */

        int num = L2[k].second.first;
        int num2 = L2[k].second.second;

        cout << setfill('0') << right << setw(6) << num ;
        cout << setfill('0') << right << setw(6) << num2 << endl;
        /*
        int keta = GetDigit(num);
        int keta2 = GetDigit(num2);
        int ten = 1;
        rep(l,keta){
            ten = 1;
            rep(x,l){
                ten *= 10;
            }
            res1[l] = num % ten;
        }
        rep(m,keta2){
            ten = 1;
            rep(y,m){
                ten *= 10;
            }
            res2[m] = num2 % ten;
        }

        rep(z,6){
            cout << res1[5-z] ;
        }
        rep(x,6){
            cout << res2[5-x] << endl;
        }
   */

    }
}