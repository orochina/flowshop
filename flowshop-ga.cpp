// ��FT06Ϊ��������ʵ�����룬������棬������죬��Ӧ��Ϊ���ʱ�䣬���̶�ѡ��
// FT06�������6��������6������������������FT06��ʾ 

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


int machineNumber = 6 ;                                 // ������Ŀ 
int jobNumber = 6 ;                                     // ������Ŀ 
int process = 6 ;                                 // ������Ŀ 
int population = 80 ;                             // ��Ⱥ��Ŀ 

double crossoverRate = 0.8 ;                 // ������� 
double mutationRate = 0.05 ;                 // ������� 
int N = 200 ;                                // ѭ������

int makespan;                                // �깤ʱ�� 
int idleTime;                                // ����ʱ�� 
int processTime;                             // �ӹ�ʱ��




 
 


