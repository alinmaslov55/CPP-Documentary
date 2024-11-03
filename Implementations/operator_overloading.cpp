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
    template<typename U>
    friend Matrix<U> operator+(const Matrix<U> &first, const Matrix<U> &some);
    ~Matrix(){
        for(int i = 0; i < rows; i++){
            delete[] data[i];
        }
        delete[] data;
    }
};

template<typename U>
Matrix<U> operator+(const Matrix<U> &first, const Matrix<U> &some){
    if(first.rows!= some.rows || first.cols!= some.cols){
        std::cerr << "Matrices must have the same dimensions" << std::endl;
        return Matrix<U>(0, 0);
    }
    Matrix<U> result(first.rows, first.cols);
    for(int i = 0; i < first.rows; ++i){
        for(int j = 0; j < first.cols; ++j){
            result.data[i][j] = first.data[i][j] + some.data[i][j];
        }
    }
    return result;
}
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
    Matrix<double> matrix1(4, 4, 1);

    std::cout << matrix1 << std::endl;
    
    Matrix<double> matrix2(4, 4, 2);

    std::cout << matrix2 << std::endl;

    std::cout << matrix1 + matrix2 << std::endl;
    return 0;
}