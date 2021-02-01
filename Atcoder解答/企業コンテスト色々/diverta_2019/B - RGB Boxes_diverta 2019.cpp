#include <bits/stdc++.h>
using namespace std;

// 本番では　
//     N = rR + gG + bB
// となることまでは簡単にわかって、数値r,g,bを固定してまわす方針も考えたが、
// なんとなく実行速度がやばそうな気がして、突っ込めなかった。
// しかし、冷静に考えると高々（3000)^2の　O(N^2)　で、オーダーは9000000　＝　9＊10^6　と問題なかった。

// 教訓として、全探索でいけそうなときは、とりあえずぶん回す方針をとることを考えるべきである
// ということを学んだ。

int main(){
    int R,G,B,N;
    int count = 0;
    cin >> R >> G >> B >> N ;
    for (int i = 0;i < N+1;i++){
        for (int j = 0;j < N+1;j++){
            int v = R*i + G*j ;
            if(N - v < 0)continue;
            if((N - v) % B == 0){
                count += 1;
               // cout << '(' << i << ',' << j << ',' << (N-v)/B << ')' << endl; 
               //確認用
            }
        }
    }
    cout << count << endl;
}
//2019 0512 AC 済み