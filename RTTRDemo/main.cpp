#include <rttr/registration>
#include <rttr/type.h>
#include <QDebug>
#include <iostream>
using namespace std;

using namespace rttr;

struct MyStruct{

	MyStruct(){};
	void func(double value){cout << "value: " << value << endl;};
	int data;
};

int main(int argc, char *argv[]){

	qDebug() << "RTTR Demo";

	//manual registration
	registration::class_<MyStruct>("MyStruct")
		.constructor<>()
		.property("data", &MyStruct::data)
		.method("func", &MyStruct::func);

	//iterate over members
	{
	type t = type::get<MyStruct>();
	for(auto &prop : t.get_properties())
		cout << "name: " << prop.get_name() << endl;
	for(auto &meth : t.get_methods())
		cout << "name: " << meth.get_name() << endl;
	}

	qDebug() << "---------------------------";

	//constructing type
	{
	type t = type::get_by_name("MyStruct");
	variant var = t.create();
	constructor ctor = t.get_constructor();
	var = ctor.invoke();
	cout << var.get_type().get_name() << endl;
	}

	qDebug() << "---------------------------";

	//Set/get properties
	{
	MyStruct obj;
	property prop = type::get(obj).get_property("data");
	prop.set_value(obj, 23);
	
	variant var_prop = prop.get_value(obj);
	cout << var_prop.to_int() << endl;
	}

	qDebug() << "---------------------------";

	//Invoke methods
	{
	MyStruct obj;
	method meth = type::get(obj).get_method("func");
	meth.invoke(obj, 42.0);
	variant var = type::get(obj).create();
	meth.invoke(var, 43.0);
	}

	return 0;
}
