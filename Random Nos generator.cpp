Codeforces blog: https://codeforces.com/blog/entry/61587?locale=ru

View this submission from : kickstart round -h 2019 -diagonal puzzles

/*
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
// #define int long long
typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(s) (int)s.size()
#define y1 fdfbvfds
typedef long double f80;
#define all(x) x.begin(), x.end()
*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l,ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}


/*
const int N = 105;
char a[N][N], b[N][N];
int n;

void left_flip(int x,int y) {
	while(x <= n && y >= 1) {
		if(b[x][y] == '#') b[x][y] = '.';
		else b[x][y] = '#';
		x++, y--;
	}
}

void right_flip(int x,int y) {
	while(x <= n && y <= n) {
		if(b[x][y] == '#') b[x][y] = '.';
		else b[x][y] = '#';
		x++, y++;
	}
}

void go() {
	fr(i, 1, n) {
		fr(j, 1, n) {
			b[i][j] = a[i][j];
		}
	}
}

int get_moves() {
	int cur = 0;
 	fr(i, 1, n) {
 		int x = 1, y = i;
 		bool move = 0;
 		while(x <= n && y >= 1) {
 			if(x == y || y == x + 1)
 				move |= (b[x][y] == '#');
 			x++, y--;
 		}
 		if(move) {
 			left_flip(1, i);
 			cur++;
 		}
 	}
 	fr(i, 2, n) {
 		int x = i, y = n;
 		bool move = 0;
 		while(x <= n && y >= 1) {
 			if(x == y || y == x + 1)
 				move |= (b[x][y] == '#');
 			x++, y--;
 		}
 		if(move) {
 			left_flip(i, n);
 			cur++;
 		}
 	}
 	// fr(i, 1, n) {
 	// 	fr(j, 1, n) {
 	// 		cout << b[i][j] << " ";
 	// 	}
 	// 	cout << endl;
 	// }
 	fr(i, 1, n) {
 		bool move = 0;
 		int x = i, y = 1;
 		while(x <= n && y <= n) {
 			move |= (b[x][y] == '#');
 			x++, y++;
 		}
 		if(move) {
 			cur++;
 			right_flip(i, 1);
 		}
 	}
 	fr(i, 1, n) {
 		bool move = 0;
 		int x = 1, y = i;
 		while(x <= n && y <= n) {
 			move |= (b[x][y] == '#');
 			x++, y++;
 		}
 		if(move) {
 			cur++;
 			right_flip(1, i);
 		}
 	}
 	fr(i, 1, n) {
 		fr(j, 1, n) {
 			if(b[i][j] == '#')
 				cur = 1e9;
 		}
 	}
 	// fr(i, 1, n) {
 	// 	fr(j, 1, n) {
 	// 		cout << b[i][j] << " ";
 	// 	}
 	// 	cout << endl;
 	// }
 	return cur;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    fr(kase, 1, T) {
        cout << "Case #" << kase << ": ";
        cin >> n;
        fr(i, 1, n) {
        	fr(j, 1, n) {
        		cin >> a[i][j];
        		if(a[i][j] == '.') a[i][j] = '#';
        		else a[i][j] = '.';
        	}
        }
     	if(n == 1) {
     		cout << ((a[1][1] == '.') ? 1 : 0) << endl;
     		continue;
     	}
     	int ans = 1e9;
     	go();
     	ans = min(ans, get_moves());
     	go();
     	right_flip(1, 1);
     	ans = min(ans, get_moves() + 1);
     	go();
     	right_flip(1, 1);
     	right_flip(1, 2);
     	ans = min(ans, get_moves() + 2);
     	go();
     	right_flip(1, 2);
     	ans = min(ans, get_moves() + 1);
     	cout << ans << endl;
    }
    return 0;
}

*/


