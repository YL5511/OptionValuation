//
//  main.cpp
//  main12
//
//  Created by Julia on 2018/11/6.
//  Copyright © 2018年 Julia. All rights reserved.
//

#include <iostream>
#include"Binmodel02.hpp"
#include "Option08.hpp"
#include<cmath>
#include<vector>
using namespace std;


int main(){
    BinModel Model;
    Model.GetInputData();
    
    Call Opt1;
    Opt1.GetInputData();
    cout<<" European Call Option price: "<< Opt1.PriceByCRR(Model)<<endl;
    cout<<"Ame Call Option Price: "<<Opt1.PriceBySnell(Model)<<endl;

    Put Opt2;
    Opt2.GetInputData();
    cout<<" European Put Option price: "<< Opt2.PriceByCRR(Model)<<endl;
    cout<<"Ame Put Option Price: "<<Opt2.PriceBySnell(Model)<<endl;
}
/*
 Enter S0: 106
 Enter U:  0.14610
 Enter D:  -0.13526
 Enter R:  0.00545
 
 Input data checked
 There is no arbitrage
 
 K: 100
 N: 8
 European Call Option price: 21.3331
 Ame Call Option Price: 21.3331
 
 K: 100
 N: 8
 European Put Option price: 11.0781
 Ame Put Option Price: 11.4424
 Program ended with exit code: 0
 */
