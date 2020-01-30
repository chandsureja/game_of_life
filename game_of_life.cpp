#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<ctime>

using namespace std;

int main()
{
    int m,n,choice,sim,num,co = 1;
    do{
            cout<<"welcome to game of life \n";
            cout<<"\n specify the size of the grid you want m and n\n";
            cin>>m>>n;
            int **ptr = (int **)malloc(m* sizeof(int*));
            for(int i=0;i<m;i++)
            {
                ptr[i]=(int *)malloc(n*sizeof(int));
            }
            if(ptr==NULL)
            {
                cout<<"error!!!out of memory\n";
                exit(0);
            }
            srand(time(NULL));
            cout<<"1. random generated cells\n";
            cout<<"2. manually generated cells\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    for(int i=0;i<m;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            ptr[i][j]=rand()%2;
                        }
                    }
                    break;
                }
                case 2:
                {
                    for(int i=0;i<m;i++)
                    {
                        for(int j=0;j<n;j++)

                        {

                            cout<<i<<","<<j<<" ";
                            ptr[i][j]=0;
                        }
                        cout<<"\n";
                    }

                    cout<<"enter amount of cells you want to input\n ";
                    cin>>num;
                    int q,r;
                    for(int i=0;i<num;i++)
                    {
                        cout<<"enter the position of cell in i j\n";
                        cin>>q>>r;
                        ptr[q][r]=1;

                    }


                    break;
                }
                default:
                {
                    cout<<"wrong choice \n";
                    break;
                }
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<ptr[i][j]<<" ";
                }
                cout<<endl;
            }

            int alive;
            int **future=(int **)malloc(m*sizeof(int*));
            for(int i=0;i<m;i++)
            {
                future[i]=(int*)malloc(n*sizeof(int));
            }
        do{
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    alive=0;
                    for(int k=-1;k<=1;k++)
                    {
                        for(int g=-1;g<=1;g++)
                        {
                            if(i+k>=0 && j+g >=0 && i+k <m && j+g < n)
                            {
                                if(ptr[i+k][j+g]==1)
                                {
                                    if(k==0 && g==0)
                                    {
                                        continue;
                                    }
                                    else{
                                            alive=alive+1;
                                    }
                                }
                            }
                            continue;

                        }

                    }
                    cout<<"\t";
                    future[i][j]=alive;


                }
            }

            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(ptr[i][j]==1)
                    {
                        if(future[i][j]==2 || future[i][j]==3)
                        {
                            continue;
                        }
                        else if(future[i][j]>3 || future[i][j]<2)
                        {
                            ptr[i][j]=0;
                        }



                    }
                    else{
                         if(future[i][j]==3)
                         {
                             ptr[i][j]=1;
                         }
                    }
                }
                cout<<endl;
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<ptr[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"press 1 to simulate again \n";
            cin>>sim;
        }while(sim==1);
    cout<<"enter 1 to run the whole game again and press any other key to exit\n";
    cin>>co;
    }while(co==1);
    return 0;
}
