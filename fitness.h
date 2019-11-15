int fitness(int c)   //������Ӧ�Ⱥ�����c����ĳ���壻
{
    int totaltime;      //�ܵļӹ�����ʱ�䣨makespan����
    int temp1[workpiecesnumber]= {0};
    int temp2[workpiecesnumber]= {0};
    int temp3[workpiecesnumber]= {0};

    for(int j=0; j<workpiecesnumber; j++)   //temp1��ʱ�洢����c�Ļ������У��Ա���в�ͬ����֮��ļӹ�ʱ��¼�����ӹ��Ⱥ�˳��
    {
        temp1[j]=a[c][j];
    }

    for(int i=0; i<ordernumber; i++)
    {
        for(int j=0; j<workpiecesnumber; j++)  //��ѭ����Ŀ����ͨ���Ƚ����л����ĵ�ǰ����ʱ�䣬�ҳ����ȿ��еĻ����������µĹ���������
        {
            int m=machinetime[i][0];        //�ȼ�¼��i������ĵ�һ̨���л����ĵ�ǰ����ʱ�䣻
            int n=0;
            for (int p=0; p<parallel; p++) //���������л������бȽϣ��ҳ�ʱ����С�Ļ�����
            {
                if (m>machinetime[i][p])
                {
                    m=machinetime[i][p];
                    n=p;
                }
            }
            int q=temp1[j];                 //��˳����ȡtemp1�еĹ����ţ��Թ������мӹ���
            starttime[q-1][i][n]=max(machinetime[i][n],temp3[j]);  //��ʼ�ӹ�ʱ��ȡ�û����ĵ�ǰʱ��͸ù�����һ�������깤ʱ������ֵ��
            machinetime[i][n]=starttime[q-1][i][n]+usetime[q-1][i] ; //�������ۼƼӹ�ʱ����ڻ�����ʼ�ӹ���ʱ�̣����ϸù����ӹ����õ�ʱ�䣻
            finishtime[q-1][i][n]=machinetime[i][n];                 //�������깤ʱ����Ǹû�����ǰ���ۼƼӹ�ʱ�䣻
            temp2[j]=finishtime[q-1][i][n];       //��ÿ���������깤ʱ�丳��temp2�������깤ʱ��Ŀ��������ھ�����һ������Ĺ����ӹ�˳��
        }

        int flg2[workpiecesnumber]= {0};           //������ʱ���飬���ڽ�temp1��temp2�еĹ����������У�
        for(int s=0; s<workpiecesnumber; s++)
        {
            flg2[s]=temp1[s];
        }

        for (int e=0; e<workpiecesnumber-1; e++)
        {
            for(int ee=0; ee<workpiecesnumber-1-e; ee++) // ����temp2�洢������һ��������깤ʱ�䣬�ڽ�����һ����������ʱ���������깤��������
            {                                            //ԭ����ˣ���ѭ����Ŀ�����ڽ�temp2�а��ռӹ�ʱ���С�������У�ͬʱtemp1��Ӧ���б任
                if (temp2[ee]>temp2[ee+1])               //����¼temp2�еĹ����ţ�
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
        for(int e=0; e<workpiecesnumber; e++)    //����temp1��temp2�����ݣ���ʼ��һ������
        {
            temp1[e]=flg2[e];
            temp3[e]=temp2[e];
        }
    }
    totaltime=0;
    for (int i=0; i<parallel; i++) //�Ƚ����һ������������ۼƼӹ�ʱ�䣬���ʱ����Ǹ����̵ļӹ�ʱ�䣻
        if (totaltime<machinetime[ordernumber-1][i])
        {
            totaltime=machinetime[ordernumber-1][i];
        }
    for(int i=0; i<workpiecesnumber; i++)  //��������㣬������һ������ļӹ�ʱ��ͳ�ƣ�
        for(int j=0; j<ordernumber; j++)
            for(int t=0; t<parallel; t++)
            {
                starttime[i][j][t]=0;
                finishtime[i][j][t]=0;
                machinetime[j][t]=0;
            }
    makespan=totaltime;
    fits[c]=1.000/makespan;          //��makespanȡ������Ϊ��Ӧ�Ⱥ�����
}

