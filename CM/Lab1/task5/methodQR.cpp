#include <cmath>

#include "TMatrix.hpp"

double sign(double val) {
    return val < 0 ? -1: 1;
}

int main() {

    int n;
    double e;

    std::cin >> n;

    TMatrix a(n, n);
    TMatrix identity(n, n);
    for(int i = 0; i < n; ++i) {
        identity[i][i] = 1;
    }

    std::cin >> a;
    std::cin >> e;

    double e_;

    TMatrix ans(a);

    int i = 0;

    do{

        TMatrix r(ans);
        TMatrix q(identity);
        
        for(int k = 0; k < n - 1; ++k) {
            TMatrix v(n, 1);

            double sum = 0;
            for(int i = k; i < n; ++i) {
                sum += r[i][k] * r[i][k];
            }

            v[k][0] = r[k][k] + sign(r[k][k]) * sqrt(sum);

            for(int i = k + 1; i < n; ++i) {
                v[i][0] = r[i][k];
            }

            TMatrix h = identity - v * v.GetTrans() * (2 / v.GetSquareSum());

            r = h * r;
            q = q * h;
            //std::cout << "v" << k << ": " << v.GetTrans() << std::endl;
            //std::cout << "A" << k << ":\n" << r << std::endl;
            //std::cout << "h" << k << ":\n" << h << std::endl;
        }

        ans = r * q;
        //std::cout << "ans:\n" << ans << std::endl;
        i++;
    } while (std::abs(ans[n - 1][0]) > e);
    
    std::cout << "A:\n" << ans << std::endl;

    for(int i = 0; i < n;) {
        if(i != n - 1) {
            if(std::abs(ans[i + 1][i]) < e) {
                std::cout << "v" << i + 1 << ": " << ans[i][i] << std::endl;
                ++i;
            } else {
                double b = - (ans[i][i] + ans[i + 1][i + 1]);
                double c = b - ans[i][i + 1] * ans[i + 1][i];
                double d = std::sqrt(std::abs(b * b - 4 * c));
                std::cout << b << ' ' << c << std::endl;
                std::cout << "v" << i + 1 << ": " << -b/2 << " + i*" << d << std::endl;
                std::cout << "v" << i + 2 << ": " << -b/2 << " - i*" << d << std::endl;
                i += 2;
            }
        } else {
            std::cout << "v" << i + 1 << ": " << ans[i][i] << std::endl;
            ++i;
        }
    }

    return 0;
}