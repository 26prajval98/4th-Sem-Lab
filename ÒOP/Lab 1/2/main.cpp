#include <iostream>
#include <cstring>
using namespace std;

class person{

    private:
        int age;
        char name[];
    public:
        void getAgeName(void){
            int a;
            cout<<"Enter age and name\n";
            cin>>a>>name;
            age = a;
            cout<<"Thanks!!\n";
        };
        void printAgeName(void){
            cout<<"Age: "<< age <<" and name: "<< name <<"\n";
        }

};

int main()
{
    person *P1 = new person();
    P1->getAgeName();
    P1->printAgeName();
    delete P1;
    P1->printAgeName();
    //cout << "Hello world!" << endl;
    return 0;
}
