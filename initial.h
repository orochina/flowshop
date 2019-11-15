//先是读取txt文件（main。cpp中），然后进行编码，然后根据编码进行适应度（makespan)计算 
 

int initial()   //初始化种群；
{
    for(int i=0; i<population; i++)     //首先生成一个工件个数的全排列的个体；
        for(int j=0; j<jobNumber; j++)
        {
            a[i][j]=j+1;
        }
        
    for(int i=0; i<population; i++)     //将全排列的个体中随机选取两个基因位交换，重复工件个数次，以形成随机初始种群；
        for(int j=0; j<jobNumber; j++)
        {
            int flg1=rand()%jobNumber;
            int flg2=rand()%jobNumber;            int flg3=a[i][flg1];
            a[i][flg1]=a[i][flg2];
            a[i][flg2]=flg3;
        }
        
    for(int i=0; i<population; i++)
    {
        for(int j=0; j<jobNumber; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
