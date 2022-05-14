#ifndef CL_NODE4_H
#define CL_NODE4_H
#include "cl_base.h"
class cl_node4 : public cl_base
{
public:
	cl_node4(cl_base* parrent, std::string object_name);
	void signal(string& msg);
	void slot(string msg);
};
#endif