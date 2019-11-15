int main()
{
    ifstream ifs("FT06.txt");                                           // 读取数据 
    outfile.open("output.txt");                                          // 输出结果 
    if(!ifs)
    {
        cout<<"打开文件失败！"<<endl;
    }
    int l = 0;                                                           //读入已知的加工时间；
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
    srand(time(NULL));                                                  //根据系统时间设置一个随机种子，保证每次运行随机种子不同 
    initial();                                                          //初始化种群；
                for(int g=0; g<G; g++)
                {
                    for(int c=0; c<populationnumber; c++)               //计算每个个体适应度并存在ttime中；
                    {
                        fitness(c);
                        ttime[c]=makespan;
                    }
                    selection();                                        //选择操作；
                    crossover();                                        //交叉操作；
                    mutation();                                         //变异操作；
                }

                    int flg8=ttime[0];
                    int flg9=0;
                    for(int c=0; c<populationnumber-1; c++)             //计算最后一代每个个体的适应度，并找出最优个体；
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
