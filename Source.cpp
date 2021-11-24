#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;


void create(int** a, int col, int row, int l, int h, int i, int j);
void print(int** a, int row, int col, int i, int j);
void Max(int** a, const int row, const int col, int n, int max, int& i_max, int& j_max, int i, int j);
void Change(int** a, const  int row, const int col, int n,  int i);

void main() {
    srand((unsigned)time(NULL));

    int n;
    int row;
    int col;

    //  cout << "row = "; cin >> n;

    cout << "n = "; cin >> n;
    col = n;
    row = n;

    int l = 0;
    int h = 10;

    int max = 0;
   

    int** a = new int* [row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];

    create(a, col, row, l, h, 0, 0);
    print(a, row, col, 0, 0);
    Change(a, row, col, n, 0);
    print(a, row, col, 0, 0);

    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;
    


}
void create(int** a, int col, int row, int l, int h, int i, int j) {
    a[i][j] = l + rand() % (h - l + 1);
    if (j < col - 1) {
        create(a, col, row, l, h, i, j + 1);
    }
    else if (i < row - 1) {
        create(a, col, row, l, h, i + 1, 0);
    }
    else {
        cout << endl;
    }
}

void print(int** a, int row, int col, int i, int j) {

    if (j == 0) {
        cout << "|";
    }

    cout << setw(3) << a[i][j] << " ";

    if (j == col - 1) {
        cout << "|\n";
    }

    if (j < col - 1) {
        print(a, row, col, i, j + 1);
    }
    else if (i < row - 1) {
        print(a, row, col, i + 1, 0);
    }
    else {
        cout << endl;
    }
}

void Max(int** a, const int row, const int col, int n, int max, int& i_max, int& j_max, int i, int j)
{
   

    if (a[i][j] >= max && (i != j || (i == j && i > n))) {
        max = a[i][j];
        i_max = i;
        j_max = j;
    }

    if (j < col - 1) {
        Max(a, row, col, n, max, i_max, j_max, i, j + 1);
    }
    else if (i < row - 1) {
        Max(a, row, col, n, max, i_max, j_max, i + 1, 0);
    }
}

void Change(int** a, const  int row, const int col, int n, int i)
{
    int tmp;
    int  i_max = 0;
    int j_max = 0;

    Max(a, row, col, n, a[i][i], i_max, j_max, 0, 0);

    tmp = a[i_max][j_max];
    a[i_max][j_max] = a[i][i];
    a[i][i] = tmp;


    if (i < col - 1) {
        Change(a, row, col, n,  i + 1);
    }
}