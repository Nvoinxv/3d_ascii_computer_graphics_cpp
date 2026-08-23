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

struct matrix_3d {
    double data[3][3];
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

class rotasi_matrix_3d {
public:

    matrix_3d rotasi_x(double theta) {
        return {{
            {1, 0, 0},
            {0, std::cos(theta), -std::sin(theta)},
            {0, std::sin(theta),  std::cos(theta)}
        }};
    }

    matrix_3d rotasi_y(double theta) {
        return {{
            { std::cos(theta), 0, std::sin(theta)},
            {0, 1, 0},
            {-std::sin(theta), 0, std::cos(theta)}
        }};
    }

    matrix_3d rotasi_z(double theta) {
        return {{
            {std::cos(theta), -std::sin(theta), 0},
            {std::sin(theta),  std::cos(theta), 0},
            {0, 0, 1}
        }};
    }
};

void print_vector(vector_3d v) {
    std::cout << "["
              << v.x << ", "
              << v.y << ", "
              << v.z << "]";
}

void print_matrix(matrix_3d matrix) {
    for (int i = 0; i < 3; i++) {
        std::cout << "[ ";

        for (int j = 0; j < 3; j++) {
            std::cout << matrix.data[i][j];

            if (j < 2) {
                std::cout << "  ";
            }
        }

        std::cout << " ]" << std::endl;
    }
}

void garis() {
    std::cout << "==============================" << std::endl;
}

int main() {

    garis();
    std::cout << "OPERASI VEKTOR 3D" << std::endl;
    garis();

    // Input
    vector_3d a = {2, 5, 6};
    vector_3d b = {1, 3, 5};

    double skalar = 10.0;

    vector_3d_operation vektor;

    std::cout << "Vektor A = ";
    print_vector(a);
    std::cout << std::endl;

    std::cout << "Vektor B = ";
    print_vector(b);
    std::cout << std::endl;

    std::cout << "Skalar   = " << skalar << std::endl;

    // Operasi
    vector_3d hasil_pertambahan =
        vektor.operasi_tambah(a, b);

    vector_3d hasil_pengurangan =
        vektor.operasi_pengurangan(a, b);

    vector_3d hasil_perkalian =
        vektor.operasi_perkalian(a, b);

    vector_3d hasil_skalar =
        vektor.operasi_skalar(a, skalar);

    // Output
    std::cout << std::endl;

    std::cout << "A + B = ";
    print_vector(hasil_pertambahan);
    std::cout << std::endl;

    std::cout << "A - B = ";
    print_vector(hasil_pengurangan);
    std::cout << std::endl;

    std::cout << "A * B = ";
    print_vector(hasil_perkalian);
    std::cout << std::endl;

    std::cout << "A * " << skalar << " = ";
    print_vector(hasil_skalar);
    std::cout << std::endl;

    std::cout << std::endl;

    garis();
    std::cout << "ROTASI MATRIX 3D" << std::endl;
    garis();

    rotasi_matrix_3d rotasi;

    double theta = 0.5;

    matrix_3d rx = rotasi.rotasi_x(theta);
    matrix_3d ry = rotasi.rotasi_y(theta);
    matrix_3d rz = rotasi.rotasi_z(theta);

    std::cout << "Rotasi X (" << theta << " rad):" << std::endl;
    print_matrix(rx);

    std::cout << std::endl;

    std::cout << "Rotasi Y (" << theta << " rad):" << std::endl;
    print_matrix(ry);

    std::cout << std::endl;

    std::cout << "Rotasi Z (" << theta << " rad):" << std::endl;
    print_matrix(rz);

    std::cout << std::endl;

    garis();

    return 0;
}