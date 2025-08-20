#include<iostream>
using namespace std;

int main(){
    float rainfall[3][4];
    float ave_rainfall = 0;
    float total = 0;

    cout << "Enter rainfall data for 3 cities (in mm)\n";

 
    for(int c = 0; c < 3; c++){
        cout << "\nEnter data for City " << c + 1 << ":\n";
        for(int m = 0; m < 4; m++){
            cout << "  Month " << m + 1 << ": ";
            cin >> rainfall[c][m];
        }
    }

    // Output 
    cout << "\nRainfall Tracking Report:\n\n";
    cout << "Sr.No.  City Name    Month1  Month2  Month3  Month4  Avg_Rainfall\n";

    for(int c = 0; c < 3; c++){
        total = 0;
        cout << c + 1 << "       City " << c + 1 << "      ";
        for(int m = 0; m < 4; m++){
            cout << rainfall[c][m] << "     ";
            total += rainfall[c][m];
        }
        ave_rainfall = total / 4;
        cout << ave_rainfall << "\n";
    }

    return 0;
}
