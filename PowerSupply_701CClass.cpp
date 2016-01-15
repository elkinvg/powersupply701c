/*----- PROTECTED REGION ID(PowerSupply_701CClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        PowerSupply_701CClass.cpp
//
// description : C++ source for the PowerSupply_701CClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the PowerSupply_701C once per process.
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


#include <PowerSupply_701CClass.h>

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass.cpp

//-------------------------------------------------------------------
/**
 *    Create PowerSupply_701CClass singleton and
 *    return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

    Tango::DeviceClass *_create_PowerSupply_701C_class(const char *name) {
        return PowerSupply_701C_ns::PowerSupply_701CClass::init(name);
    }
}

namespace PowerSupply_701C_ns
{
//===================================================================
//    Initialize pointer for singleton pattern
//===================================================================
PowerSupply_701CClass *PowerSupply_701CClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method :         PowerSupply_701CClass::PowerSupply_701CClass(string &s)
 * description :     constructor for the PowerSupply_701CClass
 *
 * @param s    The class name
 */
//--------------------------------------------------------
PowerSupply_701CClass::PowerSupply_701CClass(string &s):Tango::DeviceClass(s)
{
    cout2 << "Entering PowerSupply_701CClass constructor" << endl;
    set_default_property();
    write_class_property();

    /*----- PROTECTED REGION ID(PowerSupply_701CClass::constructor) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::constructor

    cout2 << "Leaving PowerSupply_701CClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method :         PowerSupply_701CClass::~PowerSupply_701CClass()
 * description :     destructor for the PowerSupply_701CClass
 */
//--------------------------------------------------------
PowerSupply_701CClass::~PowerSupply_701CClass()
{
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::destructor) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::destructor

    _instance = NULL;
}


//--------------------------------------------------------
/**
 * method :         PowerSupply_701CClass::init
 * description :     Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param    name    The class name
 */
//--------------------------------------------------------
PowerSupply_701CClass *PowerSupply_701CClass::init(const char *name)
{
    if (_instance == NULL)
    {
        try
        {
            string s(name);
            _instance = new PowerSupply_701CClass(s);
        }
        catch (bad_alloc &)
        {
            throw;
        }
    }
    return _instance;
}

