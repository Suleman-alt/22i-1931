#include <iostream>
using namespace std;

void in(int** ptr, int row, int col) 
{
    cout << "Enter elements:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> ptr[i][j];
        }
    }
}

int Sum(int** ptr, int row, int col) 
{
    int sum = 0;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++)
        {
            sum += ptr[i][j];
        }
    }
    return sum;
}

void out(int** ptr, int row, int col) 
{
    cout << "Matrix:" << endl;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}


void rsum(int** ptr, int row, int col) 
{
    for (int i = 0; i < row; i++) 
    {
        int rsum = 0;
        for (int j = 0; j < col; j++)
        {
            rsum += ptr[i][j];
        }
        cout << "Sum of row " << i + 1 << " is: " << rsum << endl;
    }
}

void csum(int** ptr, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int csum = 0;
        for (int j = 0; j < row; j++)
        {
            csum += ptr[j][i];
        }
        cout << "Sum of column " << i + 1 << " is: " << csum << endl;
    }
}

void tran(int** ptr, int row, int col)
{
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < col; i++) 
    {
        for (int j = 0; j < row; j++)
        {
            cout << ptr[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row, col;
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    int** ptr = new int* [row];
    for (int i = 0; i < row; i++) {
        ptr[i] = new int[col];
    }

    in(ptr, row, col);
    out(ptr, row, col);

    int sum = Sum(ptr, row, col);
    cout << "Sum of all elements: " << sum << endl;

    rsum(ptr, row, col);
    csum(ptr, row, col);

    tran(ptr, row, col);

    for (int i = 0; i < row; i++)           // Deallocating 2d allocated memory
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}
