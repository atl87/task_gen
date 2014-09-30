#include"Task_Gen.h"
#include"Tasks.h"
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<time.h>

using namespace std;


int UUniFast(int number_of_tasks, double total_util, real_time_taskset* taskset)
{
    double remaining_util=0.0000;
    int counter=0;
    
    double util_sum=total_util;
    real_time_taskset *helper=taskset;

    
    if(helper==NULL)
        exit(1);
    
    
    while(counter < number_of_tasks-1)
    {
        
        double power=1.000/(number_of_tasks-counter);
        double base=(double) rand()/(double) RAND_MAX;
        double task_util=0.000;
        double base_power=pow(base,power);
        
        remaining_util=util_sum*base_power;
        cout<<"\n"<<util_sum-remaining_util<<" ";
        
        task_util=util_sum-remaining_util;
        
        helper->period=(double)(rand()%10000);
        helper->comp_time=floor(helper->period*task_util);
        helper->utilization=helper->comp_time/helper->period;
        
        if(helper->utilization>=1.0000)
        {
            cout<<"\n\n\t---One task has utilization greater than 100%";
            
            return 0;
        }
        
        helper->task_no=counter+1;
        helper->deadline= (double)((rand() % (int)(helper->period-helper->comp_time)) + helper->comp_time+1);
        
        //cout<<"\nLast task utilization: "<<helper->utilization<<" ";
        helper=helper->next_task;
          
        util_sum=remaining_util;
        counter++;  
        
    }
    
    helper->period=(double)(rand()%10000);
    helper->comp_time=floor(helper->period*util_sum);
    helper->utilization=helper->comp_time/helper->period;
    helper->task_no=counter+1;
    helper->deadline= (double)((rand() % (int)(helper->period-helper->comp_time)) + helper->comp_time+1);
    
    if(helper->utilization> 1.0000)
    {
        cout<<"\n\n\t---One task has utilization greater than 100%";
        return 0;
    }
        
    
    cout<<util_sum<<" ";
    
    return 1;
}


int create_tasks(int number_of_tasks, real_time_taskset *taskset)
{
    
    real_time_taskset *helper=NULL;
    
    helper=taskset;
    
    for(int i=1;i<number_of_tasks;i++)
    {
        helper->task_no=i+1;
        real_time_taskset *helper1=(real_time_taskset*)malloc(sizeof(real_time_taskset));
        helper->next_task=helper1;
        helper=helper->next_task;
    }
    
    helper->next_task=NULL;
    
    return 1;
    
}