//--------------------------------------------------------
/**
 * method :         PowerSupply_701CClass::instance
 * description :     Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
PowerSupply_701CClass *PowerSupply_701CClass::instance()
{
    if (_instance == NULL)
    {
        cerr << "Class is not initialised !!" << endl;
        exit(-1);
    }
    return _instance;
}



//===================================================================
//    Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method :         ChargingOnClass::execute()
 * description :     method to trigger the execution of the command.
 *
 * @param    device    The device on which the command must be executed
 * @param    in_any    The command input data
 *
 *    returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ChargingOnClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
    cout2 << "ChargingOnClass::execute(): arrived" << endl;
    ((static_cast<PowerSupply_701C *>(device))->charging_on());
    return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method :         ChargingOffClass::execute()
 * description :     method to trigger the execution of the command.
 *
 * @param    device    The device on which the command must be executed
 * @param    in_any    The command input data
 *
 *    returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ChargingOffClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
    cout2 << "ChargingOffClass::execute(): arrived" << endl;
    ((static_cast<PowerSupply_701C *>(device))->charging_off());
    return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method :         CheckAdcOutputClass::execute()
 * description :     method to trigger the execution of the command.
 *
 * @param    device    The device on which the command must be executed
 * @param    in_any    The command input data
 *
 *    returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *CheckAdcOutputClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
    cout2 << "CheckAdcOutputClass::execute(): arrived" << endl;
    return insert((static_cast<PowerSupply_701C *>(device))->check_adc_output());
}

//--------------------------------------------------------
/**
 * method :         CheckPSStateClass::execute()
 * description :     method to trigger the execution of the command.
 *
 * @param    device    The device on which the command must be executed
 * @param    in_any    The command input data
 *
 *    returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *CheckPSStateClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
    cout2 << "CheckPSStateClass::execute(): arrived" << endl;
    ((static_cast<PowerSupply_701C *>(device))->check_psstate());
    return new CORBA::Any();
}


//===================================================================
//    Properties management
//===================================================================
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::get_class_property()
 *    Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum PowerSupply_701CClass::get_class_property(string &prop_name)
{
    for (unsigned int i=0 ; i<cl_prop.size() ; i++)
        if (cl_prop[i].name == prop_name)
            return cl_prop[i];
    //    if not found, returns  an empty DbDatum
    return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::get_default_device_property()
 *    Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum PowerSupply_701CClass::get_default_device_property(string &prop_name)
{
    for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
        if (dev_def_prop[i].name == prop_name)
            return dev_def_prop[i];
    //    if not found, return  an empty DbDatum
    return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::get_default_class_property()
 *    Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum PowerSupply_701CClass::get_default_class_property(string &prop_name)
{
    for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
        if (cl_def_prop[i].name == prop_name)
            return cl_def_prop[i];
    //    if not found, return  an empty DbDatum
    return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::set_default_property()
 *    Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void PowerSupply_701CClass::set_default_property()
{
    string    prop_name;
    string    prop_desc;
    string    prop_def;
    vector<string>    vect_data;

    //    Set Default Class Properties

    //    Set Default device Properties
    prop_name = "Socket";
    prop_desc = "Tango device name in format ``domain/family/member``";
    prop_def  = "";
    vect_data.clear();
    if (prop_def.length()>0)
    {
        Tango::DbDatum    data(prop_name);
        data << vect_data ;
        dev_def_prop.push_back(data);
        add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
    }
    else
        add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::write_class_property()
 *    Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void PowerSupply_701CClass::write_class_property()
{
    //    First time, check if database used
    if (Tango::Util::_UseDb == false)
        return;

    Tango::DbData    data;
    string    classname = get_name();
    string    header;
    string::size_type    start, end;

    //    Put title
    Tango::DbDatum    title("ProjectTitle");
    string    str_title("");
    title << str_title;
    data.push_back(title);

    //    Put Description
    Tango::DbDatum    description("Description");
    vector<string>    str_desc;
    str_desc.push_back("");
    description << str_desc;
    data.push_back(description);

    //    put cvs or svn location
    string    filename("PowerSupply_701C");
    filename += "Class.cpp";

    // check for cvs information
    string    src_path(CvsPath);
    start = src_path.find("/");
    if (start!=string::npos)
    {
        end   = src_path.find(filename);
        if (end>start)
        {
            string    strloc = src_path.substr(start, end-start);
            //    Check if specific repository
            start = strloc.find("/cvsroot/");
            if (start!=string::npos && start>0)
            {
                string    repository = strloc.substr(0, start);
                if (repository.find("/segfs/")!=string::npos)
                    strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
            }
            Tango::DbDatum    cvs_loc("cvs_location");
            cvs_loc << strloc;
            data.push_back(cvs_loc);
        }
    }

    // check for svn information
    else
    {
        string    src_path(SvnPath);
        start = src_path.find("://");
        if (start!=string::npos)
        {
            end = src_path.find(filename);
            if (end>start)
            {
                header = "$HeadURL: ";
                start = header.length();
                string    strloc = src_path.substr(start, (end-start));

                Tango::DbDatum    svn_loc("svn_location");
                svn_loc << strloc;
                data.push_back(svn_loc);
            }
        }
    }

    //    Get CVS or SVN revision tag

    // CVS tag
    string    tagname(TagName);
    header = "$Name: ";
    start = header.length();
    string    endstr(" $");

    end   = tagname.find(endstr);
    if (end!=string::npos && end>start)
    {
        string    strtag = tagname.substr(start, end-start);
        Tango::DbDatum    cvs_tag("cvs_tag");
        cvs_tag << strtag;
        data.push_back(cvs_tag);
    }

    // SVN tag
    string    svnpath(SvnPath);
    header = "$HeadURL: ";
    start = header.length();

    end   = svnpath.find(endstr);
    if (end!=string::npos && end>start)
    {
        string    strloc = svnpath.substr(start, end-start);

        string tagstr ("/tags/");
        start = strloc.find(tagstr);
        if ( start!=string::npos )
        {
            start = start + tagstr.length();
            end   = strloc.find(filename);
            string    strtag = strloc.substr(start, end-start-1);

            Tango::DbDatum    svn_tag("svn_tag");
            svn_tag << strtag;
            data.push_back(svn_tag);
        }
    }

    //    Get URL location
    string    httpServ(HttpServer);
    if (httpServ.length()>0)
    {
        Tango::DbDatum    db_doc_url("doc_url");
        db_doc_url << httpServ;
        data.push_back(db_doc_url);
    }

    //  Put inheritance
    Tango::DbDatum    inher_datum("InheritedFrom");
    vector<string> inheritance;
    inheritance.push_back("TANGO_BASE_CLASS");
    inher_datum << inheritance;
    data.push_back(inher_datum);

    //    Call database and and values
    get_db_class()->put_property(data);
}

//===================================================================
//    Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::device_factory()
 *    Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void PowerSupply_701CClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::device_factory_before) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::device_factory_before

    //    Create devices and add it into the device list
    for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
    {
        cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
        device_list.push_back(new PowerSupply_701C(this, (*devlist_ptr)[i]));
    }

    //    Manage dynamic attributes if any
    erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

    //    Export devices to the outside world
    for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
    {
        //    Add dynamic attributes if any
        PowerSupply_701C *dev = static_cast<PowerSupply_701C *>(device_list[device_list.size()-i]);
        dev->add_dynamic_attributes();

        //    Check before if database used.
        if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
            export_device(dev);
        else
            export_device(dev, dev->get_name().c_str());
    }

    /*----- PROTECTED REGION ID(PowerSupply_701CClass::device_factory_after) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::device_factory_after
}
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::attribute_factory()
 *    Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void PowerSupply_701CClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::attribute_factory_before) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::attribute_factory_before
    //    Attribute : Voltage
    VoltageAttrib    *voltage = new VoltageAttrib();
    Tango::UserDefaultAttrProp    voltage_prop;
    //    description    not set for Voltage
    voltage_prop.set_label("Voltage");
    voltage_prop.set_unit("V");
    //    standard_unit    not set for Voltage
    //    display_unit    not set for Voltage
    //    format    not set for Voltage
    voltage_prop.set_max_value("500");
    voltage_prop.set_min_value("0");
    //    max_alarm    not set for Voltage
    //    min_alarm    not set for Voltage
    //    max_warning    not set for Voltage
    //    min_warning    not set for Voltage
    //    delta_t    not set for Voltage
    //    delta_val    not set for Voltage

    voltage->set_default_properties(voltage_prop);
    //    Not Polled
    voltage->set_disp_level(Tango::OPERATOR);
    //    Not Memorized
    att_list.push_back(voltage);

    //    Attribute : isExternalControl
    isExternalControlAttrib    *isexternalcontrol = new isExternalControlAttrib();
    Tango::UserDefaultAttrProp    isexternalcontrol_prop;
    //    description    not set for isExternalControl
    //    label    not set for isExternalControl
    //    unit    not set for isExternalControl
    //    standard_unit    not set for isExternalControl
    //    display_unit    not set for isExternalControl
    //    format    not set for isExternalControl
    //    max_value    not set for isExternalControl
    //    min_value    not set for isExternalControl
    //    max_alarm    not set for isExternalControl
    //    min_alarm    not set for isExternalControl
    //    max_warning    not set for isExternalControl
    //    min_warning    not set for isExternalControl
    //    delta_t    not set for isExternalControl
    //    delta_val    not set for isExternalControl

    isexternalcontrol->set_default_properties(isexternalcontrol_prop);
    //    Not Polled
    isexternalcontrol->set_disp_level(Tango::OPERATOR);
    //    Not Memorized
    att_list.push_back(isexternalcontrol);


    //    Create a list of static attributes
    create_static_attribute_list(get_class_attr()->get_attr_list());
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::attribute_factory_after) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::pipe_factory()
 *    Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void PowerSupply_701CClass::pipe_factory()
{
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::pipe_factory_before) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::pipe_factory_before
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::pipe_factory_after) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::command_factory()
 *    Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void PowerSupply_701CClass::command_factory()
{
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::command_factory_before) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::command_factory_before


    //    Command ChargingOn
    ChargingOnClass    *pChargingOnCmd =
        new ChargingOnClass("ChargingOn",
            Tango::DEV_VOID, Tango::DEV_VOID,
            "",
            "",
            Tango::OPERATOR);
    command_list.push_back(pChargingOnCmd);

    //    Command ChargingOff
    ChargingOffClass    *pChargingOffCmd =
        new ChargingOffClass("ChargingOff",
            Tango::DEV_VOID, Tango::DEV_VOID,
            "",
            "",
            Tango::OPERATOR);
    command_list.push_back(pChargingOffCmd);

    //    Command CheckAdcOutput
    CheckAdcOutputClass    *pCheckAdcOutputCmd =
        new CheckAdcOutputClass("CheckAdcOutput",
            Tango::DEV_VOID, Tango::DEV_USHORT,
            "",
            "Voltage on the capacitors",
            Tango::OPERATOR);
    command_list.push_back(pCheckAdcOutputCmd);

    //    Command CheckPSState
    CheckPSStateClass    *pCheckPSStateCmd =
        new CheckPSStateClass("CheckPSState",
            Tango::DEV_VOID, Tango::DEV_VOID,
            "",
            "",
            Tango::OPERATOR);
    command_list.push_back(pCheckPSStateCmd);

    /*----- PROTECTED REGION ID(PowerSupply_701CClass::command_factory_after) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::command_factory_after
}

//===================================================================
//    Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method :         PowerSupply_701CClass::create_static_attribute_list
 * description :     Create the a list of static attributes
 *
 * @param    att_list    the ceated attribute list
 */
