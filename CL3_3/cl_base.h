#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cl_base;
typedef void (cl_base::*TYPE_SIGNAL)(string&);
typedef void (cl_base::* TYPE_SLOT)(string);
#define SIGNAL(signal_d) (TYPE_SIGNAL)(signal_d)
#define SLOT(slot_d) (TYPE_SLOT)(slot_d)

class cl_base {
private:
	string object_name;
	cl_base *parent;
	vector<cl_base*> children;
	int condition = 0;
	void remove(string name);
	void add(cl_base *parent);
	struct connect
	{
		cl_base* base;
		TYPE_SIGNAL sig;
		TYPE_SLOT slt;
	};
	vector<connect> connects;
	int cl_num=1;
public:
	cl_base(cl_base* parent, string object_name="empty");
	void name_setter(string name);
	void parent_setter(cl_base* parent);
	cl_base* get_parent();
	string get_name();
	cl_base* get_obj_by_name(string object_name);
	void print_tree(bool out_condition=false,const int lvl=0);
	void condition_setter(int condition_position);
	int condition_getter();
	cl_base* get_obj_by_path(string path);
	cl_base* route_getter(string object_route);
	cl_base* root_getter();
	string route_part_getter(string path, int index);
	cl_base* child_getter(string name);
	string get_path_to();
	void set_connect(TYPE_SIGNAL sig, TYPE_SLOT slt, cl_base* obj_slot);
	void delete_connect(TYPE_SIGNAL sig, TYPE_SLOT slt, cl_base* obj_slot);
	void emit_signal(TYPE_SIGNAL sig,string& cmd);
	int get_num();
	void set_num(int cl_num);
	void ready_prepare();
};
#endif