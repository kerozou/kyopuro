#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// けんちょんさんのコード。
// 自分なりの解釈と解説を加えていく。

// 基本的な考え方は
// 1,必ず2点以上h>0もしくはh=0だけどピラミッドの外側にない点がある。
// 2,その少なくとも2点以上のうち、1点を基準点として、それ以外の点と比較する。
// 3,全部おっけーだったらクリア

// という手法。
// 俺の解答と決定的に違ったのは「ピラミッドの外側の0点」を考慮に入れている点である。
// 直接数値を求める俺の方法だと、この0点を処理しきれない。もしくはとんでもなく長くなりそう。

// なので、h>0とh==0の処理を作るのだが、h>0はそのままメイン処理として機能させる。
// h==0の分岐を例外処理（外部の0点）処理に使う。
// 外部0はそもそも、高さの決定からは除外できる。
// というのも、そもそも外部0点は頂点までの高さの公式が通用しないので、別途考える必要が出てくるのだが、
// 不確定の外部0点と確定した高さを持つ点の2点からは、頂点候補が一つに定まらない。
// なので、問題の条件である「一意に定まる」というルールを破ることになる。

// 以上の議論を逆から考えると、外部0点を探索に用いると「頂点候補が複数発生する可能性がある」ということである。
// すなわち、外部0点をピラミッドの外周ギリギリの点であると仮定してしまった時に偶然「他の頂点」が存在してしまうということである。

// なので、ピラミッドのゼロ点の位置関係が異なる以上、これは考慮してはいけない。
// したがって、外部の点であるかぎり必ず「基準の高さH」を超えるはずなので、
// (vh[i] == 0 && h > abs(x - vx[i]) + abs(y - vy[i]))　となるときは、外部にあるはずの0点がピラミッド内部に存在、
// すなわち、高さ０かつピラミッド内部なので、基準として採用できる高さ0の点になっているときのことである。

// この矛盾した設定の0点を排除することで、それ以外に存在する2点以上の基準点から精確な頂点が求まるという流れになる。

int main() {
    int N; cin >> N;
    vector<long long> vx(N), vy(N), vh(N);
    int si = -1;
    for (int i = 0; i < N; ++i) {
        cin >> vx[i] >> vy[i] >> vh[i];
        if (vh[i] > 0) si = i;
    }
    
    long long resx = -1, resy = -1, resh = -1;
    for (long long x = 0; x <= 100; ++x) {
        for (long long y = 0; y <= 100; ++y) {
            long long h = vh[si] + abs(x - vx[si]) + abs(y - vy[si]);
            bool ok = true;
            for (int i = 0; i < N; ++i) {
                if (vh[i] > 0 && h - vh[i] != abs(x - vx[i]) + abs(y - vy[i]))
                    ok = false;
                if (vh[i] == 0 && h > abs(x - vx[i]) + abs(y - vy[i]))
                    ok = false;
            }
            if (ok) resx = x, resy = y, resh = h;
        }
    }
    cout << resx << " " << resy << " " << resh << endl;
}