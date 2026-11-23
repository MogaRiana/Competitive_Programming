#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

vv freq(6, vi64(26));

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  str s, a, key[6];
  while (cin >> a) {
    s += a;
  }

  for (int k = 0; k < 6; k++) {
    int m = -1;
    // int c = -1;
    for (int i = k; i < s.size(); i += 6) {
      freq[k][s[i] - 'A']++;
      if (freq[k][s[i] - 'A'] > m) {
        m = freq[k][s[i] - 'A'];
        // c = s[i] - 'A';
      }
    }

    // cout << (char)(((c - 4 + 26) % 26) + 'A');

    str c = "ETAONRISHDLFCM";
    cout << "{ ";
    for (int cc = 0; cc < c.size(); cc++) {
      for (int i = 0; i < 26; i++) {
        if (freq[k][i] == m) {
          cout << (char)(((i - (c[cc] - 'A') + 26) % 26) + 'A');
        }
      }
      cout << ' ';
    }
    cout << '}' << endl;
  }

  return 0;
}