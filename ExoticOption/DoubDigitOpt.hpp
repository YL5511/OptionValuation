//
//  DoubDigitOpt.hpp
//  digitoptin
//
//  Created by Julia on 2018/10/14.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef DoubDigitOpt_hpp
#define DoubDigitOpt_hpp

#include <stdio.h>
#include "Options06.hpp"
class DoubDigitOpt: public EurOption
{
private:
    double K1; //parameter 1
    double K2; //parameter 2
public:
    int GetInputData();
    double Payoff(double z);
};


#endif /* DoubDigitOpt_hpp */
