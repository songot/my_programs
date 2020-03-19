#include <iostream>   
#include <cstdlib> 
 
int main() 
{
    // Выделение памяти, достаточной для массива из 4 int
    int* p1 = (int*)std::malloc(4*sizeof(int));
    // Тоже самое, но с прямым указания типа  
    int* p2 = (int*)std::malloc(sizeof(int[4]));
    // Тоже самое, но без повторного указания имени типа
    int* p3 = (int*)std::malloc(4*sizeof *p3);  
 
    if(p1) {
        for(int n=0; n<4; ++n) // Заполнение массива
            p1[n] = n*n;
        for(int n=0; n<4; ++n) // Вывод его содержимого
            std::cout << "p1[" << n << "] == " << p1[n] << '\n';
    }
 
    std::free(p1);
    std::free(p2);
    std::free(p3);
}
