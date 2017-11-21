#include <iostream>
using namespace std;

// Create a class Float based on the examples from the two previous
// files and Your experiences from before.
// Try out all it's functions incrementally and print out the results in main().
// Good coding! :)
class Float {
    private:
        float mFl;
    public:
        Float(){
            mFl = 0;
        }
        Float(Float& _other){
            mFl = _other.mFl;
        }
        Float(float _num){
            mFl = _num;
        }
        void set(float _i){
            mFl = _i;
        }
        float get(){
            return mFl;
        }

        void add(Float& _other){
            mFl += _other.mFl;
        }

        void add(float _num){
            mFl += _num;
        }
        Float& operator + (Float& _other){
            mFl += _other.mFl;
            return *this;
        }

        Float& operator + (float _num){
            mFl += _num;
            return *this;
        }
};

std::ostream& operator << (std::ostream& _stream, Float& _float){
    _stream << _float.get();
    return _stream;
}
float operator + (float _num, Float& _float) {
    return _num + _float.get();
}

int main() {

    Float a;
    a.set(6.89);
    Float b(122.5);
    Float c(a);
    printf("a: %g, b: %g, c: %g\n", a.get(), b.get(), c.get());
    a.add(b);
    c.add(22.567);
    Float d(122.999);
    printf("a + b: %g\nc + 12: %g\n", a.get(), c.get());
    printf("a + b: %g\nc + 12: %g\n", (a + b).get(), (c + 12).get());
    printf("a + b + c + 42: %g\n", (a + b + c + 12).get());
    std::cout << "a printed with stream: " << a << " " << b << " " << c << std::endl;
    std::cout << "testing + operator: " << 12 + d << std::endl;
    std::cout << "testing + operators: " << a + 12 + d << std::endl;

    return 0;
}
