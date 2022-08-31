#include<bits/stdc++.h>
using namespace std;

int main()
{
	FILE *fpo = fopen("3letterwords.txt","r");
	FILE *fpo2 = fopen("22letterwords.txt","r");
	FILE *fpw = fopen("2letterwords.txt","w");
	FILE *fpw1 = fopen("1letterwords.txt","w");
	FILE *fpw3 = fopen("33letterwords.txt","w");
	char ch;
	string s;
	map<string,int>m;
	map<string,int>mone;
	while((ch = fgetc(fpo))!=EOF)
	{
		
		if(ch==' ')
		{
			string d ;
			d=d+s[0];
			d=d+s[1];
			fprintf(fpw3,"%c",s[0]);
			fprintf(fpw3,"%c",s[1]);
			fprintf(fpw3,"%c\n",s[2]);
			//cout<<d<<" ";
			string e;
			e=e+d[0];
			m[d]++;
			mone[e]++;
			s = "";			
		}
		else
		{
			s=s+ch;
		}
	}
	map<string,int>::iterator it;
	
	for(it=mone.begin();it!=mone.end();it++)
	{
		s = it->first;
		cout<<s<<" ";
		fprintf(fpw1,"%c\n",s[0]);
	}
	while((ch = fgetc(fpo2))!=EOF)
	{
		
		if(ch=='\n')
		{
			string d ;
			d=d+s[0];
			d=d+s[1];
			m[d]++;
			s = "";			
		}
		else
		{
			s=s+ch;
		}
	}
	for(it=m.begin();it!=m.end();it++)
	{
		s = it->first;
		cout<<s<<" ";
		fprintf(fpw,"%c",s[0]);
		fprintf(fpw,"%c\n",s[1]);
	}
	fclose(fpo);
	fclose(fpw);
	fclose(fpw1);
	fclose(fpo2);
}