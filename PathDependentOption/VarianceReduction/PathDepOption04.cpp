//
//  PathDepOption04.cpp
//  VarianceReduction
//
//  Created by Julia on 2018/11/11.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include "PathDepOption04.hpp"
#include<cmath>
using namespace std;
void Rescale(SamplePath &S, double x){
    auto m=S.size();
    for (int i=0;i<=m;i++){S[i]=x*S[i];}
}

double PathDepOption::PriceByMC(BSModel Model, long N)
{  double H=0.0, Hsq=0.0, Heps=0.0;
    SamplePath S(m);
    for(long i=0; i<N; i++)
    {
        Model.GenerateSamplePath(T,m,S);
        H = (i/(i+1.0))*H + Payoff(S)/(i+1.0);
        Hsq = (i/(i+1.0))*Hsq + pow(Payoff(S),2.0)/(i+1.0);
        Rescale(S,1+epsilon);
        Heps= (i/(i+1.0))*Heps + Payoff(S)/(i+1.0);
    }
    
    Price = exp(-Model.r*T)*H;
    PricingError = exp(-Model.r*T)*sqrt(Hsq-H*H)/sqrt(N-1.0);
     delta=exp(-Model.r*T)*(Heps-H)/(Model.S0*epsilon);
    
    return Price;
}
double PathDepOption::PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption)
{
    DifferenceOfOptions VarRedOpt(T,m,this,&CVOption);
    Price = VarRedOpt.PriceByMC(Model,N) + CVOption.PriceByBSFormula(Model);
    PricingError = VarRedOpt.PricingError;
    delta=VarRedOpt.delta+CVOption.delta;
    return Price;
}
double ArthmAsianCall::Payoff(SamplePath& S)
{
    double Ave=0.0;
    for (int k=0; k<m; k++) Ave=(k/(k+1.0))*Ave+S[k]/(k+1.0);
    if (Ave<K) return 0.0;
    return Ave-K;
}

