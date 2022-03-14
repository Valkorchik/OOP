#include "cl_application.h"
cl_application::cl_application(cl_base* parent)
{
	cl_base::root->parent_setter(parent);
	cl_base::root->name_setter("root");
	cl_base::root->children.push_back(root);
}
void cl_application::bild_tree_objects()
{
	string name1, name2;
	cin >> name1;
	cl_base* child = new cl_base(name1, nullptr);
	while (true)
	{
		cin >> name1 >> name2;
		if (name1 == name2)
		{
			return;
		}
		cl_base* child2 = new cl_base(name2, root->get_object_by_name(name1));
		child = child2;
	}
}
int cl_application::exec_app()
{
	cout << root->children[1]->get_name();
	root->children[1]->print_tree();
	return 0;
}