#include <iostream>

using namespace std;

class TestClass {
public:
        enum TestEnum {
                ENUM0 = 0,
                ENUM1,
                ENUMNUM
        };
};

int fn(TestClass::TestEnum e) {return (int)e;}

int main(int argc, char* argvs[]) {
        cout << "Test Enum" << endl;
    cout << TestClass::ENUMNUM << endl;
        cout << fn(TestClass::ENUM0) << endl;
        //error cout << fn(3) << endl;

        for(int i = 0; i < TestClass::ENUMNUM; i++) {
                cout << i << endl;
        }
        return 0;
}
