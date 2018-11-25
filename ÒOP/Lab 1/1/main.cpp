#include <iostream>
#define PI 3.14
using namespace std;

int geo(int a, int b, int c){
    cout<<"Cuboid selected"<<endl;
    return a*b*c;
};

int geo(int a, int b){
    cout<<"Cylinder selected"<<endl;
    return PI*a*a*b;
};

int geo(int a){
    cout<<"Cube selected"<<endl;
    return a*a*a;
};

int main(){
    int a, b, c;
    int option;
    cout<<"1:Cuboid, 2:Cylinder, 3:Cube\n";
    cin>>option;
    if(option == 1){
        cin>>a>>b>>c;
        cout<<geo(a,b,c);
    }
    else if(option == 2){
        cin>>a>>b;
        cout<<geo(a,b);
    }
    else if(option == 3){
        cin>>a;
        cout<<geo(a);
    }
    else{
        cout<<"Invalid input\n";
    }
    return 0;
}
