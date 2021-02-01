//　複素数平面 読み込み

 typedef complex<double> P;          //  complex(real,imag) で宣言
 
 P make_P(pair<double, double> pr) {    //  pair int を入れて com を作る
     return P(pr.first, pr.second);
 }
 
 pair<double, double> make_int(P p) {    //  逆に、com から pair (real,imag) を作る
     return make_pair(p.real(), p.imag());
 }

// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(P a, P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積 (cross product) : a×b = |a||b|sinΘ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}


// 複素数の配列

vector<P> points(n);


// 入力例

cin >> x >> y;
points[i] = P(x, y);

// とるときはautoが楽

auto p1 = points[i];　// P型が入る


// + - / * = の5種が使える。

auto p1 = points[i];
auto p2 = points[j];
auto v = p2 - p1;   // p1を原点としたp2の位置ベクトル

// 複素数のソート（ラムダ式で制御）

sort(all(points), [](const auto &x, const auto &y) {
        return x.real() < y.real();
    }
);

// 回転

auto p1 = points[i];
auto p2 = points[j];
auto v = p2 - p1; 

auto plus = v * P(0, 1);      // 左に90度回転
auto minus = v * P(0, -1);    // 右に90度回転

auto p3 = p1 + plus;            // ベクトル計算をしている
auto p4 = p2 + plus;


// 複素ベクトルの絶対値

|a +bi| = sqrt(a*a + b*b) となる 


// operator <
// これを入れるとcomplex で map のキーとして使える
namespace std{
    template<class T> bool operator<(const complex<T> &a, const complex<T> &b){
        return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real();
    }
};

