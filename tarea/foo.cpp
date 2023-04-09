//
// Created by Fabiola Guardamino Morales
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class Matriz2D {
    friend Matriz2D t(Matriz2D& m);
    friend std::ostream& operator<<(std::ostream& os, const Matriz2D& matriz);
    friend Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2);
    friend Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2);
    friend Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2);
    friend Matriz2D operator+(const Matriz2D& m, float n);
    friend Matriz2D operator-(const Matriz2D& m, float n);
    friend Matriz2D operator*(const Matriz2D& m, float n);
    friend Matriz2D operator/(const Matriz2D& m, float n);

public:
    Matriz2D();
    Matriz2D(int n);
    Matriz2D(int filas, int columnas);
    Matriz2D(const Matriz2D& m);
    Matriz2D(Matriz2D&& m);

    float get(int fila, int columna);
    void set(int fila, int columna, float valor);
    int getFilas();
    int getColumnas();

private:
    int filas;
    int columnas;
    float** ptr;
};

Matriz2D::Matriz2D() : filas(3), columnas(3) {
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++) {
        ptr[i] = new float[columnas];
        for (int j = 0; j < columnas; j++) {
            ptr[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

Matriz2D::Matriz2D(int n) : filas(n), columnas(n) {
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++) {
        ptr[i] = new float[columnas];
        for (int j = 0; j < columnas; j++) {
            ptr[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

Matriz2D::Matriz2D(int filas, int columnas) : filas(filas), columnas(columnas) {
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++) {
        ptr[i] = new float[columnas];
        for (int j = 0; j < columnas; j++) {
            ptr[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m) : filas(m.filas), columnas(m.columnas) {
    ptr = new float*[filas];
    for (int i = 0; i < filas; i++) {
        ptr[i] = new float[columnas];
        for (int j = 0; j < columnas; j++) {
            ptr[i][j] = m.ptr[i][j];
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m) : filas(m.filas), columnas(m.columnas), ptr(m.ptr) {
    m.ptr = nullptr;
    m.filas = 0;
    m.columnas = 0;
}

float Matriz2D::get(int fila, int columna) {
    return ptr[fila][columna];
}

void Matriz2D::set(int fila, int columna, float valor) {
    ptr[fila][columna] = valor;
}

int Matriz2D::getFilas() {
    return filas;
}

int Matriz2D::getColumnas() {
    return columnas;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& matriz) {
    for (int i = 0; i < matriz.filas; i++) {
        for (int j = 0; j < matriz.columnas; j++) {
            os << std::setprecision(2) << matriz.ptr[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2) {
    // Sobrecarga del operador +
    Matriz2D resultado(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m1.columnas; j++) {
            resultado.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
        }
    }
    return resultado;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D resultado(m1.filas, m1.columnas);
    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m1.columnas; j++) {
            resultado.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return resultado;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2) {
    if (m1.columnas != m2.filas) {
        throw std::invalid_argument("Las matrices no tienen dimensiones compatibles para multiplicación.");
    }

    Matriz2D resultado(m1.filas, m2.columnas);

    for (int i = 0; i < m1.filas; i++) {
        for (int j = 0; j < m2.columnas; j++) {
            float valor = 0.0;
            for (int k = 0; k < m1.columnas; k++) {
                valor += m1.ptr[i][k] * m2.ptr[k][j];
            }
            resultado.set(i, j, valor);
        }
    }

    return resultado;
}

Matriz2D operator+(const Matriz2D& m, float n) {
    // Sobrecarga del operador +
    Matriz2D resultado(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] + n;
        }
    }
    return resultado;
}

Matriz2D operator-(const Matriz2D& m, float n) {
    // Sobrecarga del operador -
    Matriz2D resultado(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] - n;
        }
    }
    return resultado;
}

Matriz2D operator*(const Matriz2D& m, float n) {
    // Sobrecarga del operador *
    Matriz2D resultado(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return resultado;
}

Matriz2D operator/(const Matriz2D& m, float n) {
    // Sobrecarga del operador /
    Matriz2D resultado(m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            resultado.ptr[i][j] = m.ptr[i][j] / n;
        }
    }
    return resultado;
}

Matriz2D t(Matriz2D& m) {
    Matriz2D transpuesta(m.columnas, m.filas);

    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            transpuesta.ptr[j][i] = m.ptr[i][j];
        }
    }
    return transpuesta;
}

int main() {
    srand(time(nullptr));

    Matriz2D matriz;
    std::cout << matriz;

    std::cout << "\n";

    Matriz2D matriz2(5, 3);
    std::cout << matriz2;

    std::cout << "\n";

    Matriz2D matriz3(6);
    std::cout << matriz3;

    std::cout << "\n";
    Matriz2D matriz4 = matriz3;
    std::cout << matriz4;

    std::cout << "\n";
    Matriz2D matriz5 = std::move(matriz4);
    std::cout << matriz4;
    std::cout << matriz5;

    std::cout << "\n";
    Matriz2D matriz6 = t(matriz5);
    std::cout << matriz6;

    std::cout << "\n";
    Matriz2D matriz7 = matriz6 + matriz5;
    std::cout << matriz7;

    std::cout << "\n";
    Matriz2D matriz8 = matriz7 - matriz6;
    std::cout << matriz8;

    std::cout << "\n";
    Matriz2D matriz9 = matriz * matriz;
    std::cout << matriz9;

    std::cout << "\n";
    Matriz2D matriz10 = matriz + 5;
    std::cout << matriz10;

    std::cout << "\n";
    Matriz2D matriz11 = matriz - 5;
    std::cout << matriz11;

    std::cout << "\n";
    Matriz2D matriz12 = matriz * 5;
    std::cout << matriz12;

    std::cout << "\n";
    Matriz2D matriz13 = matriz / 5;
    std::cout << matriz13;
    return 0;
}