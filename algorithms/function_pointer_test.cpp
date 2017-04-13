#include <iostream>
#include <memory>
#include <tr1/functional>
#include <tr1/memory>

using namespace std;

//////////////////////////////////////
template <
    typename R,
    typename ClassName,
    typename Arg0
>
class TemplateTest {
public:
    typedef R(ClassName::*Method)(Arg0);
    TemplateTest(ClassName* pobj, Method pmethod, Arg0 arg0) : m_pobj(pobj),m_pmethod(pmethod),p_arg0(arg0) {}
    R Run () {
        return (m_pobj->*m_pmethod)(p_arg0);
    }
private:
    ClassName* m_pobj;
    Method m_pmethod;
    Arg0 p_arg0;
};


class FptrExample {
public:
    int Func1(int in = 0) {return (in + 1);}

};


typedef int(FptrExample::*fptr1_type) (int);

template<typename R, typename ClassName, typename Arg0>
TemplateTest<R, ClassName, Arg0>* NewTemplateTest(ClassName* pobj, R (ClassName::*method)(Arg0), Arg0 arg0) {
    return new TemplateTest<R, ClassName, Arg0> (pobj, method, arg0);
}
///////////////////

////////////

class BindTest {
public:
    typedef std::tr1::function<int (int)>   Tr1FuncPtr;
    Tr1FuncPtr m_tr1funcptr;
};

template<
    typename R,
    typename Arg0
>
class BindTemplateTest {
    typedef std::tr1::function<R (Arg0) > Tr1TemplateFuncPtr;
public:
    Tr1TemplateFuncPtr m_tr1funcptr;
};
////////////



int main(int argc, char** argvs) {
    cout << "Hellow World!" << endl;
    FptrExample fexample;

    //(1) -- using the very basic pointer
    fptr1_type f = &FptrExample::Func1;
    cout << (fexample.*f)(1) << endl;

    //(2) -- using the template
    TemplateTest<int,FptrExample,int> ttest(&fexample, &FptrExample::Func1, 2);
    cout << ttest.Run() << endl;

    //(3) -- using the smart pointer
    std::auto_ptr<TemplateTest<int, FptrExample,int> > ptest(NewTemplateTest(&fexample, &FptrExample::Func1, 3));
    cout << ptest->Run() << endl;

    //(4) -- using tr1::function and tr1::bind
    BindTest bt1;
    bt1.m_tr1funcptr = std::tr1::bind(&FptrExample::Func1, &fexample, std::tr1::placeholders::_1);
    cout << bt1.m_tr1funcptr(4) << endl;

    //(5) -- using templete and tr1::function tr1::bind
    BindTemplateTest<int, int> btt1;
    btt1.m_tr1funcptr = std::tr1::bind(&FptrExample::Func1, &fexample, std::tr1::placeholders::_1);
    cout << btt1.m_tr1funcptr(5) << endl;
}
