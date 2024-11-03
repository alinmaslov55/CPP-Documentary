#include <iostream>

template<typename T, typename = std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>>>
class Matrix{
    int rows;
    int cols;
    T** data;
    public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for(int i = 0; i < rows; ++i){
            data[i] = new T[cols];
        }
    }
    Matrix(int rows, int cols, int number): rows(rows), cols(cols){
        data = new T*[rows];
        for(int i = 0; i < rows; ++i){
            data[i] = new T[cols];
        }

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; j++){
                data[i][j] = number;
            }
        }
    }
    void set(const int &krow, const int &kcol, const T & value){
        if(krow <= rows - 1 && kcol <= cols - 1 && krow >= 0 && kcol >= 0)
        data[krow][kcol] = value;
        else{
            std::cerr << "Invalid index" << std::endl;
        }
    }
    T get(const int &krow, const int &kcol, const T & value){
        if(krow <= rows - 1 && kcol <= cols - 1 && krow >= 0 && kcol >= 0)
        return data[krow][kcol];
        else{
            std::cerr << "Invalid index" << std::endl;
        }
    }
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U> &some);
    ~Matrix(){
        for(int i = 0; i < rows; i++){
            delete[] data[i];
        }
        delete[] data;
    }
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const Matrix<U> &some){
    for(int i = 0; i < some.rows; ++i){
        for(int j = 0; j < some.cols; ++j){
            os << some.data[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}
int main(){
    Matrix<double> matrix(4, 4, 1);

    std::cout << matrix << std::endl;

    matrix.set(1, 1, 2.5);
    std::cout << matrix << std::endl;

    return 0;
}