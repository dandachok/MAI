#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {

    // input

    int n;  // size of matrix

    std::cout << "\nEnter size of matrix: ";

    std::cin >> n;

    std::vector<std::vector<double> > a(n, std::vector<double>(n + 1)); // matrix A with b
    std::vector<int> p(n);  // permutation matrix
    std::vector<double> z(n);   // solution Lz = b
    std::vector<double> x(n);   // result solution

    std::cout << "\nEnter matrix A with B:\n";

    for(auto& i: a) {

        for(auto& j: i) {

            std::cin >> j;
        }
    }

    // LU decomposition

    for(int i = 0; i < n; i++) {    // i is column's index

        // swap lines and write on p

        double maxElement = 0;
        int lineMaxEl = i;

        for(int j = i; j < n; j++)  {   // j is line's index

            if(std::abs(a[j][i]) > maxElement) {

                maxElement = std::abs(a[j][i]);
                lineMaxEl = j;
            }
        }

        std::swap(a[i], a[lineMaxEl]);
        p[i] = lineMaxEl;


        for(int j = i + 1; j < n; j++) {

            a[j][i] /= a[i][i];

            for(int k = i + 1; k < n + 1; k++) {

                a[j][k] = a[j][k] - a[j][i] * a[i][k];
            }
        }
    }

    // determinant

    double det = 1;

    for(int i = 0; i < n; i++) {
        det *= a[i][i];
    }

    // solution

        //z[0] = a[0][n]; // a[0][i] is b[i]
        //
        //for(int i = 1; i < n; i++) {
        //    
        //    double sum = 0;
        //
        //    for(int j = 0; j < i; j++) {
        //        sum += a[i][j] * z[j];
        //        std::cout << a[i][j] << " * " << z[j] << ", ";
        //    }
        //
        //    std::cout << sum << std::endl;
        //
        //    z[i] = a[i][n] - sum;
        //}

    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for(int i = n - 2; i >= 0; i--) {

        double sum = 0;

        for(int j = i + 1; j < n; j++) {

            sum += a[i][j] * x[j];
        }

        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // output

    std::cout << "\nPermutation matrix:\n";

    for(auto i: p) {
        std::cout << i + 1 << ' ';
    }

    std::cout << "\n";

    std::cout << "\nLU decomposition:\n";

    for(auto i: a) {

        for(auto j: i) {
        
            std::cout << j << ' ';
        }
        
        std::cout << std::endl;
    }

    std::cout << "\nDeterminant: " << det << std::endl;

    std::cout << "\nSolution:\n";

    for(auto i: x) {
        
        std::cout << i << ' ';
    }

    std::cout << std::endl;
    return 0;
}