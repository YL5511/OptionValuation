//
//  Solver03.h
//  solver
//
//  Created by Julia on 2018/10/31.
//  Copyright © 2018年 Julia. All rights reserved.
//

#ifndef Solver03_h
#define Solver03_h



template <typename Function>
double SolveByBisect( Function* Fct,
                     double Tgt, double LEnd,double REnd, double Acc){
    double left=LEnd;
    double right=REnd;
    double mid=(left+right)/2;
    double y_left=Fct->Value(left)-Tgt, y_mid=Fct->Value(mid)-Tgt;
    while(mid-left>Acc){
        if((y_left>0&&y_mid>0)||(y_left<0&&y_mid<0)){
            left=mid;
            y_left=y_mid;
        }
        else right=mid;
        mid=(left+right)/2;
        y_mid=Fct->Value(mid)-Tgt;
    }
    return mid;
}



#endif /* Solver03_h */
