//
//  BinModel02.hpp
//  digitoptin
//
//  Created by Julia on 2018/10/14.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef BinModel02_hpp
#define BinModel02_hpp

#include <stdio.h>
class BinModel
{
private:
    double S0;
    double U;
    double D;
    double R;
public:
    //computing risk-neutral probability
    double RiskNeutProb();
    //computing the stock price at node n,i
    double S(int n, int i);
    //inputting, displaying and checking model data
    int GetInputData();
    double GetR();
}; 
#endif /* BinModel02_hpp */
