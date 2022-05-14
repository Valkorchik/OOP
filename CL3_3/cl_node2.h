#ifndef CL_NODE2_H
#define CL_NODE2_H
#include "cl_base.h"
class cl_node2 : public cl_base
{
public:
	cl_node2(cl_base* parrent, std::string object_name);
	void signal(string& msg);
	void slot(string msg);
};
#endif