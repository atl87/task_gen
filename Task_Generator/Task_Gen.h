/* 
 * File:   Task_Gen.h
 * Author: atl05
 *
 * Created on August 29, 2014, 3:07 PM
 */

#ifndef TASK_GEN_H
#define	TASK_GEN_H

#include"Tasks.h"


int UUniFast(int number_of_tasks, double total_util, real_time_taskset *taskset);
int create_tasks(int number_of_tasks, real_time_taskset *taskset);

#endif	/* TASK_GEN_H */

