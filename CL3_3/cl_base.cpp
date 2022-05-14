#include "cl_base.h"
#include <string>
cl_base::cl_base(cl_base* parent, string object_name)
{
	this->object_name = object_name;
	this->parent=parent;
	if (parent!=nullptr)
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
	if(this->object_name==name)
	{
		return this;
	}
	for (int i = 0; i < children.size(); i++)
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
	if(out_condition==true)
	{
		if(this->condition_getter()!=0)
			cout<<" is ready";
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
		this->condition=condition_position;
	}
	else
	{
		this->condition=condition_position;
		for(int i=0;i<children.size();i++)
		{
			children[i]->condition_setter(0);
		}
	}

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
		object_route="/"+object_route;
		abs=false;
	}
	route_part= route_part_getter(object_route,index);
	if(abs==true)
	{
		temp=child_getter(route_part);
	}
	else
		temp=get_obj_by_name(route_part);
	while(temp)
	{
		index++;
		route_part= route_part_getter(object_route,index);
		if(route_part.empty())
		{
			return temp;
		}
		if(abs==true)
		{
			temp=temp->child_getter(route_part);
		}
		else
			temp=temp->get_obj_by_name(route_part);
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
	int end;
	int start=1;
	int lvl=1;
	while(start)
	{
		end=path.find("/",start);
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

string cl_base::get_path_to()
{
	string path;
	cl_base* temp = this;
	while (temp->parent)
	{
		path = "/" + temp->get_name() + path;
		temp = temp->parent;
	}
	if (path.empty())
		return "/";
	return path;
}

void cl_base::set_connect(TYPE_SIGNAL sig, TYPE_SLOT slt, cl_base* obj_slot)
{
	for (connect c : connects)
	{
		if (c.sig == sig && c.slt == slt && c.base == obj_slot)
			return;
	}
	connect c = { obj_slot, sig, slt };
	connects.push_back(c);
}

void cl_base::delete_connect(TYPE_SIGNAL sig, TYPE_SLOT slt, cl_base* obj_slot)
{
	for (auto it = connects.begin(); it != connects.end(); it++)
	{
		if (it->sig == sig && it->slt == slt && it->base ==obj_slot)
		{
			connects.erase(it);
			return;
		}
	}
}
void cl_base::emit_signal(TYPE_SIGNAL sig,string& cmd)
{
	TYPE_SLOT slot;
	if(this->condition_getter()!=0)
	{
		(this->*sig)(cmd);
		for (int i = 0; i < connects.size(); i++)
		{
			if (connects[i].sig == sig && connects[i].base->condition_getter() != 0)
			{
				slot = connects[i].slt;
				(connects[i].base->*slot)(cmd);
			}
		}
	}
}
int cl_base::get_num()
{
	return cl_num;
}

void cl_base::set_num(int cl_num)
{
	this->cl_num=cl_num;
}

void cl_base::ready_prepare()
{
	this->condition_setter(1);
	for(int i = 0; i < children.size(); i++)
	{
		children[i]->ready_prepare();
	}
}