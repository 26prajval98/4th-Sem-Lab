#include <iostream>

using namespace std;

class And{
    float w0, w1, threshold, alpha,sum;
    int output;
    public:
    And(float a, float b){
        w0 = a;
        w1 = b;
    }
    void trainAnd(int input[4][3]){
        threshold = 0.0;
        alpha = 0.01;
        for (int i = 0; i < 4; i++) {
            while (1) {
                sum = input[i][0] * w0 + input[i][1] * w1;

                if(sum >= threshold) {
                    output = 1;
                }
                else {
                    output = 0;
                }

                if (output != input[i][2]) {
                    w0 = w0 + (alpha) * (input[i][2] - output) * input[i][0];
                    w1 = w1 + (alpha) * (input[i][2] - output) * input[i][1];

                    threshold = threshold - (alpha) * (input[i][2] - output);
                }
                else
                    break;
            }
        }
        cout<<"Threshold is = "<<threshold<<" W0 = "<<w0<<" W1 = "<<w1<<endl;

    };
    bool isAnd(int a, int b){
        if(a*w0+b*w1>=threshold){
            return true;
        }
        else{
            return false;
        }
    }

};

int main () {

    int input[4][3] = { 0, 0, 0,        // AND table logic
                        0, 1, 0,
                        1, 0, 0,
                        1, 1, 1 };

    int x1, x2;

    class And P(0.3,0.1);
    P.trainAnd(input);

    cout<<"Enter two inputs"<<endl;
    cin>>x1>>x2;

    if(P.isAnd(x1,x2)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
