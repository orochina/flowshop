int main()
{
    ifstream ifs("FT06.txt");                                           // ��ȡ���� 
    outfile.open("output.txt");                                          // ������ 
    if(!ifs)
    {
        cout<<"���ļ�ʧ�ܣ�"<<endl;
    }
    int l = 0;                                                           //������֪�ļӹ�ʱ�䣻
    while (ifs>>times[l])    
    {
        l++;
    }
    ifs.close();  
    for (int i=0; times[i]!=0; i++)
    {
        cout<<times[i]<<"  ";
    }
    cout<<endl;
    for (int i=0; i<workpiecesnumber; i++)
    {

        for(int j=0; j<ordernumber; j++)
        {
            usetime[i][j]=times[ordernumber*i+j];
            cout<<usetime[i][j]<<"  ";
        }

        cout<<endl;
    }
    cout<<"//////////////////////////////////////////////////"<<endl;;
    srand(time(NULL));                                                  //����ϵͳʱ������һ��������ӣ���֤ÿ������������Ӳ�ͬ 
    initial();                                                          //��ʼ����Ⱥ��
                for(int g=0; g<G; g++)
                {
                    for(int c=0; c<populationnumber; c++)               //����ÿ��������Ӧ�Ȳ�����ttime�У�
                    {
                        fitness(c);
                        ttime[c]=makespan;
                    }
                    selection();                                        //ѡ�������
                    crossover();                                        //���������
                    mutation();                                         //���������
                }

                    int flg8=ttime[0];
                    int flg9=0;
                    for(int c=0; c<populationnumber-1; c++)             //�������һ��ÿ���������Ӧ�ȣ����ҳ����Ÿ��壻
                    {

                        if(ttime[c]<flg8)
                        {
                            flg8=ttime[c];
                            flg9=c;
                        }
                    }
    outfile.close();
    return 0;
}
