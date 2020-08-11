#include <iostream>
#include <vector>

int main() {

    int n;
    double a, b, c, d;

    std::cin >> n;

    std::vector<double> p(n);
    std::vector<double> q(n);
    std::vector<double> x(n);

    std::cin >> b >> c >> d;

    p[0] = -c / b;
    q[0] = d / b;

    for(int i = 1; i < n - 1; i++) {

        std::cin >> a >> b >> c >> d;

        p[i] = -c / (b + a * p[i - 1]);
        q[i] = (d - a * q[i - 1]) / (b + a * p[i - 1]);
    }

    std::cin >> a >> b >> d;

    p[n - 1] = 0;
    q[n - 1] = (d - a * q[n - 2]) / (b + a * p[n - 2]);

    // back track

    x[n - 1] = q[n - 1];

    for(int i = n - 2; i >= 0; i--) {
        x[i] = p[i] * x[i + 1] + q[i];
    }

    for(auto i: x) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}