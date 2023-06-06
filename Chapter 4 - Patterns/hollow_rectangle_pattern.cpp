#include <iostream>
using namespace std;

int main()
{
  int rows, columns;
  cin >> rows >> columns;
  cout << endl;

  for(int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++)
    {
      if(j == 0 || j == rows-1 || i == 0 || i == columns-1) {
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    
    cout << endl;
  }
  return 0;
}