#include <iostream>

#include "../offline_alloc_proj_trunk/dev/common/base/closure.h"

using namespace std;


//
class FptrExampleBase {
        public:
                virtual int Test(int) = 0;
};




//
class TestClass {
        public:
                TestClass(int arg1, int arg2):placeholder(NULL),protected_int(arg1), private_int(arg2) {}
                Closure<int, int>* placeholder;
                //error Closure<int, TestClass&>* placeholder2;

                int SafeExecutor(int param) {
                        int result = 0;
                        if(placeholder) {result = (placeholder)->Run(param);}
                        placeholder = NULL;
                }

                template<typename ClassName> struct BindHelper {
                        typedef int (ClassName::*Method)(int);
                        public:
                            BindHelper() {}
                                static void Bind(TestClass& dest, ClassName *obj, Method method) {
                                        dest.placeholder = NewClosure(obj, method);
                                }
                };

        typedef int (FptrExampleBase::*FptrType)(int);
                void BindTest(FptrExampleBase* obj/*, FptrType method*/) {
                        //placeholder = NewClosure(obj, method);
                }

                int Run(int param) { if(placeholder) {return ((placeholder)->Run(param));}}
                int Run() {
                        if(placeholder) {cout << protected_int << "->test protected:" << (placeholder)->Run(protected_int) << endl;} else {cout << "closure is null" << endl;}
                        //cout << private_int << "->test private:" << (placeholder)->Run(private_int) << endl;


                        return 0;
                }

                // error
                /*int Run2() {
                        if(placeholder2) {cout << protected_int << "->reference protected:" << (placeholder2)->Run(*this) << endl;} else {cout << "closure is null" << endl;}
                        return 0;
                }*/
        protected:
                int protected_int;
        private:
                int private_int;
};

//
class FptrExample : public FptrExampleBase {
        public:
                virtual int Test(int val) {return (val + 1);}
                //error virtual int Test2(TestClass& tc) {return (tc.protected_int +1);}

};


//
typedef int (FptrExample::*Fptr) (int) ;

int main (int argc, char** argvs) {
        cout << "Test Closure" << endl;

        FptrExample fexample;
    int i = 1;

        //(1)
        cout << i << "->after exe(i):" << fexample.Test(i) << endl;

        //(2)
        i++;
        Fptr fptr = &FptrExample::Test;
        cout << i << "->after exe(i):" << (fexample.*fptr)(i) << endl;

        //(3)
        i++;
        TestClass tc(i + 1, i + 2);
        tc.placeholder = NewClosure(&fexample, &FptrExample::Test);
        cout << i << "->after exe(i):" << tc.Run(i) << endl;
        tc.placeholder = NewClosure(&fexample, &FptrExample::Test);
        tc.Run();

        TestClass::BindHelper<FptrExample>::Bind(tc, &fexample, &FptrExample::Test);

    //(4)
        //error i++;
        //error TestClass tc2(i + 1, i + 2);
        //error tc2.placeholder2 = NewClosure(&fexample, &FptrExample::Test2);
        //error tc2.Run();
}
