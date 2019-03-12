//
//  Option07.hpp
//  main12
//
//  Created by Julia on 2018/11/6.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef Option07_hpp
#define Option07_hpp

#include <stdio.h>
#include"Binmodel02.hpp"

class Option
{
private:
    int N;
public:
    void SetN(int N_){N=N_;}
    int GetN(){return  N;}
    virtual double Payoff(double z)=0;
};

class EurOption: virtual public Option
{

public:
    double PriceByCRR(BinModel Model);
};

class AmeOption: virtual public Option
{
public:
    double PriceBySnell(BinModel Model);
};

class Call: public EurOption, public AmeOption
{
private:
    double K;
public:
    void GetInputData();
    double Payoff(double z);
};

class Put: public EurOption, public AmeOption
{
private:
    double K;
public:
    void GetInputData();
    double Payoff(double z);
};

#endif /* Option07_hpp */
