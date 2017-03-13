
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
		 int maximum_value;
		 double max;
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
		void Sig_info(void);
		double* copyarray(char* filename);
		void do_scale(double scale1);
		void do_offset(double offset1);
		int return_length(char* filename);
		double do_average(void);
		void center(double mean1);
		void normalize(void);
		void save_file(char name[]);
		
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
	//cout<<maximum_value<<endl;
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
	FILE*fp;
	sprintf(filename,"Raw_data_%02d.txt",a);
	fp= fopen(filename,"r");
	fscanf(fp,"%d",&length);
	//cout<<length<<endl;
	fscanf(fp,"%d",&maximum_value);
	max=(double)maximum_value;
	cout<<max<<endl;
	//cout<<maximum_value<<endl;
	//printf("%d \n",maximum_value);
	array=(int*)malloc(length*sizeof(int));
	newarray=(double*)malloc(length*sizeof(double));
	if(array == NULL)
		cerr << "Error in memory allocation";
	int i=0;
	cout<<"the array is "<<endl;
	while(i<length)
	{ 
	    fscanf(fp,"%d",(array+i));
		//infile >> array[i];
		//printf("%d",(array+i));
		*(newarray+i)=(double)*(array+i);
		
		cout <<newarray[i]<<" ";
		i++;
		}
		cout<<endl;
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

void Signal::Sig_info()
{
	int i;
	double m=0,total=0;
	for(i=0;i<length;i++)
	{
		if(*(newarray+i)>*(newarray+i+1))
		{
			m=(double)*(newarray+i);
			
		}
		total=total+*(newarray+i);
		i++;
	}
	printf("the length is %d \n",length);
	max=m;
	printf("the maximum is %f \n",m);
	average=total/length;
	printf("the average is %f",average);
}

//double* 
void Signal::do_offset(double offset1)
{
	
	//double * data_offset= (double*)malloc(length*sizeof(double));
	int i=0;
	while(i<length)
	{ 

		*(newarray+i)=*(newarray+i)+offset1;
		cout<<newarray[i]<<endl;
		//printf("\n %.4f",*(data_offset+i));
		//printf("%d",*(newarray+i));
		i++;
	
}
//free(data_offset);
//return data_offset;
}

void Signal::do_scale(double scale1)
{
	int i=0;
	while(i<length)
	{ 

		*(newarray+i)=(double)*(newarray+i)*(scale1);
		cout<<newarray[i]<<endl;
		//printf("\n %.4f",*(newarray+i));
		//printf("%d",*(newarray+i));
		i++;
	
}
	
}




	
	double Signal::do_average()
	{
		int i;
	double total=0;
	for(i=0;i<length;i++)
	{
		
		total=total+(double)*(array+i);
		
	}
	//printf("the total is %f\n",total);
	average=total/length;
	//printf("the average is %f",average);
	return average;
	}
	
void Signal::center(double mean1)
{
	int i = 0;
	while(i < length){
		*(newarray+i)= *(array+i)-mean1;
		printf("\n %.4f",*(newarray+i));	
			
		i++;
	}
	
}
void Signal::normalize(void)
{
	int i = 0;
	//cout<<maximum_value<<endl;
	while(i < length){
		*(newarray+i)= (double)*(newarray+i)/maximum_value;
		printf("\n %.4f",*(newarray+i));	
			
		i++;
	}
	

	
}
void Signal::save_file(char name[])
{
	FILE*fp2;
	 
	 fp2 = fopen(name,"w");
	 int i=0;
	 fprintf(fp2,"%f\n",max);
	while(i<length)
	{ 
		fprintf(fp2,"%f \n" , *(newarray+i));
		i++;
		
	}
	
	fclose(fp2);
	
}



int main (int argc, char *argv[]) {
	int i = 1,count;
	int value,length;
	double offset, scale;
	int* ayeray;  // array
	double* ayeray2;
	double* ayeray3;
	double mean;
	char myname[100];
	char* filename;
	
	//if (argc<=1){
	//	cout<<"wrong input"<<endl;
	//}
	value = atof(argv[2]);
	Signal signal1(value);
	
start:	
	cout<<"Please choose an option!"<<endl;
	cout<<"1:Do offset"<<endl;
	cout<<"2:Do Scale"<<endl;
	cout<<"3:Do center"<<endl;
	cout<<"4:Do Normalization"<<endl;
	cout<<"5:Do statistics"<<endl;
	cout<<"6:Print to a file"<<endl;
	
	cin>>count;
	
	switch(count)
	{

	case 1:
		cout<<"please input offset number!"<<endl;
		cin>>offset;
		
		//Signal signal1(value);
		signal1.do_offset(offset);
		signal1.Sig_info();
		goto start;
		break;	
		
	case 2:
	cout<<"please input scale number!"<<endl;
	cin>>scale;
	//cout<<scale;
	
	//Signal signal1(value);
		signal1.do_scale(scale);
		//signal1.Sig_info();
		goto start;
		break;
	case 3:
		mean=signal1.do_average();
		signal1.center(mean);
		goto start;
	
	break;
	case 4:
	signal1.normalize();
	goto start;
	break;
	case 5:
	signal1.Sig_info();
	break;
	case 6:
	cout<<"please input the output filename!"<<endl;
	cin>>myname;
	signal1.save_file(myname);
	break;
	default:
	break;
	}
	
  //cout<<"please input"<<endl;

	}
  

	