// #include<iostream>

// using namespace std;
// void solve(){

    
//    int n;
//    cout <<" Enter no of Buyers in 1 line :"<< endl;
//     cin >> n ;
//    int count5 = 0;
//    int count10 = 0;
//    int possible = true;
//    for(int i = 0; i < n ; ++i){
//         int bill;
//         cin >> bill;

//         if (!possible) continue;

//         if (bill == 5){
//             count5++;
//         }else if (bill == 10){
//             if (count5 > 0 ){
//                 count5--;
//                 count10++;
//             }else{
//                 possible = false;
//             }
//         }
//         else{
//             if (count10 > 0 && count5 > 0 ){
//                 count10--;
//                 count5++;
//             }else if (count5 >= 3){
//                 count5 -= 3;
//             }else{
//                 possible = false;
//             }
//         }
//     }

//     if (possible){
//         cout << "yes\n";
//     }else{
//         cout << "No\n";
//     }
    
// }


// int main (){
// int t;
// cout <<" Enter number of lines :" << endl ;

// cin >> t;
// while(t--){
//     solve();
// }


// return 0;
// }

#include <iostream>

// This function solves a single test case.
void solve() {
    int n;
    std::cin >> n;

    int count5 = 0;
    int count10 = 0;
    bool possible = true; // Using bool for true/false is more idiomatic in C++.

    for (int i = 0; i < n; ++i) {
        int bill;
        std::cin >> bill;

        // We only need to process the logic if it's still possible to give change.
        // We still need to read all the inputs for the current test case regardless.
        if (possible) {
            if (bill == 5) {
                count5++;
            } else if (bill == 10) {
                // To give change for a $10 bill, we need one $5 bill.
                if (count5 > 0) {
                    count5--;
                    count10++;
                } else {
                    possible = false;
                }
            } else { // Bill is 20
                // To give change for a $20 bill, we have two options.
                // Option 1 (preferred): One $10 bill and one $5 bill.
                if (count10 > 0 && count5 > 0) {
                    count10--;
                    count5--;
                // Option 2: Three $5 bills.
                } else if (count5 >= 3) {
                    
                    count5 -= 3;
                } else {
                    possible = false;
                }
            }
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // These lines make C++ input/output faster, which is useful in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        solve();
    }

    return 0;
}
