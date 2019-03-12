//
//  SpreadOption.cpp
//  digitoptin
//
//  Created by Julia on 2018/10/14.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "SpreadOption.hpp"
#include <iostream>
using namespace std;
int SpreadOpt::GetInputData()
{     cout << "Enter Strangle option option data:" << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin >> N;
    SetN(N);
    cout << "Enter parameter K1:      "; cin >> K1;
    cout << "Enter parameter K2:      "; cin >> K2;
    cout << endl;
    return 0;
}
double SpreadOpt::Payoff(double z)
{      if ( z>K1 && z<((K1+K2)/2)) return z-K1;
else if(z>((K1+K2)/2) && z<K2) return K2-z;
else return 0.0;
    
}
