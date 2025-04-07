#include <iostream>
#define MAX_SIZE 100

int main() {
    int ring[MAX_SIZE];
    int size = 0;
    
    std::cout << "Введите количество элементов (не более " << MAX_SIZE << "): ";
    std::cin >> size;
    
    int i = 0;
    while(i < size) {
        std::cout << "Элемент " << i << ": ";
        std::cin >> ring[i];
        i++;
    }

    int K;
    std::cout << "Введите K для печати влево: ";
    std::cin >> K;
    
    K = (K % size + size) % size; 
    i = K;
    while(true) {
        std::cout << ring[i] << " ";
        i = (i - 1 + size) % size;
        if(i == (K - 1 + size) % size) break;
    }
    std::cout << std::endl;

    int max_val = ring[0];
    i = 1;
    while(i < size) {
        if(ring[i] > max_val) max_val = ring[i];
        i++;
    }
    
    int new_size = 0;
    i = 0;
    while(i < size) {
        if(ring[i] != max_val) {
            ring[new_size] = ring[i];
            new_size++;
        }
        i++;
    }
    size = new_size;

    std::cout << "Введите K для печати вправо: ";
    std::cin >> K;
    
    K = (K % size + size) % size; 
    i = K;
    while(true) {
        std::cout << ring[i] << " ";
        i = (i + 1) % size;
        if(i == (K + 1) % size) break;
    }
    std::cout << std::endl;

    return 0;
}
