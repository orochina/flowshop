int crossover()
/*种群中的个体随机进行两两配对，配对成功的两个个体作为父代1和父代2进行交叉操作。
随机生成两个不同的基因点位，子代1继承父代2基因位之间的基因片段，其余基因按顺序集成父代1中未重复的基因；
子代2继承父代1基因位之间的基因片段，其余基因按顺序集成父代2中未重复的基因。*/
{
    for(int i=0;i<populationnumber/2;i++) //将所有个体平均分成两部分，一部分为交叉的父代1，一部分为进行交叉的父代2；
    {
        int n1=1+rand()%workpiecesnumber/2;    //该方法生成两个不同的基因位；
        int n2=n1+rand()%(workpiecesnumber-n1-1)+1;
        int n3=rand()%10;
        if(n3==2)   //n3=2的概率为0.1；若满足0.1的概率，那么就进行交叉操作；
        {
            int temp1[workpiecesnumber]={0};int temp2[workpiecesnumber]={0};
            for(int j=0;j<workpiecesnumber;j++)
            {
                int flg1=0;int flg2=0;
                for(int p=n1;p<n2;p++)          //将交叉点位之间的基因片段进行交叉，temp1和temp2记录没有发生重复的基因；
                    {if(a[2*i+1][p]==a[2*i][j])
                      flg1=1;
                    }
                    if(flg1==0){temp1[j]=a[2*i][j];}

                for(int p=n1;p<n2;p++)
                    {if(a[2*i][p]==a[2*i+1][j])
                    flg2=1;
                    }
                    if(flg2==0){temp2[j]=a[2*i+1][j];}

            }


            for(int j=n1;j<n2;j++)             //子代1继承父代2交叉点位之间的基因；子代2继承父代1交叉点位之间的基因；
            {
                int n4=0;
                n4=a[2*i][j];
                a[2*i][j]=a[2*i+1][j];
                a[2*i+1][j]=n4;
            }
            for(int p=0;p<n1;p++)               //子代1第一交叉点之前的基因片段，按顺序依次继承父代1中未与子代1重复的基因；
            {
                for( int q=0;q<workpiecesnumber;q++)
                    {if(temp1[q]!=0)
                      {a[2*i][p]=temp1[q];temp1[q]=0;
                       break;}
                    }
            }
            for(int p=0;p<n1;p++)               //子代2第一交叉点之前的基因片段，按顺序依次继承父代2中未与子代2重复的基因；
            {
                for( int m=0;m<workpiecesnumber;m++)
                    {if(temp2[m]!=0)
                     {a[2*i+1][p]=temp2[m];temp2[m]=0;
                      break;}
                    }
            }
            for(int p=n2;p<workpiecesnumber;p++)             //子代1第2交叉点之后的基因片段，按顺序依次继承父代1中未与子代1重复的基因；
            {
                for( int q=0;q<workpiecesnumber;q++)
                    {if(temp1[q]!=0)
                      {a[2*i][p]=temp1[q];temp1[q]=0;
                       break;}

                    }
            }
            for(int p=n2;p<workpiecesnumber;p++)               //子代2第2交叉点之后的基因片段，按顺序依次继承父代2中未与子代2重复的基因；
                {
                    for( int m=0;m<workpiecesnumber;m++)
                    {if(temp2[m]!=0)
                     {a[2*i+1][p]=temp2[m];temp2[m]=0;
                     break;}
                    }
                }

        }
    }


}
