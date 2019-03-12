//
//  Binmodel02.hpp
//  test
//
//  Created by Julia on 2018/11/6.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef Binmodel02_hpp
#define Binmodel02_hpp

#include <stdio.h>
using namespace std;
class BinModel
{
private:
    double S0; // spot price
    double U; //upward rate
    double D; //downward rate
    double R; //riskfree rate
public:
    
    double RiskNeutProb(); //calculate the risk neutral probability 
    double S(int n, int i); // calculate the stock price at node(n,i)
    int GetInputData();
    double GetR();
};

#endif /* Binmodel02_hpp */
