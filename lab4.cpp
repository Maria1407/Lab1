#include <iostream>

using namespace std;


int main() {
    int A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;
    if ((A % C==0) & (B % C == 0)) { 
        cout << (A+B)/C << "\n" << endl;
    } 
    if ((A % C==0) & (B % C != 0)) { 
        cout << A/C+B << "\n" << endl;
    } 
    else {
        cout << A-B-C << "\n" << endl;
    }

    int day;
 
    cout << "Input day of week: ";
    cin >> day;
 
    switch (day)
    {
        case 1:
            cout << "Monday" << "\n" << endl;
            break;
        case 2:
            cout << "Tuesday" << "\n" << endl;
            break;
        case 3:
            cout << "Wednesday" << "\n" << endl;
            break;
        case 4:
            cout << "Thursday" << "\n" << endl;
            break;
        case 5:
            cout << "Friday" << "\n" << endl;
            break;
        case 6:
            cout << "Saturday" << "\n" << endl;
            break;
        case 7:
            cout << "Sunday" << "\n" << endl;
            break;
        default:
            cout << "Error!" << "\n" << endl;
            break;
    }






    int num;

    cout << "Enter an integer: ";
    cin >> num;

    if (num > 0){
        cout << num << " - Positive number." << endl;
    }
    
    else {
        cout << num << " - Negative number." << endl;
    }
 
    return 0;
}