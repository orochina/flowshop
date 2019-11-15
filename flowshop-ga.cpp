#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
using namespace std;
ofstream outfile;

#include <initial.h>
#include <crossover.h>
#include <mutation.h>
#include <selection.h>


int machine;                                 // 机器数目 
int job;                                     // 工件数目 
int process;                                 // 工序数目 
int population;                              // 种群数目 

double crossoverRate = 0.8 ;                 // 交叉概率 
double mutationRate = 0.05 ;                 // 变异概率 
int N = 200 ;                                // 循环代数

int makespan;                                // 完工时间 
int idleTime;                                // 空闲时间 
int processTime;                             // 加工时间



 
 


