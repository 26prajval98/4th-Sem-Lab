#include <iostream>

class isStatic{
public:
    static int a;
};
using namespace std;
int isStatic :: a = 233;
int main(){
    class isStatic A, B;
    A.a++;
    cout<<B.a;
}
