#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <random>
#include <limits>
#include <chrono>
#include <algorithm>
using namespace std;
vector <long long> v;
vector <long long> t;

//Mergesort
void interclasare(vector <long long> &t,long long int stanga,long long int mij,long long int dreapta)
{
    long long int i,j,n;
    n=1;
    i=stanga;
    j=mij+1;

     while(i<=mij && j<=dreapta)
     {
         if(t[i]<=t[j])
         {
             v[n]=t[i];
             n++;
             i++;
         }
         else
            {
                v[n]=t[j];
                n++;
                j++;
            }
     }
     while(i<=mij)
     {
         v[n]=t[i];
         i++;
         n++;
     }

     while(j<=dreapta)
     {
         v[n]=t[j];
         j++;
         n++;
     }

}
void mergesort(vector <long long> &t,long long int stanga, long long int dreapta)
{
    long long int mij,i;
    if(stanga<dreapta)
    {
        mij=(stanga+dreapta)/2;
        mergesort(t,stanga,mij);
        mergesort(t,mij+1,dreapta);
        interclasare(t,stanga,mij,dreapta);
        for(i=stanga;i<=dreapta;i++)
            t[i]=v[i-stanga+1];

    }

}


int test_sort_1(vector <long long> &t, long long int n)
{   long long int i;
    for(i=1;i<n;i++)
    {
        if(t[i]>t[i+1])
            return 0;
    }
    return 1;
}

//Radixsort

void Counting_1(vector <long long> &v,long long int n,long long int putere)
{
    long long int i,x;
    t=vector <long long>(n);
    long long int frecventa[10]={0};

    for(i=0;i<n;i++)
        {
            x=(v[i]/putere)%10;
            frecventa[x]++;

        }

    for(i=1;i<10;i++)
        frecventa[i]+=frecventa[i-1];

    i=n-1;
    while(i>=0)
        {
        x=frecventa[(v[i]/putere)%10];
        t[x-1]=v[i];
        frecventa[(v[i]/putere)%10]--;
        i--;
        }

    for(i=0;i<n;i++)
        v[i]=t[i];
}

void radixsort_1(vector <long long> &v,long long int n)
{
    long long int i,putere,nr_max;
    nr_max=-1;
    for(i=1;i<n;i++)
        if(v[i]>nr_max)
            nr_max=v[i];

    putere=1;
    while(nr_max/putere>0)
    {
         Counting_1(v,n,putere);
         putere=putere*10;
    }

}

void Counting_2(vector <long long> &v,long long int n,long long int putere)
{
    long long int i,x;
    t=vector <long long>(n);
    long long int frecventa[65536]={0};

    for(i=0;i<n;i++)
        {
            x=(v[i]/putere)%65536;
            frecventa[x]++;

        }

    for(i=1;i<65536;i++)
        frecventa[i]+=frecventa[i-1];

    for(i=n-1;i>=0;i--)
        {
        x=frecventa[(v[i]/putere)%65536];
        t[x-1]=v[i];
        frecventa[(v[i]/putere)%65536]--;
        }

    for(i=0;i<n;i++)
        v[i]=t[i];
}

void radixsort_2(vector <long long> &v,long long int n)
{
    long long int i,putere,nr_max;
    nr_max=-1;
    for(i=1;i<n;i++)
        if(v[i]>nr_max)
            nr_max=v[i];

    putere=1;
    while(nr_max/putere>0)
    {
         Counting_2(v,n,putere);
         putere=putere*65536;
    }

}
//Shellsort
int shell_sort_1(vector <long long> &v,long long int n)
{   long long int i,j,x,k;
    for(k=n/2;k>0;k=k/2)
    {
        for(i=k;i<n;i++)
        {
            j=i-k;
            while(j>=0)
            {
                if(v[j]>v[j+k])
                {
                    x=v[j];
                    v[j]=v[j+k];
                    v[j+k]=x;
                    j=j-k;
                }
                else
                    break;
            }
        }
    }
    return 0;
}
void shell_sort_2(vector<long long> &v, long long int n)
{
    long long int i,j,m=0;
    for(i=1;i<n;i++)
        {
            i=3*i+1;
            m=i;
        }
	while(m>0)
	{
		for(i=m;i<n;i++)
		{
			j=i;
			while(j>=m && v[j-m]>v[i])
				{
				    v[j]=v[j-m];
				    j=j-m;
				}

            v[j]=v[i];
		}
		m=(m-1)/3;
	}
}
//Quicksort
long long int Pivot_2(vector <long long> &v,long long int stanga,long long int dreapta)
{
    long long int i,j;
    i=stanga-1;
    for(j=stanga;j<dreapta;j++)
    {
        if(v[j]<=v[dreapta])
        {
            i++;
            swap(v[i],v[j]);

        }
    }
    swap(v[i+1],v[dreapta]);
    return (i+1);
}

