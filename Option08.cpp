//
//  Option07.cpp
//  main12
//
//  Created by Julia on 2018/11/6.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "Option08.hpp"
#include "Binmodel02.hpp"
#include <iostream>
#include<cmath>
double EurOption::PriceByCRR(BinModel Model){
    double q=Model.RiskNeutProb();
    int N=GetN();
    
    double Price[N+1]; 
    
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



double AmeOption::PriceBySnell(BinModel Model){
    double q=Model.RiskNeutProb();
    int N=GetN();
    double Price[N+1];
    for (int i=0; i<=N; i++) Price[i]=Payoff(Model.S(N,i));
    
    for (int n=N-1; n>=0; n--)
    {
        for (int i=0; i<=n; i++)
        {
            Price[i]=(q*Price[i+1]+(1-q)*Price[i]) /(1+Model.GetR());
            double temp=Payoff(Model.S(n,i));   // Payoff is virtual function called by *this, *this point to the object
            if (temp>Price[i]) Price[i]=temp;
        }
    }
    return Price[0];
}

void Call::GetInputData(){
    cout<<"K: "; cin>>K;
    int temp;
    cout<<"N: ";cin>>temp;
    SetN(temp);}


double Call::Payoff(double z){
    if (z>K) return z-K;
    else return 0;
}

void Put::GetInputData(){
    cout<<"K: "; cin>>K;
    int temp;
    cout<<"N: ";cin>>temp;
    SetN(temp);}


double Put::Payoff(double z){
    if (z<K) return K-z;
    else return 0;
}




