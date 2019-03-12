//
//  GmtrAsianCall.hpp
//  VarianceReduction
//
//  Created by Julia on 2018/11/11.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef GmtrAsianCall_hpp
#define GmtrAsianCall_hpp
#include "PathDepOption04.hpp"

class GmtrAsianCall: public PathDepOption
{
public:
    double K;
    GmtrAsianCall(double T_, double K_, int m_)
    {T=T_; K=K_; m=m_;}
    double Payoff(SamplePath& S);
    double PriceByBSFormula(BSModel Model);
};
#endif /* GmtrAsianCall_hpp */
