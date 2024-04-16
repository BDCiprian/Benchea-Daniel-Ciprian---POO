#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int year;
    string brand;
    string model;
public:
    
    Car() {};
    Car(int y, string b, string m) : year(y), brand(b), model(m) {
        cout << "Constructor called" << endl;
    }

    
    ~Car() {
        cout << "Destructor called" << endl;
    }

    void displayInfo() {
        cout << "Anul: " << year << ", Marca: " << brand << ", Modelul: " << model << endl;
    }
};

int main() {
    int n;
    cout << "Introduceti numarul de masini: ";
    cin >> n;

    Car* cars = new Car[n];

    for (int i = 0; i < n; ++i) {
        int year;
        string brand, model;
        cout << "Introduceti anul, marca si modelul masinii " << i + 1 << ": ";
        cin >> year >> brand >> model;
        cars[i] = Car(year, brand, model);
    }

    
    for (int i = 0; i < n; ++i) {
        cars[i].displayInfo();
    }

    delete[] cars; 

    return 0;
}