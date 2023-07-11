#include<iostream>
using namespace std;

int main()
{
    string names[5]={"Ali","Hiba","Asma","Zain","Faisal"};
    int Size[5];
    float **array=new float*[3];
    for(int i=0;i<5;i++)
    {
        cout<<"Enter the number of subjects of "<<names[i]<<" .\n";
        cin>>Size[i];
        array[i]=new float [Size[i]];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < Size[i]; j++)
        {
            cout<<"Enter the GPA of subject number "<<j+1<<" of "<<names[i]<<endl;
            cin>>*(*(array+i)+j);
        }
        
    }

    for (int i = 0; i < 5; i++)
    {   float sum=0;
        for (int j = 0; j < Size[i]; j++)
        {
            sum+=*(*(array+i)+j);
        }
        cout<<"GPA of "<<names[i]<<" is "<<sum/Size[i]<<endl;
        
    }
    
    
   
   
}