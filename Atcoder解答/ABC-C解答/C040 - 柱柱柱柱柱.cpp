#include <bits/stdc++.h>
using namespace std;

//　この問題はDPの中でもメモ化再起を利用する。
//  なので、i番目に到達したときの最小コストの配列DP[]と絶対値 int absol() 関数を用意。

// ポインタの初期化忘れでとんでもない値が帰ってきた。しかし、初期化後は無事AC。
// DP[]の内部をforループ内で初期化したことで通過。


int absol(int a);
int minj(int i,int *pd,int *ph);

int main(){
    int N;
    cin >> N;
    int  DP[N];
    int  high[N];

    for(int i = 0;i<N;i++){
        cin >> high[i] ;
        DP[i] = 0;
    }

    cout << minj(N-1,DP,high) << endl;


}

int minj(int i,int *pd,int *ph){ //i+1番目の柱までの最小コスト
    if (i == 0)return pd[i] = 0;
    if (i == 1)return pd[i] = absol(ph[i] -ph[i-1]);//初期値設定

    if (pd[i] != 0)return pd[i];

    int temp1j = absol(ph[i] - ph[i-1]);
    int temp2j = absol(ph[i] - ph[i-2]);

    return pd[i]=min(minj(i-1,pd,ph) + temp1j ,minj(i-2,pd,ph) + temp2j);

}


int absol(int a){
    if (a >= 0)return a;

    if (a < 0)return a*(-1);

}

// AC済