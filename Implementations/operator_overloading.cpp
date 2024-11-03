#include <iostream>

template<typename T, int n, int m, typename = std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>>>
class Matrix{
    int rows = n;
    int cols = m;
    T** data;
    public:
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
    void set(const int &krow, const int &kcol, const T & value){
        if(krow <= row - 1 && kcol <= column - 1 && krow >= 0 && kcol >= 0)
        data[krow][kcol] = value;
        else{
            std::cerr << "Invalid index" << std::endl;
        }
    }
    T get(const int &krow, const int &kcol, const T & value){
        if(krow <= row - 1 && kcol <= column - 1 && krow >= 0 && kcol >= 0)
        return data[krow][kcol];
        else{
            std::cerr << "Invalid index" << std::endl;
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
    Matrix<double, 3, 4> matrix(1);
    return 0;
}