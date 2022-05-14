#ifndef CL_NODE3_H
#define CL_NODE3_H
#include "cl_base.h"
class cl_node3 : public cl_base
{
public:
	cl_node3(cl_base* parrent, std::string object_name);
	void signal(string& msg);
	void slot(string msg);
};
#endif