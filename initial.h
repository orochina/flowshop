
int initialization()   //��ʼ����Ⱥ��
{
    for(int i=0; i<population; i++)     //��������һ������������ȫ���еĸ��壻
        for(int j=0; j<workpiecesnumber; j++)
        {
            a[i][j]=j+1;
        }
        
    for(int i=0; i<population; i++)     //��ȫ���еĸ��������ѡȡ��������λ�������ظ����������Σ����γ������ʼ��Ⱥ��
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
