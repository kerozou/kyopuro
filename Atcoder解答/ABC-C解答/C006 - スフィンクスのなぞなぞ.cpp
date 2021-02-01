#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M = 0;
    cin >> N >> M ;

    if(M - 3*N < 0){ //老人の3本足で全部考えてみる

        if(M - 2*N < 0){ //不正解
            cout << "-1 -1 -1" << endl;
        }

        else{ //大人と老人で鶴亀算

            cout << N-(M-(2*N)) << ' ' << (M-(2*N)) << ' ' << 0 << endl;
        }
    }

    else if (M - 4 * N > 0){ //脚が多すぎる時アウト    
        cout << "-1 -1 -1" <<endl;


    }
    else{ //老人と赤ちゃんで鶴亀算

        cout << 0 << ' ' << N-(M-3*N) << ' ' << M-3*N << endl;

    }
}

//AC済み