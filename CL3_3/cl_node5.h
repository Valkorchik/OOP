#ifndef CL_NODE5_H
#define CL_NODE5_H
#include "cl_base.h"
class cl_node5 : public cl_base
{
public:
	cl_node5(cl_base* parrent, std::string object_name);
	void signal(string& msg);
	void slot(string msg);
};
#endif