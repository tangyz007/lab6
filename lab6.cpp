
// Name: Tang Yunzhi
// ID:14255199

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Signal{
private: int length;
		 double maximum_value;
		 double average;
		 double *array;
		 //char name;
		 char filename[30];
		 
public: 
		Signal();// default constructor.
		Signal(int);// parametric constructor 1
		Signal(char); //parametric constructor 2
		~Signal();// destructor
		
};

Signal::~Signal(){
	free(array);
}


Signal::Signal(){

	//ifstream infile;
	//infile.open ("Raw_data_01.txt");
	//if (infile.is_open())
	//{
	//	while (!infile.eof())
	//	{
	//	infile>>length;
	//	infile>>maximum_value;
	
	//cout <<length<<endl;
	//getline(infile,maximum_value);
	//cout <<maximum_value<<endl;
	//infile >> length;
	//infile >> maximum_value;
	//fscanf(fp,"%d",&length);
	//fscanf(fp,"%d",&maximum_value);
	FILE*fp;
	fp= fopen("Raw_data_01.txt","r");
	array=new double[length];
	if(array == NULL)
		cerr << "Error in memory allocation";
	int i=0;
	while(i<length)
	{ 
	//fscanf(fp,"%d",(array+i));
		infile >> array[i];
		
		cout <<array[i];
		i++;
		}
	//fclose(fp);
	
		}
	}
}

Signal::Signal(int a){
	
	//string l;
	//string m;
	ifstream infile;
	infile.open ("Raw_data_01.txt");
	if (infile.is_open())
	{
		while (!infile.eof())
		{
		infile>>length;
		infile>>maximum_value;
	
	//cout <<length<<endl;
	//getline(infile,maximum_value);
	//cout <<maximum_value<<endl;
	//infile >> length;
	//infile >> maximum_value;
	//fscanf(fp,"%d",&length);
	//fscanf(fp,"%d",&maximum_value);
	
	array=new double[length];
	if(array == NULL)
		cerr << "Error in memory allocation";
	int i=0;
	while(i<length)
	{ 
	//fscanf(fp,"%d",(array+i));
		infile >> array[i];
		
		cout <<array[i];
		i++;
		}
		infile.close();
	//fclose(fp);
	
		}
	}
}
//Signal::signal(int)
//{


//}


int main () {
	
  cout<<"please input"<<endl;
  Signal signal;
  return 0;
}