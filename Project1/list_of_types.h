#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <math.h>
#include <ctime>
#include <thread>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

using my_double = float;

#define GAP 2
#define STOP_WORD 0 


enum type_of_purpose_of_cont_class {	mat_ozid_, mat_disperse_, mat_otkl_, mat_otkl_fixed_, excess_ratio_, asymmetry_coefficient_, sample_mean_all_	};
enum type_of_cont_class {	hard_container_class_, sql_container_class_};