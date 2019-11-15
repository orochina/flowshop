int fitness(int c)   //计算适应度函数，c代表某个体；
{
    int totaltime;      //总的加工流程时间（makespan）；
    int temp1[workpiecesnumber]= {0};
    int temp2[workpiecesnumber]= {0};
    int temp3[workpiecesnumber]= {0};

    for(int j=0; j<workpiecesnumber; j++)   //temp1暂时存储个体c的基因序列，以便进行不同流程之间的加工时记录工件加工先后顺序；
    {
        temp1[j]=a[c][j];
    }

    for(int i=0; i<ordernumber; i++)
    {
        for(int j=0; j<workpiecesnumber; j++)  //该循环的目的是通过比较所有机器的当前工作时间，找出最先空闲的机器，便于新的工件生产；
        {
            int m=machinetime[i][0];        //先记录第i道工序的第一台并行机器的当前工作时间；
            int n=0;
            for (int p=0; p<parallel; p++) //与其他并行机器进行比较，找出时间最小的机器；
            {
                if (m>machinetime[i][p])
                {
                    m=machinetime[i][p];
                    n=p;
                }
            }
            int q=temp1[j];                 //按顺序提取temp1中的工件号，对工件进行加工；
            starttime[q-1][i][n]=max(machinetime[i][n],temp3[j]);  //开始加工时间取该机器的当前时间和该工件上一道工序完工时间的最大值；
            machinetime[i][n]=starttime[q-1][i][n]+usetime[q-1][i] ; //机器的累计加工时间等于机器开始加工的时刻，加上该工件加工所用的时间；
            finishtime[q-1][i][n]=machinetime[i][n];                 //工件的完工时间就是该机器当前的累计加工时间；
            temp2[j]=finishtime[q-1][i][n];       //将每个工件的完工时间赋予temp2，根据完工时间的快慢，便于决定下一道工序的工件加工顺序；
        }

        int flg2[workpiecesnumber]= {0};           //生成暂时数组，便于将temp1和temp2中的工件重新排列；
        for(int s=0; s<workpiecesnumber; s++)
        {
            flg2[s]=temp1[s];
        }

        for (int e=0; e<workpiecesnumber-1; e++)
        {
            for(int ee=0; ee<workpiecesnumber-1-e; ee++) // 由于temp2存储工件上一道工序的完工时间，在进行下一道工序生产时，按照先完工先生产的
            {                                            //原则，因此，该循环的目的在于将temp2中按照加工时间从小到大排列，同时temp1相应进行变换
                if (temp2[ee]>temp2[ee+1])               //来记录temp2中的工件号；
                {
                    int flg5=temp2[ee];
                    int flg6=flg2[ee];
                    temp2[ee]=temp2[ee+1];
                    flg2[ee]=flg2[ee+1];
                    temp2[ee+1]=flg5;
                    flg2[ee+1]=flg6;
                }
            }
        }
        for(int e=0; e<workpiecesnumber; e++)    //更新temp1，temp2的数据，开始下一道工序；
        {
            temp1[e]=flg2[e];
            temp3[e]=temp2[e];
        }
    }
    totaltime=0;
    for (int i=0; i<parallel; i++) //比较最后一道工序机器的累计加工时间，最大时间就是该流程的加工时间；
        if (totaltime<machinetime[ordernumber-1][i])
        {
            totaltime=machinetime[ordernumber-1][i];
        }
    for(int i=0; i<workpiecesnumber; i++)  //将数组归零，便于下一个个体的加工时间统计；
        for(int j=0; j<ordernumber; j++)
            for(int t=0; t<parallel; t++)
            {
                starttime[i][j][t]=0;
                finishtime[i][j][t]=0;
                machinetime[j][t]=0;
            }
    makespan=totaltime;
    fits[c]=1.000/makespan;          //将makespan取倒数作为适应度函数；
}

