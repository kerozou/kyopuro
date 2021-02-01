#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
/**
 * Grab the pellets as fast as you can!
 **/

int main()
{
    int width; // size of the grid
    int height; // top left corner is (x=0, y=0)
    cin >> width >> height; cin.ignore();

    vector<pair<int,int>> mp;

    for (int i = 0; i < height; i++) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall

        rep(j,row.size()){
            if(row[j] == ' ')mp.push_back({i,j});
        }
    }

    int ax = -1;
    int ay = -1;


    // game loop
    while (1) {
        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount; cin.ignore();

        int pacid;
        int mx;
        int my;


        for (int i = 0; i < visiblePacCount; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string typeId; // unused in wood leagues
            int speedTurnsLeft; // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();

            if(mine){
                pacid = pacId;
                mx = x;
                my = y;
            }
        }
        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount; cin.ignore();
        for (int i = 0; i < visiblePelletCount; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
        }

        if(ax == -1 && ay == -1){
            int sz = mp.size();
            int rn = rand() % sz;
            ay = mp[rn].F;
            ax = mp[rn].S;            
        }

        if(mx == ax && my == ay){
            int sz = mp.size();
            int rn = rand() % sz;
            ay = mp[rn].F;
            ax = mp[rn].S;
        }


        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "MOVE" << " " << pacid << " " <<  ax << " " << ay << endl; // MOVE <pacId> <x> <y>
       
    }
}


// とりあえず目的地に着いたらランダムで行先を決めるAI。

// 20200510 20:05
// score 17.59