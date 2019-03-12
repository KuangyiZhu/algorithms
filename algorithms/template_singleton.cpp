#include<iostream>
#include<memory>


using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;


template<
typename T,
typename ...A
> class Singleton {
private:
    static shared_ptr<T>  instance;
public:
    static shared_ptr<T> Get_Instance(A... args) {
	if(instance == nullptr) {
	    instance = make_shared<T>(args...);
	}
	return instance;
    }
};

template<typename T, typename ...A> shared_ptr<T> Singleton<T, A...>::instance;

template<typename T, typename ...A> inline shared_ptr<T> Get_Singleton(A... args) {
    return Singleton<T, A...>::Get_Instance(args...);
}

/////////////////////////////////////////////////////////////////////

class A {
private:
    int i;
public:
    //A() {this->i = 0;}
    void Ecoh() {cout << "class A " << i << endl;}

};

class B {
private:
    int i;
public:
    B(int i) {this->i = i;}
    void Ecoh() {cout << "class B " << i << endl;}

};

////////////////////////////////////////////////////////////////////

int main(int argc, char ** argvs) {
    shared_ptr<A> p_a = ::Get_Singleton<A>();
    shared_ptr<B> p_b = ::Get_Singleton<B, int>(1);

    p_a->Ecoh();
    return 0;
}
