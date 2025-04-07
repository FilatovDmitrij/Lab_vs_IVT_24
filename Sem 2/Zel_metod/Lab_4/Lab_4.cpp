#include <iostream>
#define MAX_SIZE 100

using namespace std;

int main() 
{
    int ring[MAX_SIZE];
    int size = 0;
   
    cout << "Введите количество элементов (не более " << MAX_SIZE << "): ";
    cin >> size;
    
    int i = 0;
    while(i < size) 
    {
        cout << "Элемент " << i << ": ";
        cin >> ring[i];
        i++;
    }

    int K;
    cout << "Введите K для печати влево: ";
    cin >> K;
    
    K = (K % size + size) % size;
    i = K;
    while(true) 
    {
        cout << ring[i] << " ";
        i = (i - 1 + size) % size;
        if(i == (K - 1 + size) % size) break;
    }
    cout << endl;

    int max_val = ring[0];
    i = 1;
    while(i < size) 
    {
        if(ring[i] > max_val) max_val = ring[i];
        i++;
    }
    
    int new_size = 0;
    i = 0;
    while(i < size) 
    {
        if(ring[i] != max_val) 
        {
            ring[new_size] = ring[i];
            new_size++;
        }
        i++;
    }
    size = new_size;
    cout << "Введите K для печати вправо: ";
    cin >> K;
    
    K = (K % size + size) % size;
    i = K;
    while(true) 
    {
        cout << ring[i] << " ";
        i = (i + 1) % size;
        if(i == (K + 1) % size) break;
    }
    cout << endl;

    return 0;
}
