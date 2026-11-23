#include <bits/stdc++.h>
using namespace std;

void generate(int N, vector<vector<char>> &adj) {
  vector<char> row1;

  for (int i = 0; i < N; i++) {
    row1.push_back('-');
  }

  for (int i = 0; i < 2 * N + 1; i++) {
    if (i & 1) {
      row1.push_back('-');
    } else {
      row1.push_back('*');
    }
  }

  for (int i = 0; i < N; i++) {
    row1.push_back('-');
  }

  adj.push_back(row1);

  for (int i = 0; i < N; i++) {
    vector<char> row;

    for (int j = 0; j < N - (i + 1); j++) {
      row.push_back('-');
    }

    row.push_back('*');

    if (i < N) {
      for (int j = 0; j < 2 * N + 1 + 2 * i; j++) {
        if (j & 1) {
          row.push_back('O');
        } else {
          row.push_back('-');
        }
      }
    }

    row.push_back('*');

    for (int j = 0; j < N - (i + 1); j++) {
      row.push_back('-');
    }

    adj.push_back(row);
  }

  for (int i = 0; i < N - 1; i++) {
    vector<char> row;

    for (int j = 0; j < i + 1; j++) {
      row.push_back('-');
    }

    row.push_back('*');

    for (int j = 0; j < 4 * N - 1 - 2 * (i + 1); j++) {
      if (j & 1) {
        row.push_back('O');
      } else {
        row.push_back('-');
      }
    }

    row.push_back('*');

    for (int j = 0; j < i + 1; j++) {
      row.push_back('-');
    }

    adj.push_back(row);
  }

  vector<char> lastRow;

  for (int i = 0; i < N; i++) {
    lastRow.push_back('-');
  }

  for (int i = 0; i < 2 * N + 1; i++) {
    if (i & 1) {
      lastRow.push_back('-');
    } else {
      lastRow.push_back('*');
    }
  }

  for (int i = 0; i < N; i++) {
    lastRow.push_back('-');
  }

  adj.push_back(lastRow);
}

struct numpos {
  int i, j;
};

numpos positions_radius[6];

void put_radius(int N, vector<vector<char>> &adj) {
  // pun pozitile
  positions_radius[0] = {N, 0};
  positions_radius[1] = {0, N};
  positions_radius[2] = {0, 3 * N};
  positions_radius[3] = {N, 4 * N};
  positions_radius[4] = {2 * N, 3 * N};
  positions_radius[5] = {2 * N, N};
}

vector<bool> turned(6, 0);

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

void counter_clock_wise(int n, numpos &x, vector<vector<char>> adj) {
  if(x.j <= 3*n){
    if(x.i == 0){
      if(x.j - 2 >= 0 && adj[0][x.j - 2] == '*'){
        x.j -= 2;
      }else{
        x.i += 1;
        x.j -= 1;
      }
    }else if(x.i > 0 && x.i < n){
      x.i += 1;
      x.j -= 1;
    }else if(x.i == n){
      x.i += 1;
      x.j += 1;
    }else if(x.i > n && x.i < 2*n){
      x.i += 1;
      x.j += 1;
    }else if(x.i == 2*n){
      if(x.j + 2 >= 0 && adj[2*n][x.j + 2] == '*'){
        x.j += 2;
      }else{
        x.i -= 1;
        x.j += 1;
      }
    }
  }else{
    if(x.i > 0 && x.i < n){
      x.i -= 1;
      x.j -= 1;
    }else if(x.i == n){
      x.i -= 1;
      x.j -= 1;
    }else if(x.i > n && x.i < 2*n){
      x.i -= 1;
      x.j += 1;
    }
  }
}

void solve() {
  turned.assign(6, 0);

  int N;
  cin >> N;
  int row = 2 * N + 1;
  int cols = 4 * N + 1;

  vector<vector<char>> adj;

  generate(N, adj);

  put_radius(N, adj);
  vector<vector<int>> freq(row, vector<int>(cols, 0));

  int L;
  cin >> L;

  for (int i = 0; i < L; i++) {
    string S;
    cin >> S;

    for (int k = 0; k < 6; k++) {
      switch (S[k]) {
      case 'F':
        clock_wise(N, positions_radius[k], adj);
        cout << positions_radius[k].i << " " << positions_radius[k].j << endl;
        break;
      case 'B':
        counter_clock_wise();
        break;
      case 'T':
        //solve2(int row, int cols, vector<vector<char>> adj, freq,
        //       positions_radius[k], k);
        break;
      default:
        continue;
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