long long int mediana_2(vector <long long> &v,long long int stanga,long long int dreapta)
{
    long long int med_3=0,pivot_1,pivot_2,pivot_3,x;
    pivot_1=stanga+rand()%(dreapta-stanga+1);
    pivot_2=stanga+rand()%(dreapta-stanga+1);
    pivot_3=stanga+rand()%(dreapta-stanga+1);

    if((v[pivot_1]<=v[pivot_2] && v[pivot_2]<=v[pivot_3])||(v[pivot_3]<=v[pivot_2] && v[pivot_2]<=v[pivot_1]))
        med_3=pivot_2;
    if((v[pivot_2]<=v[pivot_1] && v[pivot_1]<=v[pivot_3])||(v[pivot_3]<=v[pivot_1] && v[pivot_1]<=v[pivot_2]))
        med_3=pivot_1;
    else
        med_3=pivot_3;

    swap(v[dreapta],v[med_3]);

    x=Pivot_2(v,stanga,dreapta);
    return x;
}

  void quick_sort_2(vector <long long> &v,long long int stanga,long long int dreapta)
{
    long long int pivot;
    if(stanga<dreapta)
    {
        pivot=mediana_2(v,stanga,dreapta);
        quick_sort_2(v,stanga,pivot-1);
        quick_sort_2(v,pivot+1,dreapta);
    }
}


int segmentare_1(vector <long long> &v,long long int stanga,long long int dreapta)
{
    long long int pivot,i,j;
    pivot=v[dreapta];
    i=stanga-1;

    for(j=stanga;j<dreapta;j++)
    {
        if (v[j]<=pivot)
            {

            i++;
            swap(v[i],v[j]);

            }
    }
    swap(v[i+1],v[dreapta]);
    i++;
    return i;
}


int segmentare_2(vector <long long> &v,long long int stanga,long long int dreapta)
{
    long long int nr_random,m;
    m=dreapta-stanga;
    nr_random=stanga+rand()%(m);
    swap(v[nr_random],v[dreapta]);


    return segmentare_1(v,stanga,dreapta);
}



void quick_sort(vector <long long> &v,long long int stanga,long long int dreapta)
{   long long int var;
    if (stanga<dreapta)
        {

        var=segmentare_2(v,stanga,dreapta);
        quick_sort(v,stanga,var-1);
        quick_sort(v,var+1,dreapta);

        }
}
//Heapsort
void heap(vector <long long> &v,long long int n, long long int varf)
{
   long long int stanga, dreapta,i;

    i=varf;
    stanga=2*varf+1;
    dreapta=2*varf+2;


    if(stanga<n&&v[i]<v[stanga])
        i=stanga;

    if(dreapta<n&&v[i]<v[dreapta])
        i=dreapta;

    if (i!=varf)
        {
            swap(v[varf],v[i]);
            heap(v,n,i);
        }
}

void heap_sort(vector <long long> &v, long long int n)
{   long long int i,x=0;
    i=n/2-1;
    while(i>=0)
    {
        heap(v,n,i);
        i--;
    }
    i=n-1;
    while(i>0)
    {
        x=v[0];
        swap(v[0],v[i]);
        heap(v,i,0);
        i--;
    }
}
int test_sort(vector <long long>, long long int n)
{   long long int i;
    for(i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
            return 0;
    }
    return 1;
}


