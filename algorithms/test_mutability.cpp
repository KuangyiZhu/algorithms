#include <iostream>
#include <vector>

class TestClass {
        public:
                class TestStruct {
                        public:
                                std::vector<int> & m_vtest;
                                const std::vector<int> & im_vtest;

                                TestStruct(std::vector<int> & vtest1, std::vector<int> & vtest2) : m_vtest(vtest1), im_vtest(vtest2) {}
                };

                TestStruct GetTestStruct() {return (TestStruct(_vtest1, _vtest2));}

                void AddTest1(int value) {_vtest1.push_back(value);}
                void AddTest2(int value) {_vtest2.push_back(value);}

                const std::vector<int> & GetTest1() {return _vtest1;}
                const std::vector<int> & GetTest2() {return _vtest2;}
        private:
                std::vector<int> _vtest1;
                std::vector<int> _vtest2;
};


int main(int argc, char** argvs) {
        std::cout << "Test Mutability" << std::endl;

        TestClass tc;

        tc.AddTest1(1);
        tc.AddTest2(2);

        TestClass::TestStruct ts = tc.GetTestStruct();

        std::cout << ts.m_vtest[0] << std::endl;
        std::cout << ts.im_vtest[0] << std::endl;

        ts.m_vtest[0] += 2;
        std::cout << ts.m_vtest[0] << std::endl;

        // error
         ts.im_vtest[0] += 2;
         std::cout << ts.im_vtest[0] << std::endl;



}
