#include <bits/stdc++.h>
using namespace std;

#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int DELTAS = 4;
const int dx[DELTAS] = {1, -1, 0, 0};
const int dy[DELTAS] = {0, 0, 1, -1};

const int maxn = 5;
const int maxsz = 15;
bool board[maxsz][maxsz];
int n, w, h, l;

typedef struct state {
    ii bots[maxn];

    operator int() {
        sort(bots + 1, bots + n);
        int id = 0;
        fori(n, i) {
            ii& bot = bots[i];
            id *= 10, id += bot.first, id *= 10, id += bot.second;
        }
        return id;
    }

    bool is_specific_bot(int boti, int x, int y) {
        return bots[boti] == ii{x, y};
    }

    bool is_bot(int x, int y) {
        fori(n, i) if (is_specific_bot(i, x, y)) return true;
        return false;
    }

    bool can_move(int x, int y) { return !is_bot(x, y) && board[x][y]; }

    void move_in_direction(int boti, int dx, int dy) {
        int &x = bots[boti].first, &y = bots[boti].second;
        int nx = x + dx, ny = y + dy;
        while (can_move(nx, ny)) x += dx, y += dy, nx = x + dx, ny = y + dy;
    }

    void move_bot(queue<state>& q, int boti) {
        fori(DELTAS, i) {
            state s(*this);
            s.move_in_direction(boti, dx[i], dy[i]);
            q.push(s);
        }
    }

    void all_moves(queue<state>& q) { fori(n, i) move_bot(q, i); }

} state;

signed main() {
    cin >> n >> w >> h >> l;

    state start;
    int fx, fy;

    fori(maxsz, i) fori(maxsz, j) board[i][j] = false;

    for (int i = 1; i <= h; i++) {
        board[i][0] = board[i][w + 1] = false;
        for (int j = 1; j <= w; j++) {
            char a;
            cin >> a;
            board[i][j] = (a != 'W');

            if ('1' <= a && a <= '9') start.bots[a - '1'] = {i, j};
            if (a == 'X') fx = i, fy = j;
        }
    }

    queue<state> cur, next;
    set<int> s;
    next.push(start);
    int steps = 0;

    do {
        cur = next;
        next = queue<state>();
        while (!cur.empty()) {
            state curs = cur.front();
            cur.pop();
            if (curs.is_specific_bot(0, fx, fy))
                return cout << steps << endl, 0;

            int uid = curs;
            auto itr = s.lower_bound(uid);
            if (itr == s.end() || *itr != uid)
                s.insert(itr, uid), curs.all_moves(next);
        }
    } while (++steps <= 10);

    cout << "NO SOLUTION" << endl;
}
