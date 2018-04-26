#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int array[1000];

void* sum_array(void* arg)
{
	int sum=0;
	int start=(int)arg;
	int finish=start+100;
	for(int i=start;i<finish;i++)
	{
		sum=sum+array[i];
	}
	return (void*)sum;
}

int main()
{
	
	for (int i=0;i<1000;i++)
	{
		array[i]=i;
	}
	//to store separate sum of threads
	void *inner_sum[10];
	//to store total sum 
	int total_sum=0;
	
	//making threads
	pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10;
	
	pthread_create(&thread1,NULL,sum_array,(void*)0);
	pthread_create(&thread2,NULL,sum_array,(void*)100);
	pthread_create(&thread3,NULL,sum_array,(void*)200);
	pthread_create(&thread4,NULL,sum_array,(void*)300);
	pthread_create(&thread5,NULL,sum_array,(void*)400);
	pthread_create(&thread6,NULL,sum_array,(void*)500);
	pthread_create(&thread7,NULL,sum_array,(void*)600);
	pthread_create(&thread8,NULL,sum_array,(void*)700);
	pthread_create(&thread9,NULL,sum_array,(void*)800);
	pthread_create(&thread10,NULL,sum_array,(void*)900);
	
	// joining thread so that they wait for each other
	
	pthread_join(thread1,&inner_sum[0]);
	total_sum=total_sum+(int)inner_sum[0];
	
	pthread_join(thread2,&inner_sum[1]);
	total_sum=total_sum+(int)inner_sum[1];
	
	pthread_join(thread3,&inner_sum[2]);
	total_sum=total_sum+(int)inner_sum[2];
	
	pthread_join(thread4,&inner_sum[3]);
	total_sum=total_sum+(int)inner_sum[3];
	
	pthread_join(thread5,&inner_sum[4]);
	total_sum=total_sum+(int)inner_sum[4];
	
	pthread_join(thread6,&inner_sum[5]);
	total_sum=total_sum+(int)inner_sum[5];
	
	pthread_join(thread7,&inner_sum[6]);
	total_sum=total_sum+(int)inner_sum[6];
	
	pthread_join(thread8,&inner_sum[7]);
	total_sum=total_sum+(int)inner_sum[7];
	
	pthread_join(thread9,&inner_sum[8]);
	total_sum=total_sum+(int)inner_sum[8];
	
	pthread_join(thread10,&inner_sum[9]);
	total_sum=total_sum+(int)inner_sum[9];
	
	//printing total sum of the  array
	
	printf("THE TOTAL SUM IS=%d",total_sum);
	
	return 0;
	
	
	
}
