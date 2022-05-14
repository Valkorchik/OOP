#include "cl_node2.h"
cl_node2::cl_node2(cl_base* parrent, std::string object_name): cl_base(parrent,object_name)
{};
void cl_node2::signal(std::string& msg)
{
	std::cout << "\nSignal from " << this->get_path_to();
	msg += " (class: 2)";
}

void cl_node2::slot(std::string msg)
{
	std::cout << "\nSignal to " << this->get_path_to() << " Text: " << msg;
}