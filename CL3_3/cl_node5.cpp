#include "cl_node5.h"
cl_node5::cl_node5(cl_base* parrent, std::string object_name): cl_base(parrent,object_name)
{};
void cl_node5::signal(std::string& msg)
{
	std::cout << "\nSignal from " << this->get_path_to();
	msg += " (class: 5)";
}

void cl_node5::slot(std::string msg)
{
	std::cout << "\nSignal to " << this->get_path_to() << " Text: " << msg;
}