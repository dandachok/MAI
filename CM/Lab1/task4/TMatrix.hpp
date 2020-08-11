#include <algorithm>
#include <vector>
#include <iostream>


class TMatrix {
public:
    TMatrix(const TMatrix& m) : storage(m.line, std::vector<double> (m.column, 0)), line(m.line), column(m.column) {
        for(int i = 0; i < line; ++i) 
        {
            for(int j = 0; j < column; ++j)
            {
                storage[i][j] = m.storage[i][j];
            }
        } 
    }

    TMatrix(TMatrix&& m) {
        std::swap(this->storage, m.storage);
    }
    
    TMatrix(int n, int m) : storage(n, std::vector<double>(m, 0)), column(m), line(n) {
    }

    TMatrix& operator= (const TMatrix& m) {
        if(&m != this) {

            for(int i = 0; i < line; ++i) {
                for(int j = 0; j < column; ++j) {
                    storage[i][j] = m.storage[i][j];
                }
            }
        }

        return *this;
    }

    TMatrix& operator= (TMatrix&& m) {
        if(&m != this) {
            std::swap(this->storage, m.storage);
        }

        return *this;
    }

    std::vector<double>& operator[] (const int idx) {
        return storage[idx];
    }

    const std::vector<double>& operator[] (const int idx) const {
        return storage[idx];
    }

    std::pair<int, int>&& GetMax() const {
        double max = 0;
        int iMax;
        int jMax;
        for (int i = 0; i < line; ++i) {
            for (int j = 0; j < column; ++j) {
                if (i != j) {
                    if(std::abs(storage[i][j]) > max) {
                        iMax = i;
                        jMax = j;
                        max = std::abs(storage[i][j]);
                    }
                }
            }
        }

        return std::move(std::make_pair(iMax, jMax));
    }

    double GetNorm() const {
        double max = 0;
        if(column != 1) {
            for(int i = 0; i < column; ++i) {
                double sum = 0;
                for(int j = 0; j < line; ++j) {
                    sum += std::abs(storage[j][i]);
                }

                max = sum > max ? sum : max;
            }
        } else {
            for(int i = 0; i < line; ++i) {
                max = std::abs(storage[i][0]) > max? std::abs(storage[i][0]) : max;
            }
        }

        return max;
    }

    TMatrix operator* (const TMatrix& right) const {

        if(column != right.line) {
            std::cerr << "Matrixs sizes do not fit";
            exit(1);
        }

        TMatrix answer(line, right.column);

        for(int i = 0; i < right.column; i++) {
            for(int j = 0; j < line; j++) {
                for(int k = 0; k < column; k++) {
                    answer.storage[j][i] += storage[j][k] * right.storage[k][i];
                }
            }
        }

        return answer;
    }

    TMatrix& operator* (const double val) {
        for(auto& i: storage) {
            for(auto& j: i) {
                j *= val;
            }
        }

        return *this;
    }

    TMatrix operator+ (const TMatrix& right) const {
        TMatrix ans(*this);

        for(int i = 0; i < line; ++i) {
            for(int j = 0; j < column; ++j) {
                ans[i][j] += right[i][j];
            }
        }

        return ans;
    }

    TMatrix& operator+= (const TMatrix& right) {
        for(int i = 0; i < line; ++i) {
            for(int j = 0; j < column; ++j) {
                storage[i][j] += right[i][j];
            }
        }

        return *this;
    }

    TMatrix& operator-= (const TMatrix& right) {
        for(int i = 0; i < line; ++i) {
            for(int j = 0; j < column; ++j) {
                storage[i][j] -= right[i][j];
            }
        }

        return *this;
    }

    TMatrix operator- (const TMatrix& right) const {
        TMatrix ans(*this);
        ans -= right;
        return ans;
    }

    friend std::istream& operator>> (std::istream& is, TMatrix& m) {
        for(auto &i: m.storage) {
            for(auto &j: i) {
                is >> j;
            }
        }

        return is;
    }

    friend std::ostream& operator<< (std::ostream& os, const TMatrix& m) {
        for(auto i: m.storage) {
            for(auto j: i) {
                os << j << ' ';
            }
            os << '\n';
        }

        return os;
    }

    ~TMatrix() {};

private:
    std::vector<std::vector<double> > storage;
    int column;
    int line;
};
