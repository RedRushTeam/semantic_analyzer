#pragma once
#define H5_BUILT_AS_DYNAMIC_LIB
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <lemmatizator_engine.h>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
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
#include <regex>
//#include <boost/numeric/ublas/matrix_sparse.hpp>
//#include <boost/numeric/ublas/io.hpp>
/*
#include "H5Cpp.h"
using namespace H5;*/

namespace fs = std::filesystem;
using namespace std;

using my_double = float;

#define GAP 2
#define STOP_WORD 0 

#define TRASH_DELETE_OPTION 0 //0 - base  1 - extended
#define LEMADR "C:\\RGD\\RussianGrammaticalDictionary\\bin-windows64\\lemmatizer.db"
//#define TEXTS_PATH "E:\\Новая папка (2)"
//#define TEXTS_PATH "A:\\rasp_puhl"
#define TEXTS_PATH "C:\\Users\\fortunati\\Desktop\\Новая папка (3)"


enum type_of_purpose_of_cont_class {	mat_ozid_, mat_disperse_, mat_otkl_, mat_otkl_fixed_, excess_ratio_, asymmetry_coefficient_, sample_mean_all_	};
enum type_of_cont_class {	hard_container_class_, sql_container_class_};