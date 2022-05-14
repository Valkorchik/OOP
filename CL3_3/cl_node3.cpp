#include "cl_node3.h"
cl_node3::cl_node3(cl_base* parrent, std::string object_name): cl_base(parrent,object_name)
{};
void cl_node3::signal(std::string& msg)
{
	std::cout << "\nSignal from " << this->get_path_to();
	msg += " (class: 3)";
}

void cl_node3::slot(std::string msg)
{
	std::cout << "\nSignal to " << this->get_path_to() << " Text: " << msg;
}