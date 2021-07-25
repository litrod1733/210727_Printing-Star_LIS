//
// Created by 이인성 on 2021/07/23.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

vector<vector<char>> v;

void setStar(int exp, int row, int colunm) {
  if(exp==0) {
    v[row][colunm] = '*';
    return;
  }
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      if(i == 1 && j == 1)
        continue;
      setStar(exp-1, row+pow(3,exp-1)*i, colunm+pow(3,exp-1)*j);
    }
  }
}

int main() {
  int N;
  int exponent = 0;
  cin >> N;
  v.resize(N);
  for(int i=0; i<N; i++) {
    v[i].resize(N,' ');
  }
  int N2 = N;
  while(N2!=1) {
    N2 /= 3;
    exponent++;
  }
  setStar(exponent, 0, 0);
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      printf("%c", v[i][j]);
    }
    printf("\n");
  }
  return 0;
}