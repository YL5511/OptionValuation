//
//  Option07.cpp
//  Main12
//
//  Created by Julia on 2018/11/6.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "Option07.hpp"
#include"Binmodel02.hpp"
#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

double EurOption::PriceByCRR(BinModel Model){
    vector<double > Price(N+1);
    double q=Model.RiskNeutProb();
    for (int i=0; i<=N; i++) Price[i]=Payoff(Model.S(N,i));
    
    for (int n=N-1; n>=0; n--)
    {
        for (int i=0; i<=n; i++)
        {
            Price[i]=(q*Price[i+1]+(1-q)*Price[i]) /(1+Model.GetR());
        }
    }
    return Price[0];
}
double AmeOption::PriceBySnell(BinModel Model)
{
    double q=Model.RiskNeutProb();
    vector<double> Price(N+1);
    double PayOffVal = 0.0;
    for (int i=0; i<=N; i++)
    {
        Price[i]=Payoff(Model.S(N,i));
    }
    for (int n=N-1; n>=0; n--)
    {
        for (int i=0; i<=n; i++)
        {
            Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+Model.GetR());
            PayOffVal=Payoff(Model.S(n,i));
            if (PayOffVal>Price[i]) Price[i]=PayOffVal;
        }
    }
    return Price[0];
}

void Call::GetInputData(){
    cout<<"K:"; cin>>K;
    int n;
    cout<<"N:";cin>>n;
    EurOption::setN(n);
    AmeOption::setN(n);
}

double Call::Payoff(double z){
    if (z>K) return z-K;
    else return 0;
}


