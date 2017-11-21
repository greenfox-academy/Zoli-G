#include <iostream>
#include <stdio.h>

using namespace std;

//function overloading
int get_area(int h, int l) {
	return l * h;
}

float get_area(int r) {
	return r * r * 3.14;
}

//not working
//float get_area(int b, int h) {
//	return b * h / 2;
//}
float get_area(float b, int h) {
	return b * h / 2;
}

int main() {

}