//--------------------------------------------------------
void PowerSupply_701CClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
    for (unsigned long i=0 ; i<att_list.size() ; i++)
    {
        string att_name(att_list[i]->get_name());
        transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
        defaultAttList.push_back(att_name);
    }

    cout2 << defaultAttList.size() << " attributes in default list" << endl;

    /*----- PROTECTED REGION ID(PowerSupply_701CClass::create_static_att_list) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method :         PowerSupply_701CClass::erase_dynamic_attributes
 * description :     delete the dynamic attributes if any.
 *
 * @param    devlist_ptr    the device list pointer
 * @param    list of all attributes
 */
//--------------------------------------------------------
void PowerSupply_701CClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
    Tango::Util *tg = Tango::Util::instance();

    for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
    {
        Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
        PowerSupply_701C *dev = static_cast<PowerSupply_701C *> (dev_impl);

        vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
        vector<Tango::Attribute *>::iterator ite_att;
        for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
        {
            string att_name((*ite_att)->get_name_lower());
            if ((att_name == "state") || (att_name == "status"))
                continue;
            vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
            if (ite_str == defaultAttList.end())
            {
                cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
                Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
                dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
                --ite_att;
            }
        }
    }
    /*----- PROTECTED REGION ID(PowerSupply_701CClass::erase_dynamic_attributes) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701CClass::get_attr_by_name()
 *    Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *PowerSupply_701CClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
    vector<Tango::Attr *>::iterator it;
    for (it=att_list.begin() ; it<att_list.end() ; ++it)
        if ((*it)->get_name()==attname)
            return (*it);
    //    Attr does not exist
    return NULL;
}


/*----- PROTECTED REGION ID(PowerSupply_701CClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701CClass::Additional Methods
} //    namespace
