#include "cl_application.h"
cl_application::cl_application(cl_base* parent):cl_base(parent){}

void cl_application::signal(string& msg)
{
	cout << "\nSignal from " << this->get_path_to();
	msg += " (class: 1)";
}

void cl_application::slot(string& msg)
{
	cout << "\nSignal to " << this->get_path_to() << " Text: " << msg;
}

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
			break;
		}
		cin>>temp_object>>cl_num;
		cl_base* temp_root_obj= get_obj_by_path(path);
		if(temp_root_obj== nullptr)
		{
			cout<<"Object tree";
			print_tree(false);
			cout<<endl<<"\nThe head object "<<path<<" is not found";
			exit(0);
		}

		cl_base* child= nullptr;
		if(cl_num==2)
			child=new cl_node2(temp_root_obj,temp_object);
		else if(cl_num==3)
			child=new cl_node3(temp_root_obj,temp_object);
		else if(cl_num==4)
			child=new cl_node4(temp_root_obj,temp_object);
		else if(cl_num==5)
			child=new cl_node5(temp_root_obj,temp_object);
		else if(cl_num==6)
			child=new cl_node6(temp_root_obj,temp_object);
		child->set_num(cl_num);
	}
	string first_part, second_part;
	while (true)
	{
		cin >> first_part;
		if (first_part == "end_of_connections")
			return;
		cl_base* from = get_obj_by_path(first_part);
		if (from == nullptr)
		{
			cout << "\nObject " << first_part << " not found";
		}
		else
		{
			cin >> second_part;
			cl_base* to = get_obj_by_path(second_part);
			if (to == nullptr)
			{
				cout << "\nHandler object " << second_part << " not found";
			}
			else
			{
				from->set_connect(get_signal(from->get_num()), get_slot(to->get_num()), to);
			}
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
	ready_prepare();
	string cmd,first_part,second_part,msg;
	int condition;
	while(true)
	{
		cin>>cmd;
		if(cmd=="END")
			break;
		else if (cmd=="SET_CONDITION"|| cmd=="EMIT" || cmd=="SET_CONNECT" || "DELETE_CONNECT")
		{
			cin>>first_part;
			cl_base* from= get_obj_by_path(first_part);
			if(from == nullptr)
			{
				cout<<"\nObject "<<first_part<<" is not found";
			}
			else if(cmd=="SET_CONDITION")
			{
				cin>>condition;
				from->condition_setter(condition);
			}
			else if(cmd=="EMIT")
			{
				getline(cin, msg);
				from->emit_signal(get_signal(from->get_num()), msg);
			}
			else
			{
				cin >> second_part;
				cl_base* to = get_obj_by_path(second_part);
				if (to == nullptr)
				{
					cout << "\nHandler object " << first_part << " is not found";
				}
				else if(cmd=="SET_CONNECT")
				{
					from->set_connect(get_signal(from->get_num()), get_slot(to->get_num()),to);
				}
				else if(cmd=="DELETE_CONNECT")
				{
					from->delete_connect(get_signal(from->get_num()),get_slot(to->get_num()), to);
				}
			}
		}
	}
	return 1;
}

TYPE_SIGNAL cl_application::get_signal(int cl_num)
{
	if (cl_num == 1)
		return SIGNAL(&cl_application::signal);
	if (cl_num == 2)
		return SIGNAL(&cl_node2::signal);
	if (cl_num == 3)
		return SIGNAL(&cl_node3::signal);
	if (cl_num == 4)
		return SIGNAL(&cl_node4::signal);
	if (cl_num == 5)
		return SIGNAL(&cl_node5::signal);
	if (cl_num == 6)
		return SIGNAL(&cl_node6::signal);
	return TYPE_SIGNAL();
}

TYPE_SLOT cl_application::get_slot(int cl_num)
{
	if (cl_num == 1)
		return SLOT(&cl_application::slot);
	if (cl_num == 2)
		return SLOT(&cl_node2::slot);
	if (cl_num == 3)
		return SLOT(&cl_node3::slot);
	if (cl_num == 4)
		return SLOT(&cl_node4::slot);
	if (cl_num == 5)
		return SLOT(&cl_node5::slot);
	if (cl_num == 6)
		return SLOT(&cl_node6::slot);
	return TYPE_SLOT();
}