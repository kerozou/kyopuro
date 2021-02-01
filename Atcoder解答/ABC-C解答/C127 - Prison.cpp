#include <bits/stdc++.h>
using namespace std;

// 不等式の範囲の重複箇所を取って、上―下＋１でカードの枚数を出してる。

int main(){
    int N,M; cin >> N >> M;
    int temp;
    int Ltemp,Rtemp; cin >> Ltemp >> Rtemp;
    
 
        for(int i = 1;i < M;i++){
            int L,R; cin >> L >> R;

            if(Ltemp <= L){
                Ltemp = L;
        
            }
            if(Rtemp >= R){
                Rtemp = R;
            }
        }
        int res = Rtemp - Ltemp + 1 ;
        if(Rtemp < Ltemp)res = 0;
        cout << res << endl;

 
}