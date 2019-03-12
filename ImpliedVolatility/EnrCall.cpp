//
//  EnrCall.cpp
//  ImpliedVolatility
//
//  Created by Julia on 2018/11/1.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "EnrCall.hpp"
#include "cmath"


double N(double x)   // calculate the cumulative probability of standard normal distribution
{
    double gamma = 0.2316419;    double a1 = 0.319381530;
    double a2    =-0.356563782;       double a3 = 1.781477937;
    double a4    =-1.821255978;       double a5 = 1.330274429;
    double pi    = 4.0*atan(1.0);        double k  = 1.0/(1.0+gamma*x);
    if (x>0)
    {
        return 1-(a1*k+a2*pow(k, 2)+a3*pow(k, 3)+a4*pow(k, 4)+a5*pow(k, 5))*exp(-x*x*0.5)/sqrt(x*pi);
        
    }
    else return 1.0-N(-x);
}

double EurCall::d_plus(double S0, double sigma, double r){return log(S0/K)+((r+0.5*sigma*sigma)*T)/(sigma*sqrt(T));}

double EurCall::d_minus(double S0,double sigma, double r){return d_plus(S0,sigma,r)-sigma*sqrt(T);}

double EurCall::PriceByFormula(double S0, double sigma, double r)
{
    return S0*N(d_plus(S0, sigma, r))-K*exp(-r*T)*N(d_minus(S0, sigma, r));
}

double EurCall::VegaByFormula(double S0, double sigma, double r){
    return S0*exp(-pow(d_plus(S0, sigma, r), 2)*0.5)/sqrt(2*4.0*atan(1.0));
}
