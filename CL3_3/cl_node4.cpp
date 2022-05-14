#include "cl_node4.h"
cl_node4::cl_node4(cl_base* parrent, std::string object_name): cl_base(parrent,object_name)
{};
void cl_node4::signal(std::string& msg)
{
	std::cout << "\nSignal from " << this->get_path_to();
	msg += " (class: 4)";
}

void cl_node4::slot(std::string msg)
{
	std::cout << "\nSignal to " << this->get_path_to() << " Text: " << msg;
}