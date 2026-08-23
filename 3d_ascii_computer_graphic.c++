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