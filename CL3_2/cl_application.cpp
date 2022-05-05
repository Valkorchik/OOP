#include "cl_application.h"
cl_application::cl_application(cl_base* parent):cl_base(parent){}
void cl_application::bild_tree_objects()
{
	string temp_object,path;
	int cl_num;
	cin >> temp_object;
	this->name_setter(temp_object);
	while (true)
	{
		cin >> path;
		if (path == "endtree")
		{
			return;
		}
		cin>>temp_object>>cl_num;
		cl_base* temp_root_obj= get_obj_by_path(path);
		if(temp_root_obj== nullptr)
		{
			cout<<"Object tree";
			print_tree(false);
			cout<<endl<<"The head object "<<path<<" is not found";
			exit(0);
		}

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
	string cmd,path;
	cl_base* temp;
	cl_base* obj=this;
	while(true)
	{
		cin>>cmd;
		if(cmd=="END")
			break;
		cin>>path;
		cout<<endl;
		temp=obj->get_obj_by_path(path);

		if(cmd=="SET")
		{
			if(temp!= nullptr)
			{
				obj=temp;
				cout<<"Object is set: "<<obj->get_name();
			}
			else
				cout<<"Object is not found: "<<temp->get_name()<<" "<<path;
		}
		if(cmd =="FIND")
		{
			if(temp!= nullptr)
				cout<<path<<"     Object name: "<<temp->get_name();
			else cout<<path<<"     Object is not found";
		}
	}
	return 1;

}
