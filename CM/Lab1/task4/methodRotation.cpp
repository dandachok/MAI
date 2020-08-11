#include <cmath>

#include "TMatrix.hpp"

const double pi = std::acos(-1);

int main() {
    int n;
    double e;
    double e_;
    
    std::cin >> n;

    TMatrix a(n, n);
    TMatrix eigenVectors(n, n);

    std::cin >> a;
    std::cin >> e;

    for(int i = 0; i < n; ++i) {
        eigenVectors[i][i] = 1;
    }

    int i = 0;
    do {
        ++i;
        std::pair<int, int> p(a.GetMax());
        
        int line = p.first;
        int column = p.second;

        double angleRotation;
        if (line == column) {
            angleRotation = pi / 4;
        } else {
            angleRotation = (1 / 2.) * std::atan(2 * a[line][column] / (a[line][line] - a[column][column]));
        }

        TMatrix u(n, n);
        TMatrix uTrans(n, n);

        for(int i = 0; i < n; ++i) {
            u[i][i] = 1;
            uTrans[i][i] = 1;
        }

        u[line][line] = cos(angleRotation);
        u[column][column] = cos(angleRotation);
        uTrans[line][line] = cos(angleRotation);
        uTrans[column][column] = cos(angleRotation);
        u[line][column] = -sin(angleRotation);
        u[column][line] = sin(angleRotation);
        uTrans[line][column] = sin(angleRotation);
        uTrans[column][line] = -sin(angleRotation);

        a = uTrans * a * u;
        eigenVectors = eigenVectors * u;

        std::cout << "Iter: " << i << " -----\n"<< a << std::endl << eigenVectors << std::endl << "----------\n";

        double t = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                t += a[j][i] * a[j][i];
            }
        }

        e_ = std::sqrt(t);

    } while(e_ > e);
    std::cout << e << ' ' << e_ << std::endl;

    return 0;
}