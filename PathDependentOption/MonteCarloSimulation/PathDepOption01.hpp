//
//  PathDepOption01.hpp
//  MonteCarloSimulation
//
//  Created by Julia on 2018/11/10.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef PathDepOption01_hpp
#define PathDepOption01_hpp

#include <stdio.h>
#include "BSModel01.hpp"

class PathDepOption
{
public:
    int m;
    double T,PriceError,delta,gamma;
    double PriceByMC(BSModel Model, long N,double epsilon);
    virtual double Payoff(SamplePath& S)=0;
};


class ArthmAsianCall: public PathDepOption
{
public:
    double K;
    ArthmAsianCall(double T_, double K_, int m_)
    {T=T_; K=K_; m=m_;}
    double Payoff(SamplePath& S);
};

class EurCall: public PathDepOption
{
public:
    double K;
    EurCall(double T_, double K_, int m_)
    {T=T_; K=K_; m=m_;}
    double Payoff(SamplePath& S);
};


#endif /* PathDepOption01_hpp */
