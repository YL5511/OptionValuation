//
//  BSModel01.hpp
//  MonteCarloSimulation
//
//  Created by Julia on 2018/11/10.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef BSModel01_hpp
#define BSModel01_hpp

#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef  vector<double> SamplePath;
class BSModel
{
public:
    double S0, r, sigma;
    BSModel(double S0_, double r_, double sigma_)
    {            S0 = S0_; r = r_; sigma = sigma_;
        srand(1);                }
    void GenerateSamplePath(double T, int m, SamplePath& S);
};

#endif /* BSModel01_hpp */
