// Notes: https://drive.google.com/file/d/1HUx50o7QAph1quheH2WlT1-f3cPE89VF/view

#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  int arr[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  int row_start = 0, row_end = n-1;
  int col_start = 0, col_end = m-1;

  while(row_start <= row_end && col_start <= col_end)
  {
    // print first row
    for(int col = col_start; col <= col_end; col++) {
      cout << arr[row_start][col] << "\t";
    }

    row_start++;

    // print last column
    for(int row = row_start; row <= row_end; row++) {
      cout << arr[row][col_end] << "\t";
    }

    col_end--;

    // print last row
    for(int col = col_end; col >= col_start; col--) {
      cout << arr[row_end][col] << "\t";
    }

    row_end--;

    // print first column
    for(int row = row_end; row >= row_start; row--) {
      cout << arr[row][col_start] << "\t";
    }

    col_start++;
  }

  return 0;
}