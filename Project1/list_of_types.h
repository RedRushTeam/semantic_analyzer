#pragma once
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

using namespace std;

using my_double = double;

#define GAP 3
#define STOP_WORD 0 

my_double divider(int size) {
	int starter = 1;
	int finisher = size;
	auto sum = (starter + finisher) * (finisher - starter + 1) / 2;
	return sum;
}