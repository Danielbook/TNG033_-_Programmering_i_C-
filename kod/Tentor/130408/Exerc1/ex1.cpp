// =======================================================
// Ex1
// Name:
// Personal number:
// =======================================================

#include <iostream>

using namespace std;

const int MAX = 10;

typedef int MATRIX [MAX][MAX];

bool symmetric(MATRIX m, int l, int c)
{
    for(int line = 0; line < l; line++)
        for(int col = 0; col < line; col++) //until the diagonal
            if (m[line][col] != m[col][line])
                return false;
    return true;
}

int main()
{
    MATRIX M;

    for(int line = 0; line < MAX; line++)
        for(int col = 0; col < MAX; col++)
            cin >> M[line][col];

    if (symmetric(M, MAX, MAX))
        cout << "The matrix is symmetric." << endl;
    else
        cout << "The matrix is not symmetric." << endl;
}
