#include <bits/stdc++.h>
using namespace std;


void solve2(pair<int, pair<int, int>> nr, int row, int cols,
            vector<vector<char>> &adj, vector<vector<int>> &freq) {
  if (nr.first == 1) {
    for (int j = nr.second.second + 2;
         adj[nr.second.first][j] != '*' &&
         !(adj[nr.second.first][j] >= '1' && adj[nr.second.first][j] <= '6');
         j += 2) {
      freq[nr.second.first][j]++;
    }
  }

  if (nr.first == 2) {
    int i = nr.second.first + 1;
    int j = nr.second.second + 1;

    for (; adj[i][j] != '*' && !(adj[i][j] >= '1' && adj[i][j] <= '6');
         i += 1, j += 1) {
      freq[i][j]++;
    }
  }

  if (nr.first == 3) {
    int i = nr.second.first + 1;
    int j = nr.second.second - 1;

    for (; adj[i][j] != '*' && !(adj[i][j] >= '1' && adj[i][j] <= '6');
         i += 1, j -= 1) {
      freq[i][j]++;
    }
  }

  if (nr.first == 4) {
    for (int j = nr.second.second - 2;
         adj[nr.second.first][j] != '*' &&
         !(adj[nr.second.first][j] >= '1' && adj[nr.second.first][j] <= '6');
         j -= 2) {
      freq[nr.second.first][j]++;
    }
  }

  if (nr.first == 5) {
    int i = nr.second.first - 1;
    int j = nr.second.second - 1;

    for (; adj[i][j] != '*' && !(adj[i][j] >= '1' && adj[i][j] <= '6');
         i -= 1, j -= 1) {
      freq[i][j]++;
    }
  }

  if (nr.first == 6) {
    int i = nr.second.first - 1;
    int j = nr.second.second + 1;

    for (; adj[i][j] != '*' && !(adj[i][j] >= '1' && adj[i][j] <= '6');
         i -= 1, j += 1) {
      freq[i][j]++;
    }
  }
}

struct numpos{
  int i, j;
} n1, n2, n3, n4, n5, n6;

void clock_wise(int n, numpos &x, vector<vector<char>> &adj){
  if(x.j >= n){
    if(x.i == 0){
      if(x.j + 2 <= 4*n && adj[0][x.j + 2] == '*'){
        x.j += 2;
      }else{
        x.i += 1;
        x.j += 1;
      }
    }else if(x.i > 0 && x.i < n){
      x.i += 1;
      x.j += 1;
    }else if(x.i == n){
      x.i += 1;
      x.j -= 1;
    }else if(x.i > n && x.i < 2*n){
      x.i += 1;
      x.j -= 1;
    }else if(x.i == 2*n){
      if(x.j - 2 >= 0 && adj[2*n][x.j - 2] == '*'){
        x.j -= 2;
      }else{
        x.i -= 1;
        x.j -= 1;
      }
    }
  }else{
    if(x.i > 0 && x.i < n){
      x.i -= 1;
      x.j += 1;
    }else if(x.i == n){
      x.i -= 1;
      x.j += 1;
    }else if(x.i > n && x.i < 2*n){
      x.i -= 1;
      x.j -= 1;
    }
  }
}

void solve() {
  int N;
  cin >> N;
  int row = 2 * N + 1;
  int cols = 4 * N + 1;

  vector<vector<char>> adj(row, vector<char>(cols));


  vector<vector<int>> freq(row, vector<int>(cols, 0));
  pair<int, pair<int, int>> nr;

  n1 = {N, 0};
  n2 = {0, N};
  n3 = {0, 3*N};
  n4 = {N, 4*N};
  n5 = {2*N, 3*N};
  n6 = {2*N, N};

  adj[n1.i][n1.j] = '1';
  adj[n2.i][n2.j] = '2';
  adj[n3.i][n3.j] = '3';
  adj[n4.i][n4.j] = '4';
  adj[n5.i][n5.j] = '5';
  adj[n6.i][n6.j] = '6';

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < cols; j++) {
      // if (adj[i][j] == 'M')
      //   freq[i][j]++;

      if (adj[i][j] >= '1' && adj[i][j] <= '6') {
        nr = {adj[i][j] - '0', {i, j}};
        solve2(nr, row, cols, adj, freq);
      }
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < cols; j++) {
      if (freq[i][j] >= 3) {
        adj[i][j] = 'O';
      } else if (freq[i][j] == 2) {
        adj[i][j] = 'M';
      }
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < cols; j++) {
      cout << adj[i][j];
    }
    cout << '\n';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}