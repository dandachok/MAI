#include "TMatrix.hpp"

int main() {
    int n;
    double e;

    std::cin >> n;

    TMatrix a(n, n);
    TMatrix b(n, 1);

    std::cin >> a >> b >> e;

    for(int i = 0; i < n; ++i) {
        b[i][0] /= a[i][i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                a[i][j] /= -a[i][i];
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        a[i][i] = 0;
    }

    TMatrix x(b);       // k-th x
    TMatrix xPrev(b);   // (k - 1)'th x

    double c = 0;

    for(int i = 0; i < n; ++i) {
        double sum = 0;
        for(int j = 0; j <= i; ++j) {
            sum += std::abs(a[j][i]);
        }
        c = sum > c ? sum : c;
    }

    double k = c / (1 - a.GetNorm());
    double e_;

    int i = 0;

    do{
        ++i;
        xPrev = x;
        for(int k = 0; k < n; ++k) {
            x[k][0] = b[k][0];
            for(int j = 0; j < k; ++j) {
                x[k][0] += a[k][j] * x[j][0];
            }
            for(int j = k; j < n; ++j) {
                x[k][0] += a[k][j] * xPrev[j][0];
            }
        }
        e_ = (x - xPrev).GetNorm();
        
    }while(e_ > e);

    std::cout << "x:\n" << x << "e: " << e_ << "\nIter: " << i << std::endl;

    return 0;
}