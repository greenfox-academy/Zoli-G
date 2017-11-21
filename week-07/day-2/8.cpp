#include <stdio.h>
#include <iostream>

// This below is an example of using operators and overloading them.
// Check it out and see which ones I've implemented outside of the class and which are within the class.
// Understand this code and play around with it.

class Integer {
    private:
        int mInt;
    public:
        Integer(){
            mInt = 0;
        }
        Integer(Integer& _other){
            mInt = _other.mInt;
        }
        Integer(int _num){
            mInt = _num;
        }
        void set(int _i){
            mInt = _i;
        }
        int get(){
            return mInt;
        }

        void add(Integer& _other){
            mInt += _other.mInt;
        }

        void add(int _num){
            mInt += _num;
        }
        Integer& operator + (Integer& _other){
            mInt += _other.mInt;
            return *this;
        }

        Integer& operator + (int _num){
            mInt += _num;
            return *this;
        }
};

std::ostream& operator<< (std::ostream& _stream, Integer& _integer){
    _stream << _integer.get();
    return _stream;
}

int main(){
    Integer a;
    a.set(12);
    Integer b(1);
    Integer c(a);
    printf("a: %d, b: %d, c: %d\n",a.get(), b.get(), c.get());
    a.add(b);
    c.add(12);
    printf("a + b: %d\nc + 12: %d\n",a.get(),c.get());
    printf("a + b: %d\nc + 12: %d\n", (a + b).get(), (c + 12).get());
    printf("a + b + c + 42: %d\n", (a + b + c + 12).get());
    std::cout << "a printed with stream: " << a << " " << b << " " << c << std::endl;
    return 0;
}
