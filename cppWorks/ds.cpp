//
//  ds.cpp
//  cppWorks
//
//  Created by 徐普 on 14/12/6.
//  Copyright (c) 2014年 xp. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int i, n, t;
    cin>>n;
    int max = 0, sum = 0, flg = 1, fst = 0, lst = 0, fst_t = 0;
    int fst_1 = 0, lst_1 = 0;
    for (i = 0; i < n; ++i) {
        cin>>t;
        if (i == 0) {
            fst_1 = t;
        } else if (i == n-1) {
            lst_1 = t;
        }
        
        sum += t;
        if (flg == 1) {
            flg = 0;
            fst_t = t;
        }
        if (sum > max) {
            max = sum;
            fst = fst_t;
            lst = t;
        } else if (sum <= 0) {
            flg = 1;
            sum = 0;
        }
    }
    
    if (max == 0) {
        fst = fst_1;
        lst = lst_1;
    }
    
    cout<<max<<" "<<fst<<" "<<lst;
    return 0;
}