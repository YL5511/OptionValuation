//
//  Option07.hpp
//  main12
//
//  Created by Julia on 2018/11/6.
//  Copyright © 2018年 Julia. All rights reserved.
/*
There is multi inheritance. 
1. The EurOption class and AmeOption  class are sub classes from the Option class by virtual inheritance. By doing so, we can guarantee a single copy of  N and other member of Option class. 
2. Put and Call are subclass of EurOption and AmeOption
*/

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
    virtual double Payoff(double z)=0;  // Payoff is pure virtual function of the Option class. 
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
