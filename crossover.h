int crossover()
/*��Ⱥ�еĸ����������������ԣ���Գɹ�������������Ϊ����1�͸���2���н��������
�������������ͬ�Ļ����λ���Ӵ�1�̳и���2����λ֮��Ļ���Ƭ�Σ��������˳�򼯳ɸ���1��δ�ظ��Ļ���
�Ӵ�2�̳и���1����λ֮��Ļ���Ƭ�Σ��������˳�򼯳ɸ���2��δ�ظ��Ļ���*/
{
    for(int i=0;i<populationnumber/2;i++) //�����и���ƽ���ֳ������֣�һ����Ϊ����ĸ���1��һ����Ϊ���н���ĸ���2��
    {
        int n1=1+rand()%workpiecesnumber/2;    //�÷�������������ͬ�Ļ���λ��
        int n2=n1+rand()%(workpiecesnumber-n1-1)+1;
        int n3=rand()%10;
        if(n3==2)   //n3=2�ĸ���Ϊ0.1��������0.1�ĸ��ʣ���ô�ͽ��н��������
        {
            int temp1[workpiecesnumber]={0};int temp2[workpiecesnumber]={0};
            for(int j=0;j<workpiecesnumber;j++)
            {
                int flg1=0;int flg2=0;
                for(int p=n1;p<n2;p++)          //�������λ֮��Ļ���Ƭ�ν��н��棬temp1��temp2��¼û�з����ظ��Ļ���
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


            for(int j=n1;j<n2;j++)             //�Ӵ�1�̳и���2�����λ֮��Ļ����Ӵ�2�̳и���1�����λ֮��Ļ���
            {
                int n4=0;
                n4=a[2*i][j];
                a[2*i][j]=a[2*i+1][j];
                a[2*i+1][j]=n4;
            }
            for(int p=0;p<n1;p++)               //�Ӵ�1��һ�����֮ǰ�Ļ���Ƭ�Σ���˳�����μ̳и���1��δ���Ӵ�1�ظ��Ļ���
            {
                for( int q=0;q<workpiecesnumber;q++)
                    {if(temp1[q]!=0)
                      {a[2*i][p]=temp1[q];temp1[q]=0;
                       break;}
                    }
            }
            for(int p=0;p<n1;p++)               //�Ӵ�2��һ�����֮ǰ�Ļ���Ƭ�Σ���˳�����μ̳и���2��δ���Ӵ�2�ظ��Ļ���
            {
                for( int m=0;m<workpiecesnumber;m++)
                    {if(temp2[m]!=0)
                     {a[2*i+1][p]=temp2[m];temp2[m]=0;
                      break;}
                    }
            }
            for(int p=n2;p<workpiecesnumber;p++)             //�Ӵ�1��2�����֮��Ļ���Ƭ�Σ���˳�����μ̳и���1��δ���Ӵ�1�ظ��Ļ���
            {
                for( int q=0;q<workpiecesnumber;q++)
                    {if(temp1[q]!=0)
                      {a[2*i][p]=temp1[q];temp1[q]=0;
                       break;}

                    }
            }
            for(int p=n2;p<workpiecesnumber;p++)               //�Ӵ�2��2�����֮��Ļ���Ƭ�Σ���˳�����μ̳и���2��δ���Ӵ�2�ظ��Ļ���
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
