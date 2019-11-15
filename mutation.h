int mutation()  //变异操作为两点变异，随机生成两个基因位，并交换两个基因的位置；
{
    int n3=rand()%20;
        if(n3==2)
        {
           for(int i=0; i<populationnumber; i++)
          {
           int b1=rand()%workpiecesnumber;
           int b2=rand()%workpiecesnumber;
           int b3=a[i][b1];
           a[i][b1]=a[i][b2];
           a[i][b2]=b3;
          }
        }
}
