int selection()                                 // ���̶� 
{
   double roulette[population+1]={0.00};	// ��¼���̶ĵ�ÿһ���������䣻
   double pro_single[population];			// ��¼ÿ��������ֵĸ��ʣ����������Ӧ�ȳ���������Ӧ��֮�ͣ�
   double totalfitness=0.00;                // ��Ⱥ���и������Ӧ��֮�ͣ�
   int a1[population][workpiecesnumber];	// �洢a�����и����Ⱦɫ�壻

   for(int i=0;i<population;i++)     		// �������и�����Ӧ�ȵ��ܺͣ�
   {
       totalfitness=totalfitness+fits[i];
   }

   for(int i=0;i<population;i++)
   {
       pro_single[i]=fits[i]/totalfitness;   	// ����ÿ��������Ӧ����������Ӧ��֮�ȣ�
       roulette[i+1]=roulette[i]+pro_single[i]; // ��ÿ������ĸ����ۼӣ��������̶ģ�
   }

   for(int i=0;i<population;i++)
   {
       for(int j=0;j<workpiecesnumber;j++)
       {
           a1[i][j]=a[i][j];               //a1��ʱ�洢a��ֵ��
       }
   }

   for(int i=0;i<population;i++)
   {
       int a2;   //��ʶ�����������֮��a2��¼�������ţ�
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
