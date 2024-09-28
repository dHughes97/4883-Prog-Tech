/**
* Delton Hughes
* UVA Online Judge Username - dHughes97
* 4883 Programming Techniques 
* 8/31/2024
* Submission ID - Submission received with ID 29738463
*/
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    long A = 0, B = 0;

    
    while (cin >> A >> B) {
        
        long difference = abs(A - B);

        cout << difference << endl;
    }
    return 0;
}