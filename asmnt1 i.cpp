#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> grades;
	int* arr=new int[99];
	int c=0,tmp=0,n=1,i,j;
	
	cout << "please enter the grades :\n";
	
	while( true )
	{
		cin >> tmp;
		if( tmp < -1 )
		{
			cout << "wrong entry,try again.\n";
			cout << tmp;
			continue;
		}
		if( tmp == -1 ) break;
		grades.push_back(tmp);
		c++;
	}
	c--;
	
	partial_sort(grades.begin(),grades.begin()+c,grades.end());
	
	arr[0]=grades[0];
	for( i=1,j=1 ;  ; i++ )
	{
		if( grades[i]==grades[i-1] )
		{
			n++;
			continue;
		}
		arr[j++]=n;
		n=1;
		arr[j++]=grades[i];
		if ( i==c )
		{
			arr[j]=n;
			break;
		}
	}
	
	for( i=0 ; i<j; i+=2 )
	{
		cout << "Number of " << arr[i] << "\'s = " << arr[i+1] << endl;
	}
	
	
	delete[] arr;
}
		
