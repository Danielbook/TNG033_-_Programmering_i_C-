#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


void my_strcat(char *S1, const char *S2)
{
    int count = strlen(S1);

    while(*S2)
    {
        *(S1+count) = *S2++;  //See Fö 3 for pointer arithmetic and C-strings
        count++;
    }

/*
    while(*S2 != '\0')
    {
        S1[count] = *S2;
        S2++;
        count++;
    }
*/

    *(S1+count) = '\0'; //null terminator character of C-string
}


int main()
{
  const int SIZE = 50;

  char word1[SIZE], word2[SIZE];

  cout << "Enter word 1: ";
  cin >> setw(SIZE) >> word1;

  cout << "Enter word 2: ";
  cin >> setw(SIZE) >> word2;

  my_strcat(word1, word2);

  cout << "Concatenated word: " << word1 << endl;

  return 0;
}
