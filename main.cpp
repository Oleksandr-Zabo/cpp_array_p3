#include <iostream>
#include <ctime>;
using namespace std;

//
int main()
{
    srand(time(0));
    const int full_col = 20;
    const int full_row = 20;
    int row, col;
    do
    {
        cout << "Enter the number of columns: ";
        cin >> row;
    } while (row < 1 || row > full_row);
    do
    {
        cout << "Enter the number of rows: ";
        cin >> col;
    } while (col < 1 || col > full_col);


    int arr[full_col][full_row];
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
    /*for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;*/

    double all_sum = 0, sum_raw = 0, sum_col = 0;
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            cout << arr[i][j] << "   ";
            sum_raw += arr[i][j];
            all_sum += arr[i][j];
        }
        cout << "| " << sum_raw << endl;
        sum_raw = 0;
    }
    for (int i = 0; i <= row+1; i++)
    {
        cout << "- -";
    }

    cout << endl;
    for (int j  = 0;  j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            sum_col += arr[i][j];
            all_sum += arr[i][j];
        }
        cout  << sum_col << " |";
        sum_col = 0;
    }

    cout << "  " << all_sum << endl;
    return 0;
}