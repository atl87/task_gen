/* 
 * File:   main.cpp
 * Author: atl05
 *
 * Created on August 29, 2014, 3:00 PM
 */

#include <cstdlib>
#include<iostream>
#include"Task_Gen.h"
#include<time.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int NUMBER_OF_TASKS=7;              //Change this for changing number of tasks
    double total_util=0.50;             //Change this for changing the required maximum utilization
    int NUMBER_OF_TASKSETS=500;
    int counter=1;
    int successful_parameter_generation=0;
    
    srand (time(NULL));
 
    while(counter<=NUMBER_OF_TASKSETS)
    {
        successful_parameter_generation=0;
        real_time_taskset *taskset=(real_time_taskset*) malloc(sizeof(real_time_taskset));
        while(!successful_parameter_generation)
        {
                cout<<"\n\nCreating real-time tasks";
                create_tasks(NUMBER_OF_TASKS,taskset);
                cout<<"-- created real-time tasks successfully!!";
                if(taskset==NULL)
                {
                        cout<<"-- taskset not created";
                        exit(1);
                }
    
                cout<<"\n\nGenerating taskset parameters";
                if(UUniFast(NUMBER_OF_TASKS,total_util,taskset)==1)
                {
                    successful_parameter_generation=1; 
                    cout<<"-- generated taskset parameters successfully!!";   
                    if(taskset==NULL)
                    {
                        cout<<"-- parameters not generated !";
                        exit(1);
                    }
                    taskset=print_task(taskset);
                    write_taskset_to_file(counter,taskset);  
                }
        }
        delete_taskset(taskset);
        
        
        counter++;
    }
    
    return 0;
}

