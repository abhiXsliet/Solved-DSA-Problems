// https://www.naukri.com/code360/guided-paths/oops-in-c/content/274160/offering/3757742




#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

class ComplexNumbers {
    int real, img;
public:
    ComplexNumbers(int real, int img) {
        this -> real = real;
        this -> img  = img;
    }

    void plus(ComplexNumbers const &c) {
        real += c.real;
        img  += c.img;
    }

    void multiply(ComplexNumbers const &c) {
        int nReal = (c.real * real) - (img * c.img);
        int nImg  = (real * c.img) + (img * c.real);
        real = nReal;
        img  = nImg;
    }
    
    void print() {
        cout << real << " + " << "i" << img << endl;
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}