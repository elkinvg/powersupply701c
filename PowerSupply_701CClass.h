/*----- PROTECTED REGION ID(PowerSupply_701CClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        PowerSupply_701CClass.h
//
// description : Include for the PowerSupply_701C root class.
//               This class is the singleton class for
//                the PowerSupply_701C device class.
//               It contains all properties and methods which the 
//               PowerSupply_701C requires only once e.g. the commands.
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef PowerSupply_701CClass_H
#define PowerSupply_701CClass_H

#include <tango.h>
#include <PowerSupply_701C.h>


/*----- PROTECTED REGION END -----*/	//	PowerSupply_701CClass.h


namespace PowerSupply_701C_ns
{
/*----- PROTECTED REGION ID(PowerSupply_701CClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	PowerSupply_701CClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Voltage class definition
class VoltageAttrib: public Tango::Attr
{
public:
	VoltageAttrib():Attr("Voltage",
			Tango::DEV_SHORT, Tango::READ_WRITE) {};
	~VoltageAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<PowerSupply_701C *>(dev))->read_Voltage(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<PowerSupply_701C *>(dev))->write_Voltage(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<PowerSupply_701C *>(dev))->is_Voltage_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command ChargingOn class definition
class ChargingOnClass : public Tango::Command
{
public:
	ChargingOnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ChargingOnClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ChargingOnClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<PowerSupply_701C *>(dev))->is_ChargingOn_allowed(any);}
};

//	Command ChargingOff class definition
class ChargingOffClass : public Tango::Command
{
public:
	ChargingOffClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ChargingOffClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ChargingOffClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<PowerSupply_701C *>(dev))->is_ChargingOff_allowed(any);}
};

//	Command SetVoltage class definition
class SetVoltageClass : public Tango::Command
{
public:
	SetVoltageClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetVoltageClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetVoltageClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<PowerSupply_701C *>(dev))->is_SetVoltage_allowed(any);}
};

//	Command CheckAdcOutput class definition
class CheckAdcOutputClass : public Tango::Command
{
public:
	CheckAdcOutputClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	CheckAdcOutputClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~CheckAdcOutputClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<PowerSupply_701C *>(dev))->is_CheckAdcOutput_allowed(any);}
};


/**
 *	The PowerSupply_701CClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  PowerSupply_701CClass : public Tango::DeviceClass
#else
class PowerSupply_701CClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(PowerSupply_701CClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	PowerSupply_701CClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static PowerSupply_701CClass *init(const char *);
		static PowerSupply_701CClass *instance();
		~PowerSupply_701CClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		PowerSupply_701CClass(string &);
		static PowerSupply_701CClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	PowerSupply_701C_H
