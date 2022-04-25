#include "cl_application.h"
cl_application::cl_application(cl_base* parent):cl_base(parent){}
void cl_application::bild_tree_objects()
{
	string temp_root,temp_object;
	int cl_num;
	cl_base* temp_root_obj;
	cin >> temp_object;
	this->name_setter(temp_object);
	while (true)
	{
		cin >> temp_root;
		if (temp_root == "endtree")
		{
			break;
		}
		cin>>temp_object>>cl_num;
		temp_root_obj= get_obj_by_name(temp_root);
		switch(cl_num)
		{
			case 2:
				new cl_node2(temp_root_obj,temp_object);
				break;
			case 3:
				new cl_node3(temp_root_obj,temp_object);
				break;
			case 4:
				new cl_node4(temp_root_obj,temp_object);
				break;
			case 5:
				new cl_node5(temp_root_obj,temp_object);
				break;
			case 6:
				new cl_node6(temp_root_obj,temp_object);
				break;
			default:
				break;
		}

	}
}
void cl_application::condition_insert()
{
	string name_object;
	int condition_position;
	while(cin>>name_object>>condition_position)
	{
		get_obj_by_name(name_object)->condition_setter(condition_position);
	}
}
int cl_application::exec_app()
{
	cout<<"Object tree";
	print_tree(false);
	cout<<"\nThe tree of objects and their readiness";
	print_tree(true);
	return 0;
}