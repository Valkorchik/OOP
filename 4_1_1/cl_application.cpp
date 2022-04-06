#include "cl_application.h"
cl_application::cl_application(cl_base* parent):cl_base(parent){}
void cl_application::bild_tree_objects()
{
	string temp_root,temp_object;
	cl_base* temp_root_obj;
	cin >> temp_root;
	this->name_setter(temp_root);
	while (true)
	{
		cin >> temp_root >> temp_object;
		if (temp_root == temp_object)
		{
			return;
		}
		temp_root_obj= get_obj_by_name(temp_root);
		if(temp_root_obj!= nullptr)
		{
			new cl_node(temp_root_obj,temp_root);
		}
	}
}
int cl_application::exec_app()
{
	print_tree();
	return 0;
}