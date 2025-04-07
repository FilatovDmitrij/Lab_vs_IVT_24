#include <iostream>
using namespace std
int main()
{
 int a[100], b=1, tmp, n, k, max ;
 cin >> n ;
 for (int i = 0; i<=n-1; i++)
    {
     a[i] = b; 
     b++; 
    }
 for (int j = 0; j<=n-1; j++)
    {
     cout << a[j] <<  ' ';
    }
 cout << endl;
 cin >> k;
 tmp = 0;
 while (tmp < n)
	{
     if (k == 0) 
	    {
		 k = n;
	    }
	 cout << a[k-1] << ' ';
	 k--;
	 tmp++;
	}
 b = 0;	
 for (int i = 0; i<=n-2; i++)
    {
     max = a[i];
     if (a[i+1] >max)
        {
         max = a[i+1];
        }    
    }
 for (int i = 0; i<=n-1; i++)
    {
     if (a[i]=max)
        {
         b++;
        }      
    }
 
 for (int i = 0; i<=n-2; i++)
    {
     if (a[i] == max)
        {
         for (int j = i; j<=n-2; j++)
            {
             a[j] = a[j+1];   
            }
        }    
    }
 while (tmp < n-b)
	{
     if (k == 0) 
	    {
		 k = n-b;
	    }
	 cout << a[k-1] << ' ';
	 k--;
	 tmp++;
	}
 while (tmp < n-b)
	{
		if (k == n-b) 
		   {
		    k = 0; 
		   }
		cout << a[k] << ' ';
		k++;
		tmp++;
	}

 return 0;
}