int selection()                                 // 轮盘赌 
{
   double roulette[population+1]={0.00};	// 记录轮盘赌的每一个概率区间；
   double pro_single[population];			// 记录每个个体出现的概率，即个体的适应度除以总体适应度之和；
   double totalfitness=0.00;                // 种群所有个体的适应度之和；
   int a1[population][workpiecesnumber];	// 存储a中所有个体的染色体；

   for(int i=0;i<population;i++)     		// 计算所有个体适应度的总和；
   {
       totalfitness=totalfitness+fits[i];
   }

   for(int i=0;i<population;i++)
   {
       pro_single[i]=fits[i]/totalfitness;   	// 计算每个个体适应度与总体适应度之比；
       roulette[i+1]=roulette[i]+pro_single[i]; // 将每个个体的概率累加，构造轮盘赌；
   }

   for(int i=0;i<population;i++)
   {
       for(int j=0;j<workpiecesnumber;j++)
       {
           a1[i][j]=a[i][j];               //a1暂时存储a的值；
       }
   }

   for(int i=0;i<population;i++)
   {
       int a2;   //当识别出所属区间之后，a2记录区间的序号；
       double p=rand()%(1000)/(double)(1000);
       for(int j=0;j<population;j++)
       {
           if(p>=roulette[j]&&p<roulette[j+1])
              a2=j;
       }
       for(int m=0;m<workpiecesnumber;m++)
       {
           a[i][m]=a1[a2][m];
       }
   }


}
