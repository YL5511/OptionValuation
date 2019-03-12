//
//  EurCall.hpp
//  VarianceReduction
//
//  Created by Julia on 2018/11/13.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef EurCall_hpp
#define EurCall_hpp

#include <stdio.h>
class EurCall
{
public:
    double T, K;
    EurCall(double T_, double K_){T=T_; K=K_;}
    double d_plus(double S0, double sigma, double r);
    double d_minus(double S0, double sigma, double r);
    double PriceByBSFormula(double S0, double sigma, double r);
    double VegaByBSFormula(double S0, double sigma, double r);
};


#endif /* EurCall_hpp */
