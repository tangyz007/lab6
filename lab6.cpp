
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
		 int *array;
		 double *newarray;
		 //char name;
		 char filename[30];
		 
public: 
		Signal();// default constructor.
		Signal(int a);// parametric constructor 1
		Signal(char* filename); //parametric constructor 2
		~Signal();// destructor
		void Sig_info(int* array);
		double* copyarray(char* filename);
		void do_scale(char* filename,double scale1);
		void do_offset(double offset1);
		int return_length(char* filename);
		
};

Signal::~Signal(){
	free(array);
	free(newarray);
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
	
	FILE*fp;
	fp= fopen("Raw_data_01.txt","r");
	fscanf(fp,"%d",&length);
	fscanf(fp,"%d",&maximum_value);
	array=(int*)malloc(length*sizeof(int));
	newarray=(double*)malloc(length*sizeof(double));
	if(array == NULL)
		cerr << "Error in memory allocation";
	int i=0;
	while(i<length)
	{ 
	    fscanf(fp,"%d",(array+i));
		*(newarray+i)=(double)*(array+i);
		//infile >> array[i];
		
		cout <<newarray[i];
		i++;
		}
	fclose(fp);
	
	
}

Signal::Signal(int a){
	int l;
	FILE*fp;
	sprintf(filename,"Raw_data_%02d.txt",a);
	fp= fopen(filename,"r");
	fscanf(fp,"%d",&length);
	
	fscanf(fp,"%f",&maximum_value);
	//printf("%d \n",maximum_value);
	array=(int*)malloc(length*sizeof(int));
	newarray=(double*)malloc(length*sizeof(double));
	if(array == NULL)
		cerr << "Error in memory allocation";
	int i=0;
	while(i<length)
	{ 
	    fscanf(fp,"%d",(array+i));
		//infile >> array[i];
		//printf("%d",(array+i));
		*(newarray+i)=(double)*(array+i);
		//cout <<newarray[i];
		i++;
		}
	fclose(fp);
	
}
	
Signal::Signal(char* filename){
	int l;
	FILE*fp;
	fp= fopen(filename,"r");
	l=fscanf(fp,"%d",&length);
	
	fscanf(fp,"%d",&maximum_value);
	//printf("%d \n",maximum_value);
	array=(int*)malloc(length*sizeof(int));
	if(array == NULL)
		cerr << "Error in memory allocation";
	int i=0;
	while(i<length)
	{ 
	    fscanf(fp,"%d",(array+i));
		//infile >> array[i];
		//printf("%d",(array+i));
		cout <<array[i];
		i++;
		}
	fclose(fp);
	
}

void Signal::Sig_info(int* array)
{
	int i;
	double max=0,total=0;
	for(i=0;i<length;i++)
	{
		if(*(array+i)>*(array+i+1))
		{
			max=(double)*(array+i);
			
		}
		total=total+*(array+i);
		i++;
	}
	maximum_value=max;
	printf("the maximum is %f",maximum_value);
	average=total/length;
	printf("the average is %f",average);
}

//double* 
void Signal::do_offset(double offset1)
{
	
	double * data_offset= (double*)malloc(length*sizeof(double));
	int i=0;
	while(i<length)
	{ 

		*(data_offset+i)=*(newarray+i)+offset1;
		cout<<data_offset[i]<<endl;
		//printf("\n %.4f",*(data_offset+i));
		//printf("%d",*(newarray+i));
		i++;
	
}
free(data_offset);
//return data_offset;
}


double*copyarray(char* filename)
{
	int l,m;
	 FILE*fp;
	fp= fopen(filename,"r");
	fscanf(fp,"%d",&l);
	fscanf(fp,"%d",&m);
	int * array1= (int*)malloc(l*sizeof(int));
	double * array2 = (double*)malloc(l*sizeof(double));
	int i=0;
	while(i<l)
	{ 
		fscanf(fp,"%d",(array1+i));
		*(array2+i)=*(array1+i);  
		i++;
		
	}

fclose(fp);

	return array2;
}




int return_length(char* filename)
	{
		int l,length;
		FILE*fp;
	
	 
	fp= fopen(filename,"r");
	fscanf(fp,"%d",&l);
	length=l;
	fclose(fp);
	return length;
	}


int main (int argc, char *argv[]) {
	int i = 1,count;
	int value,length;
	float offset, scale;
	int* ayeray;  // array
	double* ayeray2;
	double* ayeray3;
	double mean;
	char myname[100];
	char* filename;

	while(i < argc){
	if((argv[i][0] == '-'))
	goto l1;
	else{
		if(i%2==0)
		{i++;}
	else 
		printf("wrong input");
	}
l1:
	count=argv[i][1];
	switch(count)
	{
case 'n':		
value = atof(argv[i+1]);
if (value<=0||value>12)
			{
            printf("Int value should be 0-11\n");
			}
			else{
				Signal signal1(value);
				//Signal*objPtr=new Signal(value);
				//delete objPtr;
				//signal1(objPtr);
				//sprintf(myname,"Raw_data_%02d.txt",value);
				
			}
			break;
	//case 'a':
	//filename=argv[i+1];
				//Signal signal2(filename);
				//break;
				
	case 'o':
		//Signal*objPtr= new Signal(value);
		//length=return_length(myname);
		//ayeray2=(double*)malloc(sizeof(double)*length);
		//ayeray2=copyarray(myname);
		
		offset = atof(argv[i+1]);//strtod(argv[i+1],NULL);
		
	
		//ayeray3=(double*)malloc(sizeof(double)*length);
		Signal signal2;
		signal2.do_offset(offset);
		break;	
	
	}
	
  //cout<<"please input"<<endl;
  i++;
	}
  
 free(ayeray3);
	free(ayeray2);
	
	
}