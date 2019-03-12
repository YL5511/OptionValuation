//
//  PathDepOption01.cpp
//  MonteCarloSimulation
//
//  Created by Julia on 2018/11/10.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "PathDepOption01.hpp"
#include <cmath>
using namespace std;
void Rescale(SamplePath &S, double x){
    auto m=S.size();
    for (int i=0;i<=m;i++){S[i]=x*S[i];}
}
double PathDepOption::PriceByMC(BSModel Model, long N,double epsilon)
{  double H=0.0;
    double Hsq=0.0;
    double Heps=0.0;
    double Hmeps=0.0;
    SamplePath S(m);
    for(long i=0; i<N; i++)
    { Model.GenerateSamplePath(T,m,S);
        H = (i/(i+1.0))*H + Payoff(S)/(i+1.0);
        Hsq=(i/(i+1.0))*Hsq + pow(Payoff(S), 2)/(i+1.0);
        Rescale(S,1+epsilon);
        Heps= (i/(i+1.0))*Heps + Payoff(S)/(i+1.0);
     Rescale(S,(1-epsilon)/(1+epsilon));
        Hmeps= (i/(i+1.0))*Hmeps + Payoff(S)/(i+1.0);
    }
    
    PriceError=exp(-Model.r*T)*sqrt(Hsq-H*H)/sqrt(N-1.0);
    delta=exp(-Model.r*T)*(Heps-H)/(Model.S0*epsilon);
    gamma=exp(-Model.r*T)*(Heps-2*H+Hmeps)/pow(Model.S0*epsilon,2);
    return exp(-Model.r*T)*H;
}
double ArthmAsianCall::Payoff(SamplePath& S)
{  double Ave=0.0;
    for (int k=0; k<m; k++) Ave=(k/(k+1.0))*Ave+S[k]/(k+1.0);
    if (Ave<K) return 0.0;
    return Ave-K;
}

double EurCall::Payoff(SamplePath &S){
    if(S[m-1]<K) return 0.0;
    else return S[m-1]-K;
}

