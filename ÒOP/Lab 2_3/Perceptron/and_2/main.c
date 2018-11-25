#include <iostream>

using namespace std;

class And{
    float w0, w1, threshold, alpha;
    int output;
    public:
    void trainAnd(int input**){
        threshold = 0.0;
        alpha = 0.01;
        w0 = 0.3;
        w1 = 0.1;
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
        cout<<"Threshold is = "<<threshold<<endl;

    }

};

int main () {

    int input[4][3] = { 0, 0, 0,        // AND table logic
                        0, 1, 0,
                        1, 0, 0,
                        1, 1, 1 };

    int x1, x2;

    cout<<"Enter weight 1: ";
    cin>>w0;

    cout<<"Enter weight 2: ";
    cin>>w1;

    cout<<"Checking if weights are correct:\n";
    cout<<"Enter two inputs for the AND gate:\n";
    cin>>x1>>x2;

    // cout<<"result = "<<res<<endl;
    if(res >= threshold)
        output = 1;
    else
        output = 0;

    cout<<"Output = "<<output<<endl;

    return 0;
}
