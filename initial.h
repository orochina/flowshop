//���Ƕ�ȡtxt�ļ���main��cpp�У���Ȼ����б��룬Ȼ����ݱ��������Ӧ�ȣ�makespan)���� 
 

int initial()   //��ʼ����Ⱥ��
{
    for(int i=0; i<population; i++)     //��������һ������������ȫ���еĸ��壻
        for(int j=0; j<jobNumber; j++)
        {
            a[i][j]=j+1;
        }
        
    for(int i=0; i<population; i++)     //��ȫ���еĸ��������ѡȡ��������λ�������ظ����������Σ����γ������ʼ��Ⱥ��
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
