#pragma once
#include "ProcessChain.h"
#include "DoOnce.h"
#include "DoOnUpdate.h"
#include "WaitForSeconds.h"
#include <vector>

class Processor
{
	std::vector<ProcessChain*> processes;

public:

	void StartProcess(ProcessChain* process);

	void EndProcess(std::string processToEnd);

	void EndAllProcesses();

	EventListener<ProcessChain*>* RemoveProcessFromList = new EventListener<ProcessChain*>([this](ProcessChain* process) {
		for (size_t i = 0; i < processes.size(); i++)
		{
			if (processes.at(i) == process) {
				processes.erase(processes.begin() + i);
			}
		}
	});

	virtual ~Processor() = 0;
};
