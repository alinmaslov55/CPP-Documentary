#include <iostream>

class Complex {
    float re , im;
    public:
        Complex(float re=0.0f, float im=0.0f){
            this->re = re;
            this->im = im;   
        }
        void setRe(const float& re){
            this->re = re;
        }
        void setIm(const float& im){
            this->im = im;
        }
        float getRe() const {
            return this->re;
        }
        float getIm() const {
            return this->im;
        }
        Complex operator+(const Complex& other){
            return Complex(re+other.re, im+other.im);
        }
        Complex operator*(const Complex& other){
            float nre, nim;
            //(a+bi)⋅(c+di)=(ac−bd)+(ad+bc)i
            nre = re*other.re - im*other.im;
            nim = re*other.im + im*other.re;
            return Complex(nre, nim);
        }
        friend std::ostream& operator<<(std::ostream& os, const Complex& object);
};
std::ostream& operator<<(std::ostream& os, const Complex& object){
    os << "( " << object.re << " + " << object.im << "i )";
    return os;
}
int main(){
    Complex first(3.4f, 5.0f);
    Complex second(4.5f, 6.0f);

    std::cout << first + second << std::endl;
    std::cout << first * second << std::endl;



    return 0;
}