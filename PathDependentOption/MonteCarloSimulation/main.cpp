//
//  main.cpp
//  MonteCarloSimulation
//
//  Created by Julia on 2018/11/10.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include <iostream>
#include"BSModel01.hpp"
#include "PathDepOption01.hpp"
using namespace std;

int main()
{
    double S0=100.0, r=0.03, sigma=0.2;
    BSModel Model(S0,r,sigma);
    
    double T=1.0/12.0, K=100.0;
    int m=30;
    ArthmAsianCall Option(T,K,m);
    
    long N=30000;
    double epsilon=0.001;
    cout << "Asian Call Price = " << Option.PriceByMC(Model,N,epsilon) << endl;
    cout << "Error = " << Option.PriceError << endl;
    cout<<"Delta = "<<Option.delta<<endl;
    cout<<"Gamma = "<<Option.gamma<<endl;;
    return 0;
}

//Asian Call Price = 1.43478

