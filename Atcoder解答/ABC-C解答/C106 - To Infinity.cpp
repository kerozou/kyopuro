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

//  入力が文字列なので、桁ごとにint配列に分離する。
//  そののち、頭から続く1の数によって分岐。
//  1以外はその数の5000兆乗個並ぶので、必然的に1以外に初めに現れた数が答えになる。


unsigned GetDigit(unsigned num){
    if(num == 0)return 1;
    return log10(num)+1;
}

int main(){
    string S;cin >> S;
    LL K;cin >> K;
    vector<int> s;
    int ksize = GetDigit(K);
    for(auto i : S){
        s.push_back(i -'0');
    }

    int one_ct = 0;         //1のカウント。
    if(s[0] == 1){
        rep(i,s.size()){
            if(i == 0){
                one_ct++;
                continue;
            }
            if(s[i-1] == s[i]){
                one_ct++;
            }
            else{
                break;
            }
        }
    }


    if(one_ct >= K){                //1の方がKより多い時、答えは１
        cout << '1' << endl;
    }
    else if(one_ct != 0 && one_ct < K){     //1よりKの方が多い時、最後の1の次の数が答え。配列は0indexなので、one_ct番目がそのまま答え。
        cout << s[one_ct] << endl;
    }
    else{
        cout << s[0] << endl;       //1が頭に現れないとき。
    }
}