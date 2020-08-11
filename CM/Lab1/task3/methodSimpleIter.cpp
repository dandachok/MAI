#include "TMatrix.hpp"

int main() {

    int n;
    double e;

    std::cin >> n;

    TMatrix mat(n, n);
    TMatrix vec(n, 1);
    
    std::cin >> mat;
    std::cin >> vec;
    std::cin >> e;

    for(int i = 0; i < n; ++i) {
        vec[i][0] /= mat[i][i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                mat[i][j] /= -mat[i][i];
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        mat[i][i] = 0;
    }

    TMatrix xPrev(vec);
    TMatrix x(vec);

    double a = mat.GetNorm() / (1 - mat.GetNorm());
    double e_;
    int i = 0;
    do{
        ++i;
        xPrev = x;
        x = vec + mat * x;
        e_ = (x - xPrev).GetNorm() * a;
        
    }while(e_ > e);

    std::cout << "x:\n" << x << "e: " << e_ << "\nIter:" << i << std::endl;

    //std::cout << "Matrix:\n" << mat << "Norm: " << mat.GetNorm() << "\nVector:\n" << vec << "Norm: " << vec.GetNorm() << std::endl;

    return 0;
}
