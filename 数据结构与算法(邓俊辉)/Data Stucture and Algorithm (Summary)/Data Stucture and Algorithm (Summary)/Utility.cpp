//
//  Utility.cpp
//  Data Stucture and Algorithm (Summary)
//
//  Created by Vic Wan on 2017/11/22.
//  Copyright © 2017年 Vic Wan. All rights reserved.
//

#include <stdio.h>

// 函数对象

template <typename T>
struct Increase {
    virtual void operator ()( T & e )
    {
        return e++;
    }
};

template <typename T>
struct Visit {
    virtual void operator ()( T & e )
    {
        return e;
    }
};


