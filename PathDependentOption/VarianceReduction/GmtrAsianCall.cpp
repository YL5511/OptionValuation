//
//  GmtrAsianCall.cpp
//  VarianceReduction
//
//  Created by Julia on 2018/11/11.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "GmtrAsianCall.hpp"

#include <cmath>
#include"EurCall.hpp"

double Normal(double x)
{
    double gamma = 0.2316419;    double a1 = 0.319381530;
    double a2    =-0.356563782;       double a3 = 1.781477937;
    double a4    =-1.821255978;       double a5 = 1.330274429;
    double pi    = 4.0*atan(1.0);        double k  = 1.0/(1.0+gamma*x);
    if (x>=0.0)
    {
        return 1.0-((((a5*k+a4)*k+a3)*k+a2)*k+a1)*k*exp(-x*x/2.0)/sqrt(2.0*pi);
    }
    else return 1.0-Normal(-x);
}

double GmtrAsianCall::Payoff(SamplePath& S)
{
    double Prod=1.0;
    for (int i=0; i<m; i++)
    {
        Prod=Prod*S[i];
    }
    if (pow(Prod,1.0/m)<K) return 0.0;
    return pow(Prod,1.0/m)-K;
}

double GmtrAsianCall::PriceByBSFormula(BSModel Model)
{
    double a = exp(-Model.r*T)*Model.S0*exp(
                                            (m+1.0)*T/(2.0*m)*(Model.r+Model.sigma*Model.sigma
                                                               *((2.0*m+1.0)/(3.0*m)-1.0)/2.0));
    double b = Model.sigma*sqrt((m+1.0)*(2.0*m+1.0)/(6.0*m*m));
    EurCall G(T, K);
    Price = G.PriceByBSFormula(a,b,Model.r);
    ;
    delta=Normal(G.d_plus(a, b, Model.r))*a/Model.S0;
    
    return Price;
}

