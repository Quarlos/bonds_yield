//
//  main.cpp
//  bonds
//  Computes de price, duration, and convexity of a bond given the cash flow dates, the cash flow, and the yield
//  Press return after entering all values (with no space at the end)
//
//  Created by carlos on 20/11/2018.
//  Copyright © 2018 carlos. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#include <iomanip> // to use setprecision() so that std output gives me more decimal places

int main() {
    
    //    int n;
    
    //    cout << "bond maturity: ";
    //    cin >> T;
    //    cout << "number of cash flows: ";
    //    cin >> n;
    
    //    double t_cash_flow[n], v_cash_flow[n];
    
    //    cout << "vector of cash flow dates: ";
    //    for(unsigned long i=0; i < n; i++) {
    //        cin >> t_cash_flow[i];
    //    }
    //
    //    cout << "vector of cash flows: ";
    //    for(unsigned long i=0; i < n; i++) {
    //        cin >> v_cash_flow[i];
    //    }
    //
    
    vector <double> t_cash_flow, v_cash_flow;
    double t, v;
    cout << "vector of cash flow dates: ";
    
    cin >> t;
    t_cash_flow.push_back(t);
    while(cin.get() != '\n') {
        cin >> t;
        t_cash_flow.push_back(t);
    }
    
    cout << "vector of cash flows: ";
    cin >> v;
    v_cash_flow.push_back(v);
    while(cin.get() != '\n') {
        cin >> v;
        v_cash_flow.push_back(v);
    }
    
    double y;
    cout << "yield of the bond: ";
    cin >> y;
    
    double B=0, D=0, C=0;
    vector <double> disc(t_cash_flow.size());
    
    for(unsigned long i=0; i < t_cash_flow.size(); i++) {
        disc[i] = exp(-t_cash_flow[i]*y);
        B += v_cash_flow[i]*disc[i];
        D += t_cash_flow[i]*v_cash_flow[i]*disc[i];
        C += (t_cash_flow[i]*t_cash_flow[i])*v_cash_flow[i]*disc[i];
    }
    D = D/B;
    C = C/B;
    
    cout << "\nprice of the bond B = " << setprecision (8) << B << endl;
    cout << "duration of the bond D = " << setprecision (8) << D << endl;
    cout << "convexity of the bond C = " << setprecision (8) << C << endl;
    
    return 0;
}
