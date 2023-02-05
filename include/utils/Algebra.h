#pragma once
#include<vector>
#include "RankTwoTensor.h"
#include "MooseUtils.h"
#include "libmesh/vector_value.h"

RankTwoTensor Kronecker(const RealVectorValue &n);