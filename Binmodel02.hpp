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
    double S0;
    double U;
    double D;
    double R;
public:
    
    double RiskNeutProb();
    double S(int n, int i);
    int GetInputData();
    double GetR();
};

#endif /* Binmodel02_hpp */
