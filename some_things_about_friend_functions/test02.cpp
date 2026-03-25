#include<iostream>
using namespace std;
template<typename T>
class Box1{
private:
    T value;
    int num;
public:
    Box1(const T &v):value(v){}
    template<typename X, typename Y>
    friend void peek(const Box1<X>& a, const Box1<Y>& b);
};
template<typename T,typename U>
 void peek(const Box1<T>&a,const Box1<U>&b){
    cout<<"value1 = "<<a.value<<endl;
    cout<<"value2 = "<<b.value<<endl;
}

int main(){
    Box1<int> box1(10);
    Box1<double> box2(20.1);
    peek(box1,box2);

}