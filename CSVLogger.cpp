/*
 * CSVLogger.cpp
 *
 *  Created on: 7 Jan 2020
 *      Author: abhishekkulkarni
 */
#include <ctime>
#include <string.h>
#include "CSVLogger.h"

CSVLogger::CSVLogger(const char* filename)
{
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);

	char datetime[20];
	strftime(datetime, 20, "_%Y%m%d%H%M%S.csv", local_time);

	char filename_timestamp[100];
	strcpy(filename_timestamp,filename);
	strcat(filename_timestamp,datetime);

	csvfile_.open(filename_timestamp, std::ios::out | std::ios::app);
}

CSVLogger::~CSVLogger()
{
	csvfile_.close();
}
