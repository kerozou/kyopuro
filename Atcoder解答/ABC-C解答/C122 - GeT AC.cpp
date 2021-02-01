#include <bits/stdc++.h>
using namespace std;

// 文字列からi番目までにACが表れた数の累積和配列を作る。
// あとは、sum_pile[a] - sum_pile[b] を順に出力。

int main(){
    int N,Q;
    cin >> N >> Q ;
    string S;
    cin >> S ;
    vector<long long int> sum_pile(N+1);
    int temp = 0;
    sum_pile[0] = 0;
    for(int i = 1;i < N;i++){ // 累積和配列の作成

        if(S[i] == 'C'){
            if(S[i-1] == 'A'){
                temp += 1;
                sum_pile[i] = temp;
                continue;
            }
        }

    sum_pile[i] = temp;

    }

    int l,r;
    for(int j = 0;j < Q;j++){
        cin >> l >> r;
        cout << sum_pile[r-1] - sum_pile[l-1] << endl;
    }

}

// 20190515 AC