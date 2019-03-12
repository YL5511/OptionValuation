//
//  Option07.hpp
//  Main12
//
//  Created by Julia on 2018/11/6.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef Option07_hpp
#define Option07_hpp

#include <stdio.h>
#include "Binmodel02.hpp"

class EurOption{
private:
    int N;
public:
    void setN(int N_){N=N_;}
    virtual double Payoff(double z)=0;
    double PriceByCRR(BinModel Model);
};

class AmeOption{
private:
    int N;
public:
    void setN(int N_){N=N_;}
    virtual double Payoff(double z)=0;
    double PriceBySnell(BinModel Model);
};


class Call: public EurOption, public AmeOption{
private:
    double K;
public:
    void GetInputData();
    double Payoff(double z);
};

#endif /* Option07_hpp */
