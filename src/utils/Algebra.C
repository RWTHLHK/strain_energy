#include "Algebra.h"
RankTwoTensor
Kronecker(const RealVectorValue &n){
    RankTwoTensor result;
    for(auto i:make_range(3)){
        result.fillRow(i, n(i)*n);
    }
    return result;
}