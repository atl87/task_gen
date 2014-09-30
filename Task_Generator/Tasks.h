/* 
 * File:   Tasks.h
 * Author: atl05
 *
 * Created on August 29, 2014, 3:20 PM
 */

#ifndef TASKS_H
#define	TASKS_H

struct real_time_taskset{
    
    int task_no;
    double comp_time;
    double period;
    double deadline;
    double utilization;
    
    real_time_taskset *next_task;
};

real_time_taskset *print_task(real_time_taskset *tasket);
int delete_taskset(real_time_taskset *taskset);
int write_taskset_to_file(int task_set_no, real_time_taskset *taskset);



#endif	/* TASKS_H */

