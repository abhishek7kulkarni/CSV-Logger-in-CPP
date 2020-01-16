/*
 * CSVLogger.cpp
 *
 *  Created on: 7 Jan 2020
 *      Author: abhishekkulkarni
 */

#include "CSVLogger.h"

CSVLogger::CSVLogger(const char* filename)
{
	csvfile_.open(filename, std::ios::out | std::ios::app);
}

CSVLogger::~CSVLogger()
{
	csvfile_.close();
}
