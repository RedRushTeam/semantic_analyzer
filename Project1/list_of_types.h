#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <lemmatizator_engine.h>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <list>
#include <map>
#include <math.h>
#include <ctime>
#include <thread>

using namespace std;

using my_double = float;

#define GAP 2
#define STOP_WORD 0 

enum type_of_cont_class{	mat_ozid_, mat_disperse_, mat_otkl_, mat_otkl_fixed_, excess_ratio_, asymmetry_coefficient_, sample_mean_all_	};