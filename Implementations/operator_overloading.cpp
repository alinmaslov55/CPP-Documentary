#include <iostream>

template<typename T, int n, int m>
class Matrix{
    int rows = n;
    int cols = m;
    T** data;
    public:
    template <typename U = T, typename = std::enable_if_t<std::is_same_v<U, int> || std::is_same_v<U, float> || std::is_same_v<U, double>>>
    Matrix(){
        data = new T*[rows];
        for(int i = 0; i < rows; ++i){
            data[i] = new T[cols];
        }
    }
    Matrix(int number){
        data = new T*[rows];
        for(int i = 0; i < rows; ++i){
            data[i] = new T[cols];
        }

        for(auto row : data){
            for(auto cell : row){
                *cell = number;
            }
        }
    }

    ~Matrix(){
        for(auto row : data){
            delete[] row;
        }
        delete[] data;
    }
};

int main(){
    Matrix<double, 3, 4> matrix;
    return 0;
}