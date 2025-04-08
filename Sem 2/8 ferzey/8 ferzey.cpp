#include <iostream>
using namespace std;

int desk[8][8]; 
const int Q = -1; 

void clearDesk() 
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            desk[i][j] = 0;
}

void printDesk() 
{
    for(int i = 0; i < 8; i++) 
    {
        for(int j = 0; j < 8; j++) 
	{
            if(desk[i][j] == Q) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
}

void placeQ(int row, int col) 
{
    for(int x = 0; x < 8; x++) 
    {
        desk[x][col]++; 
        desk[row][x]++;
        int d1 = col - row + x;
        if(d1 >= 0 && d1 < 8) desk[x][d1]++;
        
        int d2 = col + row - x;
        if(d2 >= 0 && d2 < 8) desk[x][d2]++;
    }
    desk[row][col] = Q;
}

void removeQ(int row, int col) 
{
    for(int x = 0; x < 8; x++) 
    {
        desk[x][col]--;
        desk[row][x]--;

        int d1 = col - row + x;
        if(d1 >= 0 && d1 < 8) desk[x][d1]--;
        
        int d2 = col + row - x;
        if(d2 >= 0 && d2 < 8) desk[x][d2]--;
    }
    desk[row][col] = 0;
}
bool tryPlace(int row) 
{
    for(int col = 0; col < 8; col++) 
    {
        if(desk[row][col] == 0) 
	{
            placeQ(row, col); 
            
            if(row == 7 || tryPlace(row + 1)) 
                return true;
                
            removeQ(row, col); // Откат
        }
    }
    return false;
}

int main() 
{
    clearDesk();
    if(tryPlace(0)) 
    {
        cout << "Решение найдено:\n";
        printDesk();
    } else 
    {
        cout << "Решение не найдено!\n";
    }
    return 0;
}
