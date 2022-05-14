#include "cl_node6.h"
cl_node6::cl_node6(cl_base* parrent, std::string object_name): cl_base(parrent,object_name)
{};

void cl_node6::signal(std::string& msg)
{
	std::cout << "\nSignal from " << this->get_path_to();
	msg += " (class: 6)";
}

void cl_node6::slot(std::string msg)
{
	std::cout << "\nSignal to " << this->get_path_to() << " Text: " << msg;
}