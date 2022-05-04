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
	if(out_condition!=0)
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
void cl_base::condition_setter(int condition_position)
{
	if(condition_position!=0)
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
	}
	else
	{
		for(int i=0;i<children.size();i++)
		{
			children[i]->condition_setter(0);
		}
	}
	condition=condition_position;
}
int cl_base::condition_getter()
{
	return condition;
}

cl_base* cl_base::get_obj_by_path(string path)
{
	if((path[0]=='/') && (path[1]=='/'))
	{
		return root_getter()->get_obj_by_name(path.substr(2,string::npos));
	}
	if(path[0]=='.')
	{
		return this;
	}
	if(path.size()==1 && path[0] =='/')
	{
		return root_getter();
	}
	return route_getter(path);
}

cl_base* cl_base::route_getter(string object_route)
{
	bool abs =true;
	cl_base* temp=this;
	int index=1;
	string route_part;
	if(object_route[0]!='/')
	{
		object_route='/'+route_part;
		abs=false;
	}
	route_part= route_part_getter(object_route,index);
	if(abs)
	{
		temp=temp->child_getter(route_part);
	}
	else
		temp=temp->get_obj_by_name(route_part);
	while(temp)
	{
		index++;
		route_part= route_part_getter(object_route,index);
		if(route_part.empty())
		{
			return temp;
		}
		if(abs)
		{
			temp=temp->child_getter(object_route);
		}
		else
			temp=temp->get_obj_by_name(object_route);
	}
	return nullptr;
}

cl_base* cl_base::root_getter()
{
	cl_base* temp= this;
	while(temp->parent)
	{
		temp=temp->parent;
	}
	return temp;

}

string cl_base::route_part_getter(string path, int index)
{
	int end,start=1,lvl=1;
	while(start)
	{
		end=path.find('/',start);
		if(lvl==index)
		{
			return path.substr(start,end-start);
		}
		start=end+1;
		lvl++;
	}
	return "";
}

cl_base* cl_base::child_getter(string name)
{
	for(int i=0;i<children.size();i++)
	{
		if(children[i]->get_name()==name)
		{
			return children[i];
		}
	}
	return nullptr;
}