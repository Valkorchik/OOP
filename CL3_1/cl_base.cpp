#include "cl_base.h"
#include <string>
cl_base::cl_base(cl_base* parent, string object_name)
{
	this->object_name = object_name;
	this->parent=parent;
	if (parent)
	{
		parent->add(this);
	}
}
void cl_base::name_setter(string name)
{
	this->object_name = name;
}
void cl_base::parent_setter(cl_base* parent)
{
	if (parent != nullptr)
	{
		parent->remove(object_name);
	}
	this->parent = parent;
	this->parent->add(this);
}
cl_base* cl_base::get_parent()
{
	return parent;
}
string cl_base::get_name()
{
	return object_name;
}
void cl_base::add(cl_base* children_point)
{
	if(children_point!= nullptr)
	{
		children.push_back(children_point);
	}
}
void cl_base::remove(string name)
{
	for (int i = 0; i <  children.size(); i++)
	{
		if (children[i]->get_name() == name)
		{
			children.erase(children.begin() + i);
			break;
		}
	}
}
cl_base* cl_base::get_obj_by_name(string name)
{
	if(object_name==name)
	{
		return this;
	}
	for (int i = 0; i < this->children.size(); i++)
	{
		cl_base* val = children[i]->get_obj_by_name(name);
		if (val!= nullptr)
		{
			return val;
		}
	}
	return nullptr;
}
void cl_base::print_tree(bool out_condition,const int lvl)
{
	cout<<endl;
	for(int i=0;i<lvl;i++)
	{
		cout<<"    ";
	}
	cout<<this->get_name();
	if(out_condition)
	{
		if(this->condition_getter())
		{
			cout<<" is ready";
		}
		else
			cout<<" is not ready";
	}
	if(children.size()>0)
	{
		for (int i = 0; i < children.size(); i++)
		{
			children[i]->print_tree(out_condition,lvl+1);
		}
	}
}
void cl_base::condition_setter(int condition_value)
{
	if(condition_value!=0)
	{
		cl_base* t_parent=get_parent();
		while(t_parent!= nullptr)
		{
			if(t_parent->condition_getter()==0)
			{
				return;
			}
			t_parent=t_parent->get_parent();
		}
		condition=true;
	}
}
bool cl_base::condition_getter()
{
	return condition;
}