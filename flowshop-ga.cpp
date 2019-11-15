// 以FT06为例，采用实数编码，随机交叉，两点变异，适应度为完成时间，轮盘赌选择
// FT06问题包括6个机器和6个工件，具体算例如FT06所示 

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


int machineNumber = 6 ;                                 // 机器数目 
int jobNumber = 6 ;                                     // 工件数目 
int process = 6 ;                                 // 工序数目 
int population = 80 ;                             // 种群数目 

double crossoverRate = 0.8 ;                 // 交叉概率 
double mutationRate = 0.05 ;                 // 变异概率 
int N = 200 ;                                // 循环代数

int makespan;                                // 完工时间 
int idleTime;                                // 空闲时间 
int processTime;                             // 加工时间




 
 


