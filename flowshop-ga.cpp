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


int machine;                                 // ������Ŀ 
int job;                                     // ������Ŀ 
int process;                                 // ������Ŀ 
int population;                              // ��Ⱥ��Ŀ 

double crossoverRate = 0.8 ;                 // ������� 
double mutationRate = 0.05 ;                 // ������� 
int N = 200 ;                                // ѭ������

int makespan;                                // �깤ʱ�� 
int idleTime;                                // ����ʱ�� 
int processTime;                             // �ӹ�ʱ��



 
 