int main()
{  long long int opt, n,i, nr_maxim, nr_test,j, baza,optiune;
    do
    {     cout<<"Alegeti metoda de sortare pe care doriti sa o utilizati: "<<"\n";
          cout<<"1.Mergesort"<<"\n";
          cout<<"2.Radixsort"<<"\n";
          cout<<"3.Shellsort"<<"\n";
          cout<<"4.Quicksort"<<"\n";
          cout<<"5.Heapsort"<<"\n";
          cout<<"6.Algoritm de sortare nativ"<<"\n";
          cin>>opt;
          if(opt==1)
    {
    cout<<"Dati o valoare pentru numarul de teste pe care doriti sa le testati:" <<endl;
    cin>>nr_test;
    for(j=1;j<=nr_test;j++)
    {
    cout<<"Dati o valoare pentru numarul elementelor pe care doriti sa le generati:"<<endl;
    cin>>n;
    cout<<"Dati o valoare pentru valoarea maxima pe care o pot avea elementele ce se doresc a fi generate:"<<endl;
    cin>>nr_maxim;
    t=vector <long long>(n+1);
    v=vector <long long>(n+1);

    chrono::time_point<std::chrono::system_clock> start,stop;

    if(n>100000001)
    {
        cout<<"Algoritmul nu poate sorta."<<endl;

    }
else
    {
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<long long> random(0,nr_maxim);
    for(auto i = t.begin(); i!=t.end(); i++)
        {
        *i = random(gen);
        }
    start = chrono::system_clock::now();
    mergesort(t,1,n);

    stop=chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds4=stop-start;
    cout<<"Sortare Mergesort"<<"\n";

    if(test_sort_1(t,n)==1)
        {
            cout<<"Numerele au fost sortate corect."<<"\n";
            cout<<"Timp de executie:"<<elapsed_seconds4.count()<<"s"<<"\n";
        }
        else
           {
            cout<<"Sortarea este nereusita."<<"\n";
            for(i=1;i<=n;i++)
                cout<<t[i]<<" ";
            cout<<"\n";
           }

     }

    }
    }
    else
        if(opt==2)
        {
    cout<<"Dati o valoare pentru numarul de teste pe care doriti sa le testati:" <<"\n";
    cin>>nr_test;
    for(j=1;j<=nr_test;j++)
    {
    cout<<"Selectati baza in care doriti sa sortati."<<"\n";
    cout<<"1. Baza 10"<<"\n";
    cout<<"2. Baza 2^16"<<"\n";
    cin>>baza;
    cout<<"Dati o valoare pentru numarul elementelor pe care doriti sa le generati:"<<"\n";
    cin>>n;
    cout<<"Dati o valoare pentru valoarea maxima pe care o pot avea elementele ce se doresc a fi generate:"<<"\n";
    cin>>nr_maxim;

    v=vector <long long>(n);
    chrono::time_point<std::chrono::system_clock> start,stop;

    if(n>100000001)
    {
        cout<<"Algoritmul nu poate sorta."<<"\n";

    }
else
    {
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<long long> random(0,nr_maxim);
    for(auto i = v.begin(); i!=v.end(); i++)
        {
        *i = random(gen);
        }
    start = chrono::system_clock::now();
    if(baza==1)
    radixsort_1(v,n);
    else
        if(baza==2)
        radixsort_2(v,n);
    else
        break;

    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds4=stop-start;
    cout<<"Sortare Radix_sort"<<"\n";

    if(test_sort(v,n)==1)
        {
            cout<<"Numerele au fost sortate corect."<<"\n";
            cout<<"Timp de executie:"<<elapsed_seconds4.count()<<"s"<<"\n";
        }
        else
            cout<<"Sortarea este nereusita."<<"\n";

     }

    }
        }
    else
        if(opt==3)
    {
    cout<<"Dati o valoare pentru numarul de teste pe care doriti sa le generati:" <<"\n";
    cin>>nr_test;
    for(j=1;j<=nr_test;j++)
    {
    cout<<"Alegeti tipul de sortare Shellsort pe care doriti sa il utilizati:"<<"\n";
    cout<<"1.Shellsort_1"<<"\n";
    cout<<"2.Shellsort_2"<<"\n";
    cin>>optiune;
    cout<<"Dati o valoare pentru numarul elementelor pe care doriti sa le generati:"<<"\n";
    cin>>n;
    cout<<"Dati o valoare pentru valoarea maxima pe care o pot avea elementele ce se doresc a fi generate:"<<"\n";
    cin>>nr_maxim;
    v=vector <long long>(n);
    chrono::time_point<std::chrono::system_clock> start,stop;

    if(n>100000001)
    {
        cout<<"Algoritmul nu poate sorta."<<endl;

    }
else
    {
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<long long> random(0,nr_maxim);
    for(auto i = v.begin(); i!=v.end(); i++)
        {
        *i = random(gen);
        }
    start = chrono::system_clock::now();
    if(optiune==1)
        shell_sort_1(v,n);
    else
        if(optiune==2)
        shell_sort_2(v,n);
    else
        break;

    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds4=stop-start;
    cout<<"Sortare Shellsort"<<"\n";

    if(test_sort(v,n)==1)
        {
            cout<<"Numerele au fost sortate corect."<<"\n";
            cout<<"Timp de executie:"<<elapsed_seconds4.count()<<"s"<<"\n";

        }
        else
            cout<<"Sortarea este nereusita."<<"\n";

     }

    }
    }
    else
        if(opt==4)
    {
    cout<<"Dati o valoare pentru numarul de teste pe care doriti sa le faceti:"<<"\n";
    cin>>nr_test;
    for(j=1;j<=nr_test;j++)
    {
    cout<<"Dati o valoare pentru numarul elementelor pe care doriti sa le generati:"<<"\n";
    cin>>n;
    cout<<"Dati o valoare pentru valoarea maxima pe care o pot avea elementele ce se doresc a fi generate:"<<"\n";
    cin>>nr_maxim;
    v=vector <long long>(n);
    chrono::time_point<std::chrono::system_clock> start,stop;

    if(n>100000001)
    {
        cout<<"Algoritmul nu poate sorta."<<"\n";

    }
else
    {
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<long long> random(0,nr_maxim);
    for(auto i = v.begin(); i!=v.end(); i++)
        {
        *i = random(gen);

        }
    start = chrono::system_clock::now();
    cout<<"Ce quicksort doriti sa utilizati?"<<"\n";
    cout<<"1.Quicksort cu pivot random"<<"\n";
    cout<<"2.Quicksort cu pivot mediana din 3"<<"\n";
    cin>>optiune;
    if(optiune==1)
        quick_sort(v,0,n-1);
    else
        if(optiune==2)
        quick_sort_2(v,0,n-1);
    else
        break;

    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds4=stop-start;
    cout<<"Sortare Quick_sort"<<"\n";



    if(test_sort(v,n)==1)
        {
            cout<<"Numerele au fost sortate corect."<<"\n";
            cout<<"Timp de executie:"<<elapsed_seconds4.count()<<"s"<<"\n";
        }
        else
            cout<<"Numerele nu au fost sortate corect."<<"\n";

     }
    }
    }
    else
        if(opt==5)
    {
    cout<<"Dati o valoare pentru numarul de teste pe care doriti sa le generati:" <<endl;
    cin>>nr_test;
    for(j=1;j<=nr_test;j++)
    {

    cout<<"Dati o valoare pentru numarul elementelor pe care doriti sa le generati:"<<endl;
    cin>>n;
    cout<<"Dati o valoare pentru valoarea maxima pe care o pot avea elementele ce se doresc a fi generate:"<<endl;
    cin>>nr_maxim;

    v=vector <long long>(n);
    chrono::time_point<std::chrono::system_clock> start,stop;

    if(n>100000001)
    {
        cout<<"Algoritmul nu poate sorta."<<endl;

    }
else
    {
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<long long> random(0,nr_maxim);
    for(auto i = v.begin(); i!=v.end(); i++)
        {
        *i = random(gen);
        }
    start = chrono::system_clock::now();
    heap_sort(v,n);

    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds4=stop-start;
    cout<<"Sortare Heap_sort"<<"\n";

    if(test_sort(v,n)==1)
        {
            cout<<"Numerele au fost sortate corect."<<"\n";
            cout<<"\n";
            cout<<"Timp de executie:"<<elapsed_seconds4.count()<<"s"<<"\n";
        }
        else
            cout<<"Sortarea este nereusita."<<"\n";

     }

    }
    }
    else
        if(opt==6)
    {
    cout<<"Dati o valoare pentru numarul de teste pe care doriti sa le generati:" <<endl;
    cin>>nr_test;
    for(j=1;j<=nr_test;j++)
    {

    cout<<"Dati o valoare pentru numarul elementelor pe care doriti sa le generati:"<<endl;
    cin>>n;
    cout<<"Dati o valoare pentru valoarea maxima pe care o pot avea elementele ce se doresc a fi generate:"<<endl;
    cin>>nr_maxim;

    v=vector <long long>(n);
    chrono::time_point<std::chrono::system_clock> start,stop;

    if(n>100000001)
    {
        cout<<"Algoritmul nu poate sorta."<<endl;

    }
else
    {
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<long long> random(0,nr_maxim);
    for(auto i = v.begin(); i!=v.end(); i++)
        {
        *i = random(gen);
        }
    start = chrono::system_clock::now();
    sort(v.begin(),v.end());

    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds4=stop-start;
    cout<<"STL Sort"<<"\n";
    cout<<"Timp de executie:"<<elapsed_seconds4.count()<<"s"<<"\n";

     }

    }
    }


    }while(opt>=1&&opt<=6);


    return 0;
}
