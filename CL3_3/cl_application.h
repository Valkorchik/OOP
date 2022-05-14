#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H
#include "cl_base.h"
#include "cl_node2.h"
#include "cl_node3.h"
#include "cl_node4.h"
#include "cl_node5.h"
#include "cl_node6.h"
using namespace std;
class cl_application : public cl_base
{
public:
	cl_application(cl_base* parent);
	void signal(string& cmd);
	void slot(string& cmd);
	void bild_tree_objects();
	void condition_insert();
	int exec_app();
	TYPE_SIGNAL get_signal(int cl_num);
	TYPE_SLOT get_slot(int cl_num);
};
#endif