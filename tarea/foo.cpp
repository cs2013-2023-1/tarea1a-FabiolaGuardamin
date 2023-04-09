//
// Created by Fabiola Guardamino Morales
//
#include <iostream>
#include <cstdlib>
#include <ctime>


class Matriz2D {
private:
    float filas;
    float columnas;

public:
    Matriz2D();
    Matriz2D(int n);
    Matriz2D(int n, int m);
    Matriz2D(const Matriz2D& m);
    Matriz2D(Matriz2D&& m);

    float getFilas();
    float getColumnas();
};

Matriz2D::Matriz2D(){
    srand(time(nullptr));
    filas = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    columnas = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Matriz2D::Matriz2D(int n){
    srand(time(nullptr));
    filas = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    columnas = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Matriz2D::Matriz2D(int n, int m){
    srand(time(nullptr));
    filas = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    columnas = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Matriz2D::Matriz2D(const Matriz2D& m){
    filas = m.filas;
    columnas = m.columnas;
}

Matriz2D::Matriz2D(Matriz2D&& m){
    filas = m.filas;
    columnas = m.columnas;
    m.filas = 0;
    m.columnas = 0;
}

float Matriz2D::getFilas(){
    return filas;
}

float Matriz2D::getColumnas(){
    return columnas;
}

int main(){
    Matriz2D matriz1;
    Matriz2D matriz2(3);
    Matriz2D matriz3(4, 5);
    Matriz2D matriz4(matriz3);
    Matriz2D matriz5(std::move(matriz4));

    std::cout << "Matriz 1: " << matriz1.getFilas() << ", " << matriz1.getColumnas() << std::endl;
    std::cout << "Matriz 2: " << matriz2.getFilas() << ", " << matriz2.getColumnas() << std::endl;
    std::cout << "Matriz 3: " << matriz3.getFilas() << ", " << matriz3.getColumnas() << std::endl;
    std::cout << "Matriz 4: " << matriz4.getFilas() << ", " << matriz4.getColumnas() << std::endl;
    std::cout << "Matriz 5: " << matriz5.getFilas() << ", " << matriz5.getColumnas() << std::endl;

    return 0;
}

