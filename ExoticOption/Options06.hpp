//
//  Options06.hpp
//  digitoptin
//
//  Created by Julia on 2018/10/14.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef Options06_hpp
#define Options06_hpp
#include "BinModel02.hpp"

#include <stdio.h>
class EurOption
{
private:
    int N;
public:
    void SetN(int N_){N=N_;}
    
    virtual double Payoff(double z){return 0.0;}
    
    double PriceByCRR(BinModel Model);
};
class Call: public EurOption
{
private:
    double K; //strike price
public:
    void SetK(double K_){K=K_;}
    int GetInputData();
    double Payoff(double z);
};
class Put: public EurOption
{
private:
    double K; //strike price
public:
    void SetK(double K_){K=K_;}
    int GetInputData();
    double Payoff(double z);
};

#endif
