int mutation()  //�������Ϊ������죬���������������λ�����������������λ�ã�
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
