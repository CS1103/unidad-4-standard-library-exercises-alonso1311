#include<iostream>

using namespace std;

void Little() {
    int number;
    cin >> number; cin.ignore();

    cout << endl;

    int convert = number << 24 | ((255 << 8) & number) << 8 
            | ((255 << 16) & number) >> 8 | (number >> 24) & 255;

    cout << number << " converts to " << convert << '\n';
}
