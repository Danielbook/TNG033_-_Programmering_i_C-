#include <iostream>

using namespace std;


int main()
{
  const int SIZE = 10;

  char text1[SIZE];

  for(int i = 0; i < SIZE; i++) //store the letters a-j in text1
    text1[i] = 'a' + i;

  char text2[SIZE];

  for(int i = 0; i < SIZE; i++) //store the letters A-J in text2
    text2[i] = 'A' + i;

  cout << "Text1: " << text1 << endl;
  cout << "Text2: " << text2 << endl;

  cout << endl << "Why is this wrong??? " << endl;

  return 0;
}
