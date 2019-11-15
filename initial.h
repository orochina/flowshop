
int initialization()   //初始化种群；
{
    for(int i=0; i<population; i++)     //首先生成一个工件个数的全排列的个体；
        for(int j=0; j<workpiecesnumber; j++)
        {
            a[i][j]=j+1;
        }
        
    for(int i=0; i<population; i++)     //将全排列的个体中随机选取两个基因位交换，重复工件个数次，以形成随机初始种群；
        for(int j=0; j<workpiecesnumber; j++)
        {
            int flg1=rand()%workpiecesnumber;
            int flg2=rand()%workpiecesnumber;            int flg3=a[i][flg1];
            a[i][flg1]=a[i][flg2];
            a[i][flg2]=flg3;
        }
        
    for(int i=0; i<population; i++)
    {
        for(int j=0; j<workpiecesnumber; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
