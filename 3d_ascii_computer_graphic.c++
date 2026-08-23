#include <vector>
#include <iostream>
#include <cmath>

struct vector_3d {
    double x;
    double y;
    double z;
}

struct edge {
    int a;
    int b;
}

class 3d_vector {
    public:
    vector_3d operasi_tambah(egde a, edge b) {
        return {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
        };
    }

    vector_3d operasi_pengurangan(edge a, edge b) {
        return {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z
        };
    }

    vector_3d operasi_perkalian(edge a, edge b) {
        return {
            a.x * b.x,
            a.y * b.y,
            a.z * b.z
        };
    }

    vector_3d operasi_skalar(edge a, double skalar) {
        return {
            a.x * skalar;
            a.y * skalar;
            a.z * skalar;
        }
    }
}

int main() {
    for (int i = 0; i < 30; i++) {
        std::cout << "=" << " ";
    }
    std::cout << std::endl;

    std::cout << "MEMULAI PROGRAM OPERASI VEKTOR" std::endl;

    for(int j=0; j < 30; j++) {
        std::cout << "=" << " ";
    }

    std::cout << std::endl;


    std::cout << std::endl;
    edge a = {2, 5, 6};
    edge b = {1, 3, 5};
    double skalar = 10.0;
    3d_vector vektor;

    std::cout << "Input pada vektor A: " << "[" << a << "]" << std::endl;
    std::cout << "Input pada vektor B: " << "[" << b "]" << std::endl;
    std::cout << "Input pada skalar: " << skalar << std::endl;

    double hasil_pertambahan = vektor.operasi_tambah(a,b);
    double hasil_pengurangan = vektor.operasi_pengurangan(a,b);
    double hasil_perkalian = vektor.operasi_perkalian(a,b);
    double hasil_skalar = vektor.operasi_skalar(a, skalar);


    std::cout << "Hasil pertambahan vektor: " << hasil_pertambahan << std::endl;
    std::cout << "Hasil pengurangan vektor: " << hasil_pengurangan << std::endl;
    std::cout << "Hasil perkalian vektor: " << hasil_perkalian << std::endl;
    std::cout << "Hasil skalar vektor: " << hasil_skalar << std::endl;

    return 0;
}