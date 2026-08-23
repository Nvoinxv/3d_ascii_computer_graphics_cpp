#include <vector>
#include <iostream>
#include <cmath>

struct vector_3d {
    double x;
    double y;
    double z;
};

struct edge {
    int a;
    int b;
};

class vector_3d_operation {
    public:
    vector_3d operasi_tambah(vector_3d a, vector_3d b) {
        return {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
        };
    }

    vector_3d operasi_pengurangan(vector_3d a, vector_3d b) {
        return {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z
        };
    }

    vector_3d operasi_perkalian(vector_3d a, vector_3d b) {
        return {
            a.x * b.x,
            a.y * b.y,
            a.z * b.z
        };
    }

    vector_3d operasi_skalar(vector_3d a, double skalar) {
        return {
            a.x * skalar,
            a.y * skalar,
            a.z * skalar
        };
    }
};

int main() {
    for (int i = 0; i < 30; i++) {
        std::cout << "=" << " ";
    }

    std::cout << std::endl;

    std::cout << "MEMULAI PROGRAM OPERASI VEKTOR" << std::endl;

    for (int j = 0; j < 30; j++) {
        std::cout << "=" << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    vector_3d a = {2, 5, 6};
    vector_3d b = {1, 3, 5};

    double skalar = 10.0;

    vector_3d_operation vektor;

    std::cout << "Input pada vektor A: "
              << "[" << a.x << ", " << a.y << ", " << a.z << "]"
              << std::endl;

    std::cout << "Input pada vektor B: "
              << "[" << b.x << ", " << b.y << ", " << b.z << "]"
              << std::endl;

    std::cout << "Input pada skalar: "
              << skalar
              << std::endl;

    vector_3d hasil_pertambahan = vektor.operasi_tambah(a, b);
    vector_3d hasil_pengurangan = vektor.operasi_pengurangan(a, b);
    vector_3d hasil_perkalian = vektor.operasi_perkalian(a, b);
    vector_3d hasil_skalar = vektor.operasi_skalar(a, skalar);

    std::cout << std::endl;

    std::cout << "Hasil pertambahan vektor: "
              << "[" << hasil_pertambahan.x
              << ", " << hasil_pertambahan.y
              << ", " << hasil_pertambahan.z << "]"
              << std::endl;

    std::cout << "Hasil pengurangan vektor: "
              << "[" << hasil_pengurangan.x
              << ", " << hasil_pengurangan.y
              << ", " << hasil_pengurangan.z << "]"
              << std::endl;

    std::cout << "Hasil perkalian vektor: "
              << "[" << hasil_perkalian.x
              << ", " << hasil_perkalian.y
              << ", " << hasil_perkalian.z << "]"
              << std::endl;

    std::cout << "Hasil skalar vektor: "
              << "[" << hasil_skalar.x
              << ", " << hasil_skalar.y
              << ", " << hasil_skalar.z << "]"
              << std::endl;

    return 0;
}