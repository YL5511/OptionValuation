//
//  StrangleOpt.cpp
//  digitoptin
//
//  Created by Julia on 2018/10/14.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "StrangleOpt.hpp"
#include <iostream>
using namespace std;
int StrangleOpt::GetInputData()
{     cout << "Enter Strangle option option data:" << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin >> N;
    SetN(N);
    cout << "Enter parameter K1:      "; cin >> K1;
    cout << "Enter parameter K2:      "; cin >> K2;
    cout << endl;
    return 0;
}
double StrangleOpt::Payoff(double z)
{      if ( z<K1) return K1-z;
else if(z>K1 && z<K2) return 0;
else return z-K2;
    return 0.0;
}
