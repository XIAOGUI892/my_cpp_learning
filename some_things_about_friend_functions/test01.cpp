#include <iostream>
using namespace std;

template<typename T>
class Hasfriend{
private:
    T item;
    static int ct;
public:
    Hasfriend(const T& i): item(i) {
        ct++;
    }
    ~Hasfriend() { ct--; }
    friend void count();
    friend void reports(Hasfriend<T>& hf);
};

template<typename T>
int Hasfriend<T>::ct = 0;

void count(){
    cout << "int count = " << Hasfriend<int>::ct << endl;
    cout << "double count = " << Hasfriend<double>::ct << endl;
    // 注意非模板友元不是模板函数，不能用<T>;
}

void reports(Hasfriend<int>& hf){
    cout << "int friend says: " << hf.item << endl;
}

void reports(Hasfriend<double>& hf){
    cout << "double friend says " << hf.item << endl;
}

int main(){
    cout << "No objects declared: ";
    count();
    Hasfriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    count();
    Hasfriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    count();
    Hasfriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    count();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    return 0;
}
