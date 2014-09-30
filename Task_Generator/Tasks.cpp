#include"Tasks.h"
#include<iostream>
#include<cmath>
#include<iostream>
#include<fstream>
#include<time.h>

using namespace std;

real_time_taskset *print_task(real_time_taskset *taskset)
{
    if(taskset==NULL)
        cout<<"Error: No task to print !";
    else
    {
        //Code to sort
        
       real_time_taskset *sort_help1=taskset;
        while(sort_help1)
        {
            real_time_taskset *sort_help2=sort_help1->next_task;
            while(sort_help2)
            {
                if(sort_help1->deadline > sort_help2->deadline)
                {
                    real_time_taskset *prev_task1=taskset;
                    if(sort_help1!=taskset)
                    {             
                        while(prev_task1->next_task!=sort_help1)
                                prev_task1=prev_task1->next_task;
                    }
                        
                    real_time_taskset *prev_task2=taskset;
                    while(prev_task2->next_task!=sort_help2)
                        prev_task2=prev_task2->next_task;
                    
                    real_time_taskset *dummy=sort_help1->next_task;
                    
                    if(sort_help1!=taskset)
                    {                        
                        prev_task2->next_task=sort_help1;
                        sort_help1->next_task=sort_help2->next_task;
                        if(prev_task1!=sort_help1)
                                prev_task1->next_task=sort_help2;
                        
                        if(dummy!=sort_help2)
                                sort_help2->next_task=dummy;
                        else
                                sort_help2->next_task=sort_help1;
 
                    }
                    else
                    {
                        prev_task2->next_task=sort_help1;
                        sort_help1->next_task=sort_help2->next_task;
                        
                        if(sort_help2!=dummy)
                                sort_help2->next_task=dummy;
                        else
                                sort_help2->next_task=sort_help1;
                        
                        taskset=sort_help2;
                        
                    }
                               
                    dummy=sort_help1;
                    sort_help1=sort_help2;
                    sort_help2=dummy;
   
                }
                
                sort_help2=sort_help2->next_task;
            }
            
            sort_help1=sort_help1->next_task;
        }
        
        
        //Code to print
        
        real_time_taskset *help_ptr=taskset;
        cout<<"\n\nPrinting the taskset!!\n\n";
        int counter=1;
        while(help_ptr!=NULL)
        {
            help_ptr->task_no=counter;
            cout<<help_ptr->task_no<<"\t"<<help_ptr->comp_time<<"\t"<<help_ptr->deadline<<"\t"<<help_ptr->period<<"\n";
            help_ptr=help_ptr->next_task;
            counter++;
        }
    }
    
    return taskset;
}

int delete_taskset(real_time_taskset *taskset)
{
    real_time_taskset *helper=taskset;
    
    while(taskset)
    {
        helper=taskset;
        taskset=taskset->next_task;
        free(helper);
    }
    
    cout<<"\n\nSuccessfully deleted the taskset!";
    return 1;
}
int write_taskset_to_file(int task_set_no, real_time_taskset *taskset)
{
    
    char task_set_name[100];
    char utilization_filename[50];
    fstream fobj_task, fobj_utilization;
    real_time_taskset *helper=taskset;
    double total_util=0.00;
    
    
    sprintf(task_set_name,"./Tasksets/task_set%d.dat",task_set_no); 
    sprintf(utilization_filename,"./Tasksets/a-utilization.dat");
    
    fobj_task.open(task_set_name,ios::out | ios::app);
    if(!fobj_task)
    {
        cout<<"\nError opening file: "<<task_set_name;
        exit(1);
    }
    else
        cout<<"\nSuccessfully opened file: "<<task_set_name<<"\n";
    
    fobj_utilization.open(utilization_filename,ios::out|ios::app);
    if(!fobj_utilization)
    {
        cout<<"\nError opening file: "<<utilization_filename;
        exit(0);
    }
    else
        cout<<"\nSuccessfully opened file: "<<utilization_filename<<"\n";
    
    while(helper)
    {
        //cout<<helper->task_no<<"\t"<<helper->comp_time<<"\t"<<helper->deadline<<"\t"<<helper->period<<"\n";
        fobj_task<<helper->task_no<<"\t"<<helper->comp_time<<"\t"<<helper->deadline<<"\t"<<helper->period<<"\n";
        total_util=total_util+helper->utilization;
        
        helper=helper->next_task;
    }
    
    
    fobj_utilization<<total_util<<"\n";    
    
    return 1;
}