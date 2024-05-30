#include <iostream>
#include <ctime>;
using namespace std;

//
int main()
{
    srand(time(0));
    const int full_col = 12;
    const int full_row = 7;
    int row_1 = 5, col_1 = 10, row_2 = 5, col_2 = 5;;


    int arr[full_col][full_row], arr_2[full_col][full_row];
    for (long i = 0; i < col_1; i++)
    {
        for (int j = 0; j < row_1; j++)
        {
            arr[i][j] = rand() % 51;
        }
    }

    cout << "The first matrix:" << endl;
    for (short i = 0; i < col_1; i++)
    {
        for (int j = 0; j < row_1; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }


    int k = 0, temp[full_col * full_row];//add temp array for arr -> arr_2
    for (int i = 0; i < col_1; i++)
    {
        for (int j = 0; j < row_1; j++)
        {
            temp[k] = arr[i][j];
            k++;
        }
    }


    k = 0;
    for (int i = 0; i < col_2; i++)
    {
        for (int j = 0; j < row_2; j++)
        {
            arr_2[i][j] = temp[k]+temp[k+1];
            k+=2;
        }
    }


    cout << endl << endl;
    cout << "The second matrix:" << endl;
    for (short i = 0; i < col_2; i++)
    {
        for (int j = 0; j < row_2; j++)
        {
            cout << arr_2[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}