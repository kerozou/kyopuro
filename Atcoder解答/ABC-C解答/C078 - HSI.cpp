#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    long long teisyutu_kaisuu = 1LL<<M;
    long long each_time = 1900LL * M + 100LL * (N - M);
    cout <<  each_time * teisyutu_kaisuu << endl;
}

// けんちょんさんのコードそのまま

// C - HSI

// プログラムは毎回、1900M+100(N−M) ms かかることから、AC がもらえるまでの回数の期待値を e とすれば、求める期待値は
//  1900M+100(N−M))e
// となることがわかる。よって問題は、AC がもらえるまでに提出する回数の期待値を求める問題へと帰着された。