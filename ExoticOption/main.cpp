//
//  main.m
//  digitoptin
//
//  Created by Julia on 2018/10/14.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "BinModel02.hpp"
#include "Options06.hpp"
#include "DoubDigitOpt.hpp"
#include "StrangleOpt.hpp"
#include "SpreadOption.hpp"
using namespace std;

int main()
{
    BinModel Model;
    if (Model.GetInputData()==1)
        return 1;

    Call Option1;
    Option1.GetInputData();
    cout << "European call option price = "  << Option1.PriceByCRR(Model) << endl << endl;
    
    Put Option2;
    Option2.GetInputData();
    cout << "European put option price = "  << Option2.PriceByCRR(Model)  << endl << endl;
    
    DoubDigitOpt Option3;
    Option3.GetInputData();
    cout << "European double-digital option price = "  << Option3.PriceByCRR(Model)  << endl << endl;
    
    StrangleOpt Option4;
    Option4.GetInputData();
    cout << "European double-digital option price = "  << Option4.PriceByCRR(Model)  << endl << endl;
    
    SpreadOpt Option5;
    Option5.GetInputData();
    cout << "European double-digital option price = "  << Option5.PriceByCRR(Model)  << endl << endl;
    return 0;
    
   
}
/*
Enter S0: 106
Enter U:  0.1525
Enter D:  -0.13138
Enter R:  0.00545

Input data checked
There is no arbitrage

Enter call option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European call option price = 21.7726

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European put option price = 11.5176

Enter double-digital option data:
Enter steps to expiry N: 8
Enter parameter K1:      100
Enter parameter K2:      110

European double-digital option price = 0.260448

Enter Strangle option option data:
Enter steps to expiry N: 8
Enter parameter K1:      100
Enter parameter K2:      110

European double-digital option price = 28.4991

Enter Strangle option option data:
Enter steps to expiry N: 8
Enter parameter K1:      100
Enter parameter K2:      110

European double-digital option price = 0.921831

Program ended with exit code: 0
*/
