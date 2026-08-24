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

double perhitungan_sudut(double sudut, bool ke_radian) {
    const double pi = 3.141592653589793;

    if (ke_radian) {
        return sudut * pi / 180.0;
    } else {
        return sudut * 180.0 / pi;
    }
}


// Membuat Kelas Balok 3D 
class Balok_3D {
    public:
    std::vector<vector_3d> balok = {
        {-1, -1, -1},
        { 1, -1, -1},
        { 1,  1, -1},
        {-1,  1, -1},

        {-1, -1,  1},
        { 1, -1,  1},
        { 1,  1,  1},
        {-1,  1,  1}
    };

    std::vector<edge> titik = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4},
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7}
    };
    
    // Membuat operasi matrix agar fleksibel pada variabel balok dan titik 
    vector_3d operasi_matrix(matrix_3d m,vector_3d v) {
        return {
            m.data[0][0] * v.x + m.data[0][1] * v.y + m.data[0][2] * v.z,
            m.data[1][0] * v.x + m.data[1][1] * v.y + m.data[1][2] * v.z,
            m.data[2][0] * v.x + m.data[2][1] * v.y + m.data[2][2] * v.z
        };
    }

    void rotasi(perhitungan_sudut sudut) {
        sudut = (70, true);
        matrix_3d R = operasi_rotasi_matrix.rotasi_y(sudut);
        for (auto& vertex : balok) {
            vertex = operasi_matrix.operasi_matrix(R, vertex);
        };
    }

    private:
    rotasi_matrix_3d operasi_rotasi_matrix;
    matrix_3d m;
    vector_3d v;
    double sudut;
};

class Render_Objek_ASCII {
    public:
    vector_3d projeksi_orthografi(vector_3d a) {
        // Biar kelihatan 3D
        double layar_x = a.x - a.z * 0.5;
        double layar_y = a.y - a.z * 0.25;

        return { layar_x, layar_y, 0 };
    }

    std::vector<vector_3d> Algoritma_DDA(vector_3d a, vector_3d b) {
        std::vector<vector_3d> titik_garis;

        double delta_x = b.x - a.x;
        double delta_y = b.y - a.y;

        double langkah = std::max(std::abs(delta_x), std::abs(delta_y));

        if (langkah == 0) {
            titik_garis.push_back(a);
            return titik_garis;
        }

        double X_incerement = delta_x / langkah;
        double Y_incerement = delta_y / langkah;

        double x = a.x;
        double y = a.y;

        for (int i = 0; i <= (int)langkah; i++) {
            titik_garis.push_back({x, y, 0});
            x += X_incerement;
            y += Y_incerement;
        }

        return titik_garis;
    }

    void gambar_titik (
        std::vector<std::vector<char>>& layar,
        vector_3d titik,
        int panjang,
        int tinggi
    ) {
        int x = panjang / 2 + static_cast<int>(titik.x * 10);
        int y = tinggi / 2 - static_cast<int>(titik.y * 10);

        if (x >= 0 && x < panjang && y>= 0 && y < tinggi) {
            layar[y][x] = "*";
        }
    }

    void gambar_garis (std::vector<std::vector<char>>& layar,
        vector_3d a,
        vector_3d b,
        int panjang,
        int tinggi
    ) {
        std::vector<vector_3d> titik_garis = Algoritma_DDA(a, b);

        for(auto& titik : titik_garis) {
            gambar_titik(
                layar,
                titik,
                panjang,
                tinggi
            );
        }
    }

    void Layar(const int panjang = 80, const int tinggi = 40) {
        std::vector<std::vector<char>> layar(tinggi, std::vector<char>(panjang, ' '));
         
        for (auto& edge : titik) {
            vector_3d a = balok[edge.a];
            vector_3d b = balok[edge.b];

            a = operasi_matrix()

            vector_3d a_2d = projeksi_orthografi(a);
            vector_3d b_2d = projeksi_orthografi(b);

            gambar_garis(
                layar,
                a_2d,
                b_2d,
                panjang,
                tinggi
            );
        }

        for (int y = 0; y < tinggi; y++) {
            for (int x = 0; x < panjang; x++) {
                std::cout << layar[y][x];
            }
            std::cout << "\n";
        }
    }
};

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