#include<iostream>
using namespace std;
template<typename T>void counts();
template <typename T>void reports(T &t);

template<typename T>
class HasFriend{
private:
    T item;
    static int ct;
public:
    HasFriend(const T&t):item(t){ct++;}
    ~HasFriend(){
        ct--;
    }
    friend void counts<T>();
    friend void reports<HasFriend <T>>(HasFriend<T>&t);
};
template<typename T>
void counts(){
    cout<<HasFriend<T>::ct<<endl;
}
template<typename T>
void reports(T &t){
    cout<<t.item<<endl;
}
template<typename T>
 int HasFriend<T>::ct = 0;
int main(){
    HasFriend<int> friend1(10);
    HasFriend<int>friend2(20);
    HasFriend<double>friend3(20.1);
    counts<int>();
    counts<double>();
    reports<HasFriend<int>>(friend1);
    reports<HasFriend<double>>(friend3);
    

}