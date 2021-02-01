#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
//sort(all(x))とするとソートできるよ

int main(){
    int N;cin >> N;
    LL A,B;
    vector<pair<LL,LL>> work(N);
    rep(i,N){ // B,Aの順で保存
        cin >> work[i].second >> work[i].first ;
    }
    sort(all(work));

    bool OK = true;
    LL tmp;
    LL sum = 0;
    rep(j,N){ 
        tmp = work[j].first - work[j].second ;
        if(tmp - sum < 0){
            OK = false;
            break;
        }
        sum += work[j].second;
    }
    if(OK){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}