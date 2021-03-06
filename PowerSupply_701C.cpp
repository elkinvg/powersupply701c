/*----- PROTECTED REGION ID(PowerSupply_701C.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        PowerSupply_701C.cpp
//
// description : C++ source for the PowerSupply_701C class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               PowerSupply_701C are implemented in this file.
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


#include <PowerSupply_701C.h>
#include <PowerSupply_701CClass.h>

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C.cpp

/**
 *  PowerSupply_701C class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name    |  Method name
//================================================================
//  State           |  Inherited (no method)
//  Status          |  Inherited (no method)
//  ChargingOn      |  charging_on
//  ChargingOff     |  charging_off
//  CheckAdcOutput  |  check_adc_output
//  CheckPSState    |  check_psstate
//================================================================

//================================================================
//  Attributes managed are:
//================================================================
//  Voltage                  |  Tango::DevUShort    Scalar
//  isExternalControl        |  Tango::DevBoolean    Scalar
//  isActive                 |  Tango::DevBoolean    Scalar
//  isVoltageFromOutComp     |  Tango::DevBoolean    Scalar
//  isVoltageMatchesToGiven  |  Tango::DevBoolean    Scalar
//================================================================

namespace PowerSupply_701C_ns
{
/*----- PROTECTED REGION ID(PowerSupply_701C::namespace_starting) ENABLED START -----*/

//    static initializations

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::namespace_starting

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::PowerSupply_701C()
 *    Description : Constructors for a Tango device
 *                implementing the classPowerSupply_701C
 */
//--------------------------------------------------------
PowerSupply_701C::PowerSupply_701C(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
    /*----- PROTECTED REGION ID(PowerSupply_701C::constructor_1) ENABLED START -----*/
    init_device();

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::constructor_1
}
//--------------------------------------------------------
PowerSupply_701C::PowerSupply_701C(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
    /*----- PROTECTED REGION ID(PowerSupply_701C::constructor_2) ENABLED START -----*/
    init_device();

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::constructor_2
}
//--------------------------------------------------------
PowerSupply_701C::PowerSupply_701C(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
    /*----- PROTECTED REGION ID(PowerSupply_701C::constructor_3) ENABLED START -----*/
    init_device();

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::constructor_3
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::delete_device()
 *    Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void PowerSupply_701C::delete_device()
{
    DEBUG_STREAM << "PowerSupply_701C::delete_device() " << device_name << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::delete_device) ENABLED START -----*/

    //    Delete device allocated objects
    //elkin
    //delete socketProxy; //DELETE
    delete tangoSocket;
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::delete_device
    delete[] attr_Voltage_read;
    delete[] attr_isExternalControl_read;
    delete[] attr_isActive_read;
    delete[] attr_isVoltageFromOutComp_read;
    delete[] attr_isVoltageMatchesToGiven_read;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::init_device()
 *    Description : will be called at device initialization.
 */
//--------------------------------------------------------
void PowerSupply_701C::init_device()
{
    DEBUG_STREAM << "PowerSupply_701C::init_device() create device " << device_name << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::init_device_before) ENABLED START -----*/

    //    Initialization before get_device_property() call

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::init_device_before


    //    Get the device properties from database
    get_device_property();

    attr_Voltage_read = new Tango::DevUShort[1];
    attr_isExternalControl_read = new Tango::DevBoolean[1];
    attr_isActive_read = new Tango::DevBoolean[1];
    attr_isVoltageFromOutComp_read = new Tango::DevBoolean[1];
    attr_isVoltageMatchesToGiven_read = new Tango::DevBoolean[1];
    //    No longer if mandatory property not set.
    if (mandatoryNotDefined)
        return;

    /*----- PROTECTED REGION ID(PowerSupply_701C::init_device) ENABLED START -----*/

    //    Initialize device
#ifndef SUPC11
    initStringCommand();
#endif
    //elkin
    //isExternalControl = false;
    attr_isExternalControl_read[0] = false; // true если включение заряда через спец.разъём
    attr_isActive_read[0] = false;
    //isActive = false;
    attr_isVoltageFromOutComp_read[0] = false;
    //isVoltageFromOutComp = false;
    //isVoltageMatchesToGiven = false;
    attr_isVoltageMatchesToGiven_read[0] = false;

    set_state(Tango::OFF);
    set_status("Device is OFF");
    attr_Voltage_read[0] = 0;
    sleepTime = 300;

    try {

        DEBUG_STREAM << "Socket:    " << socket << endl;

        tangoSocket = new TangoSocket(socket);

        checkSocketState();

        if (isSocketOn)
        {
            check_psstate();
            check_adc_output();
        }

    } catch (Tango::DevFailed &e) {
        DEBUG_STREAM << "Can't connect to socket " << socket << endl;
        Tango::Except::print_exception(e);
        set_state(Tango::FAULT);
        set_status("Can't connect to socket " + socket);
    }

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::init_device
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::get_device_property()
 *    Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void PowerSupply_701C::get_device_property()
{
    /*----- PROTECTED REGION ID(PowerSupply_701C::get_device_property_before) ENABLED START -----*/

    //    Initialize property data members

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::get_device_property_before

    mandatoryNotDefined = false;

    //    Read device properties from database.
    Tango::DbData    dev_prop;
    dev_prop.push_back(Tango::DbDatum("Socket"));

    //    is there at least one property to be read ?
    if (dev_prop.size()>0)
    {
        //    Call database and extract values
        if (Tango::Util::instance()->_UseDb==true)
            get_db_device()->get_property(dev_prop);

        //    get instance on PowerSupply_701CClass to get class property
        Tango::DbDatum    def_prop, cl_prop;
        PowerSupply_701CClass    *ds_class =
            (static_cast<PowerSupply_701CClass *>(get_device_class()));
        int    i = -1;

        //    Try to initialize Socket from class property
        cl_prop = ds_class->get_class_property(dev_prop[++i].name);
        if (cl_prop.is_empty()==false)    cl_prop  >>  socket;
        else {
            //    Try to initialize Socket from default device value
            def_prop = ds_class->get_default_device_property(dev_prop[i].name);
            if (def_prop.is_empty()==false)    def_prop  >>  socket;
        }
        //    And try to extract Socket value from database
        if (dev_prop[i].is_empty()==false)    dev_prop[i]  >>  socket;
        //    Property StartDsPath is mandatory, check if has been defined in database.
        check_mandatory_property(cl_prop, dev_prop[i]);

    }

    /*----- PROTECTED REGION ID(PowerSupply_701C::get_device_property_after) ENABLED START -----*/

    //    Check device property data members init

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::get_device_property_after
}
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::check_mandatory_property()
 *    Description : For mandatory properties check if defined in database.
 */
//--------------------------------------------------------
void PowerSupply_701C::check_mandatory_property(Tango::DbDatum &class_prop, Tango::DbDatum &dev_prop)
{
    //    Check if all properties are empty
    if (class_prop.is_empty() && dev_prop.is_empty())
    {
        TangoSys_OMemStream    tms;
        tms << endl <<"Property \'" << dev_prop.name;
        if (Tango::Util::instance()->_UseDb==true)
            tms << "\' is mandatory but not defined in database";
        else
            tms << "\' is mandatory but cannot be defined without database";
        string    status(get_status());
        status += tms.str();
        set_status(status);
        mandatoryNotDefined = true;
        /*----- PROTECTED REGION ID(PowerSupply_701C::check_mandatory_property) ENABLED START -----*/
        cerr << tms.str() << " for " << device_name << endl;

        /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::check_mandatory_property
    }
}


//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::always_executed_hook()
 *    Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void PowerSupply_701C::always_executed_hook()
{
//    DEBUG_STREAM << "PowerSupply_701C::always_executed_hook()  " << device_name << endl;
    if (mandatoryNotDefined)
    {
        string    status(get_status());
        Tango::Except::throw_exception(
                    (const char *)"PROPERTY_NOT_SET",
                    status.c_str(),
                    (const char *)"PowerSupply_701C::always_executed_hook()");
    }
    /*----- PROTECTED REGION ID(PowerSupply_701C::always_executed_hook) ENABLED START -----*/

    //    code always executed before all requests

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::always_executed_hook
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::read_attr_hardware()
 *    Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void PowerSupply_701C::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
//    DEBUG_STREAM << "PowerSupply_701C::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::read_attr_hardware) ENABLED START -----*/

    //    Add your own code

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::read_attr_hardware
}
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::write_attr_hardware()
 *    Description : Hardware writing for attributes
 */
//--------------------------------------------------------
void PowerSupply_701C::write_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
//    DEBUG_STREAM << "PowerSupply_701C::write_attr_hardware(vector<long> &attr_list) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::write_attr_hardware) ENABLED START -----*/

    //    Add your own code

    //elkin
    checkSocketState();
    if (!isSocketOn) return;

    if(!ifStateIsOnOrMoving()) check_psstate();

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::write_attr_hardware
}

//--------------------------------------------------------
/**
 *    Read attribute Voltage related method
 *    Description:
 *
 *    Data type:    Tango::DevUShort
 *    Attr type:    Scalar
 */
//--------------------------------------------------------
void PowerSupply_701C::read_Voltage(Tango::Attribute &attr)
{
//    DEBUG_STREAM << "PowerSupply_701C::read_Voltage(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::read_Voltage) ENABLED START -----*/
    //    Set the attribute value
    attr.set_value(attr_Voltage_read);

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::read_Voltage
}
//--------------------------------------------------------
/**
 *    Write attribute Voltage related method
 *    Description:
 *
 *    Data type:    Tango::DevUShort
 *    Attr type:    Scalar
 */
//--------------------------------------------------------
void PowerSupply_701C::write_Voltage(Tango::WAttribute &attr)
{
//    DEBUG_STREAM << "PowerSupply_701C::write_Voltage(Tango::WAttribute &attr) entering... " << endl;
    //    Retrieve write value
    Tango::DevUShort    w_val;
    attr.get_write_value(w_val);
    /*----- PROTECTED REGION ID(PowerSupply_701C::write_Voltage) ENABLED START -----*/

    // from setvoltage
    if (!isSocketOn) return;

    // timeout??? for device

    // if isActive || isExternalControl || isVoltageFromOutComp is false ???
    DEBUG_STREAM << "WRITE VOLTAGE isExternalControl:" << attr_isExternalControl_read[0] << endl;
    DEBUG_STREAM << "WRITE VOLTAGE isVoltageFromOutComp:" << attr_isVoltageFromOutComp_read[0] << endl;

        string reply,commandToPS,checkSumChr;

        //convert little-endian to big-endian
        Tango::DevUShort writeVal = w_val;
        char* instVolt = reinterpret_cast<char*>(&writeVal);
        //char tmp; tmp = instVolt[0];instVolt[0]= instVolt[1];instVolt[1]=tmp;

        commandToPS = '#';
        commandToPS.push_back(4);
        commandToPS += 'U';
        //commandToPS += writeVal; // big-endian ???
        commandToPS.push_back(instVolt[1]);
        commandToPS.push_back(instVolt[0]);

        checkSumChr = calcCheckSum(commandToPS);
        commandToPS += checkSumChr;

        DEBUG_STREAM << "WRITE VOLTAGE" << endl;

        reply = tangoSocket->toSocketWriteAndReadBinary(commandToPS);

        DEBUG_STREAM << "WRITE VOLTAGE reply:" << reply << endl;

        if (reply==OK) {
            attr_Voltage_write = w_val;
            INFO_STREAM << " It sets new voltage: " << w_val << "V" << endl;
        } // ??? if reply!=OK
#ifdef __unix__
        usleep(sleepTime);
#else
        Sleep(sleepTime); // for serialport
#endif
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::write_Voltage
}
//--------------------------------------------------------
/**
 *    Read attribute isExternalControl related method
 *    Description:
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
//--------------------------------------------------------
void PowerSupply_701C::read_isExternalControl(Tango::Attribute &attr)
{
//    DEBUG_STREAM << "PowerSupply_701C::read_isExternalControl(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::read_isExternalControl) ENABLED START -----*/
    //    Set the attribute value
    attr.set_value(attr_isExternalControl_read);

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::read_isExternalControl
}
//--------------------------------------------------------
/**
 *    Read attribute isActive related method
 *    Description:
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
//--------------------------------------------------------
void PowerSupply_701C::read_isActive(Tango::Attribute &attr)
{
//    DEBUG_STREAM << "PowerSupply_701C::read_isActive(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::read_isActive) ENABLED START -----*/
    //    Set the attribute value
    attr.set_value(attr_isActive_read);

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::read_isActive
}
//--------------------------------------------------------
/**
 *    Read attribute isVoltageFromOutComp related method
 *    Description:
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
//--------------------------------------------------------
void PowerSupply_701C::read_isVoltageFromOutComp(Tango::Attribute &attr)
{
//    DEBUG_STREAM << "PowerSupply_701C::read_isVoltageFromOutComp(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::read_isVoltageFromOutComp) ENABLED START -----*/
    //    Set the attribute value
    attr.set_value(attr_isVoltageFromOutComp_read);

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::read_isVoltageFromOutComp
}
//--------------------------------------------------------
/**
 *    Read attribute isVoltageMatchesToGiven related method
 *    Description:
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
//--------------------------------------------------------
void PowerSupply_701C::read_isVoltageMatchesToGiven(Tango::Attribute &attr)
{
//    DEBUG_STREAM << "PowerSupply_701C::read_isVoltageMatchesToGiven(Tango::Attribute &attr) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::read_isVoltageMatchesToGiven) ENABLED START -----*/
    //    Set the attribute value
    attr.set_value(attr_isVoltageMatchesToGiven_read);

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::read_isVoltageMatchesToGiven
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::add_dynamic_attributes()
 *    Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void PowerSupply_701C::add_dynamic_attributes()
{
    /*----- PROTECTED REGION ID(PowerSupply_701C::add_dynamic_attributes) ENABLED START -----*/

    //    Add your own code to create and add dynamic attributes if any

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *    Read pipe PipeAttr related method
 *    Description:
 */
//--------------------------------------------------------
void PowerSupply_701C::read_PipeAttr(Tango::Pipe &pipe)
{
    DEBUG_STREAM << "PowerSupply_701C::read_PipeAttr(Tango::Pipe &pipe) entering... " << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::read_PipeAttr) ENABLED START -----*/

    //    Add your own code here
    pipe.set_root_blob_name("psData");
    vector<string> names{
        "Voltage",
        "isExternalControl",
        "isActive",
        "isVoltageFromOutComp",
        "isVoltageMatchesToGiven",
        "State",
        "Status"
    };
    pipe.set_data_elt_names(names);

    pipe << attr_Voltage_read[0] << attr_isExternalControl_read[0] <<
            attr_isActive_read[0] << attr_isVoltageFromOutComp_read[0] << attr_isVoltageMatchesToGiven_read[0] << get_state() << get_status();

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::read_PipeAttr
}
//--------------------------------------------------------
/**
 *    Command ChargingOn related method
 *    Description: Switch on power supply
 *
 */
//--------------------------------------------------------
void PowerSupply_701C::charging_on()
{
    DEBUG_STREAM << "PowerSupply_701C::ChargingOn()  - " << device_name << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::charging_on) ENABLED START -----*/
    check_psstate();

    chargingOnOrOff(CHARGINGONCOMM);

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::charging_on
}
//--------------------------------------------------------
/**
 *    Command ChargingOff related method
 *    Description: Switch off power supply
 *
 */
//--------------------------------------------------------
void PowerSupply_701C::charging_off()
{
    DEBUG_STREAM << "PowerSupply_701C::ChargingOff()  - " << device_name << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::charging_off) ENABLED START -----*/

    //    Add your own code
    check_psstate();

    chargingOnOrOff(CHARGINGOFFCOMM);

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::charging_off
}
//--------------------------------------------------------
/**
 *    Command CheckAdcOutput related method
 *    Description: Checking ADC output.
 *
 *    @returns Voltage on the capacitors
 */
//--------------------------------------------------------
Tango::DevUShort PowerSupply_701C::check_adc_output()
{
    Tango::DevUShort argout;
    DEBUG_STREAM << "PowerSupply_701C::CheckAdcOutput()  - " << device_name << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::check_adc_output) ENABLED START -----*/

    //    Add your own code

    if(!ifStateIsOnOrMoving()) check_psstate();

    // timeout??? for device

    try { // if isActive || isExternalControl || isVoltageFromOutComp is false ???
            string reply = tangoSocket->toSocketWriteAndReadBinary(OUTPUTADC);

            if (reply.size()<2) {
                DEBUG_STREAM << "Reply is incorrect " << endl;
                set_state(Tango::FAULT);
                set_status("Reply is incorrect. reply.size<2");
                return 65535;
            }

            //string stateStr = {reply[0],reply[1]};
            string stateStr;
            stateStr.push_back(reply[0]); stateStr.push_back(reply[1]);
            string replyVoltage;

            if (stateStr==OK)
            {
                Tango::DevUShort outVoltage;
                char checkSum;
                std::copy(reply.begin()+2,reply.end(),std::back_inserter(replyVoltage));

                if (replyVoltage.size()<6) {
                    DEBUG_STREAM << "Reply is incorrect " << endl;
                    set_state(Tango::FAULT);
                    set_status("Reply is incorrect. (replyVoltage)");
                    return 65535;
                }
                if (replyVoltage[0]='!')
                {
                    checkSum = calcCheckSum(replyVoltage.substr(0,5));
                    if (checkSum != replyVoltage[5])
                    {
                        DEBUG_STREAM << "Checksum of reply is incorrect " << endl;
                        set_state(Tango::FAULT);
                        set_status("Checksum is incorrect");
                        return 65535;
                    }

                    // ??? big-endian ?
                    char* instVolt = reinterpret_cast<char*>(&outVoltage);
                    instVolt[0]=replyVoltage[4]; // ???
                    instVolt[1]=replyVoltage[3]; // ???
                    DEBUG_STREAM << "Reply Voltage:" << outVoltage << endl;
                    argout = outVoltage;
                    attr_Voltage_read[0] = outVoltage; // ???
                }
            }
            else if (reply[0]=='E')
            {
                // process
                errorReply(stateStr);
                return 65535;
            }
//        }
    }  catch (Tango::DevFailed &e) {
        DEBUG_STREAM << "checkPSState() - ConnectionFailed " << endl;
        Tango::Except::print_exception(e);
        set_state(Tango::FAULT);
        set_status("Can't connect to socket " + socket);
        return 65535;
    }
#ifdef __unix__
    usleep(sleepTime);
#else
    Sleep(sleepTime); // for serialport
#endif

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::check_adc_output
    return argout;
}
//--------------------------------------------------------
/**
 *    Command CheckPSState related method
 *    Description: Check the state of the power supply
 *
 */
//--------------------------------------------------------
void PowerSupply_701C::check_psstate()
{
    DEBUG_STREAM << "PowerSupply_701C::CheckPSState()  - " << device_name << endl;
    /*----- PROTECTED REGION ID(PowerSupply_701C::check_psstate) ENABLED START -----*/

    try
    {
//        DEBUG_STREAM << "checkPSState()" <<  endl;
//        socketProxy->ping();

        string reply,replyStatus;

        reply = tangoSocket->toSocketWriteAndReadBinary(CHECKPSSTATE);

        if (reply.size()<2) {
            DEBUG_STREAM << "Reply is incorrect. " << endl;
            set_state(Tango::FAULT);
            set_status("Reply is incorrect. reply.size<2");
            return;
        }

        DEBUG_STREAM << "checkPSState_Reply:" << reply << endl;
        char errorbyte,statebyte;

#ifdef TESTING
        DEBUG_STREAM << "Request size: " << reply.size() << endl;
#endif

        //string stateStr = {reply[0],reply[1]};
        string stateStr;
        stateStr.push_back(reply[0]); stateStr.push_back(reply[1]);

        if (stateStr==OK)
        {
            char checkSum;
            std::copy(reply.begin()+2,reply.end(),std::back_inserter(replyStatus));

            if (replyStatus.size()<6) {
                DEBUG_STREAM << "Reply is incorrect " << endl;
                set_state(Tango::FAULT);
                set_status("Reply is incorrect. (replyVoltage)");
                return;
            }
            if (replyStatus[0]='!')
            {
                checkSum = calcCheckSum(replyStatus.substr(0,5));
                if (checkSum != replyStatus[5])
                {
                    DEBUG_STREAM << "Checksum of reply is incorrect " << endl;
                    set_state(Tango::FAULT);
                    set_status("Checksum is incorrect");
                    return;
                }

                statebyte = replyStatus[3];
                errorbyte = replyStatus[4];
                // ??? check statebyte & errorbyte
                checkStateByte(statebyte);
                checkErrorByte(errorbyte);
            }
        }
        else if (reply[0]=='E')
        {
            // process
            errorReply(stateStr);
        }

#ifdef __unix__
        usleep(sleepTime);
#else
        Sleep(sleepTime); // for serialport
#endif

    }
    catch (Tango::DevFailed &e)
    {
        DEBUG_STREAM << "checkPSState() - ConnectionFailed " << endl;
        Tango::Except::print_exception(e);
        set_state(Tango::FAULT);
        set_status("Can't connect to socket " + socket);
    }

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::check_psstate
}
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::add_dynamic_commands()
 *    Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void PowerSupply_701C::add_dynamic_commands()
{
    /*----- PROTECTED REGION ID(PowerSupply_701C::add_dynamic_commands) ENABLED START -----*/

    //    Add your own code to create and add dynamic commands if any

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::add_dynamic_commands
}

/*----- PROTECTED REGION ID(PowerSupply_701C::namespace_ending) ENABLED START -----*/

//    Additional Methods

char PowerSupply_701C::calcCheckSum(string bytes)
{
    //short size = bytes.size();
//    char sum{0};
//    for (auto& i: bytes) sum += i;
    char sum = 0;
    for (unsigned short i=0;i<bytes.size();i++)
    {
        sum+=bytes[i];
    }
    return sum;
}

Tango::DevState PowerSupply_701C::dev_state()
{
//    DEBUG_STREAM << "CHECK STATE" << endl;
//    checkPSState();
    return Tango::DeviceImpl::dev_state();
}

void PowerSupply_701C::errorReply(string ERROR)
{
    if (ERROR==ERR0) {
        set_state(Tango::FAULT);
        set_status("Checksum error (Input command) ");
        return;
    }
    if (ERROR==ERR1) {
        set_state(Tango::FAULT);
        set_status("Format error. Broken command structure (Input command) ");
        return;
    }
    if (ERROR==ERR2) {
        set_state(Tango::FAULT);
        set_status("Unknown command (Input command) ");
        return;
    }
    if (ERROR==ERR3) {
        set_state(Tango::FAULT);
        //set_status("Exceeding the allowable value for voltage (max=500V) (Input command) ");
        set_status("Exceeding the allowable value for voltage (Input command) ");
        return;
    }
    if (ERROR==ERR4) {
        set_state(Tango::FAULT);
        set_status("Command can not be executed ");
    }
}

void PowerSupply_701C::checkSocketState()
{
    isSocketOn = tangoSocket->checkSocketState();

    if (!isSocketOn)
    {
        set_state(Tango::OFF);
        set_status("Device is OFF or Socket is FAULT");
    }

}

void PowerSupply_701C::checkErrorByte(char byte)
{
    // ??? check errorbyte
    DEBUG_STREAM << "ERRORBYTE: " <<(short int)byte << endl;
    if ((1) & byte)
    {
        set_state(Tango::FAULT);
        set_status("Overheat of powersupply ");
        FATAL_STREAM << "Overheat of powersupply on " << device_name << endl;
        // перегрев источника питания
    }
    if ((1 << 1) & byte)
    {
        set_state(Tango::FAULT);
        set_status("Voltage of powersupply below normal. Problem with power source ");
        FATAL_STREAM << "Voltage of powersupply below normal. Problem with power source on " << device_name << endl;
        // Напряжение питания ниже нормы (проблемы с трехфазным сетевым питанием)
    }
    if ((1 << 2) & byte)
    {
        set_state(Tango::FAULT);
        set_status("short circuit");
        FATAL_STREAM << "Short circuit on " << device_name << endl;
        // короткое замыкание
    }
    if ((1 << 3) & byte)
    {
        set_state(Tango::FAULT);
        set_status("break of power");
        FATAL_STREAM << "break of power on " << device_name << endl;
        // обрыв нагрузки
    }
    if ((1 << 6) & byte)
    {
        set_state(Tango::FAULT);
        set_status("No lock on the connector INTERLOCK");
        // нет блокировки по разъему INTERLOCK
    }
}

void PowerSupply_701C::checkStateByte(char byte)
{
    DEBUG_STREAM << "STATEBYTE: " <<(short int)byte << endl;
    //isExternalControl = (1) & byte;
    attr_isExternalControl_read[0] = (1) & byte;
    attr_isActive_read[0] = (1 << 1) & byte;
    attr_isVoltageMatchesToGiven_read[0] =  (1 << 3) & byte;
    attr_isVoltageFromOutComp_read[0] = (1 << 6) & byte;

#ifdef TESTING
    if(attr_isExternalControl_read[0])
        DEBUG_STREAM << "ISEXTERNAL";
    if(attr_isActive_read[0])
        DEBUG_STREAM << "ISACTIVE";
    if(attr_isVoltageMatchesToGiven_read[0])
        DEBUG_STREAM << "ISMATCH";
    if(attr_isVoltageFromOutComp_read[0])
        DEBUG_STREAM << "ISVOLT";
    DEBUG_STREAM <<endl;
#endif

    if (!attr_isExternalControl_read[0]) {
        if (attr_isActive_read[0]) {
            if (attr_isVoltageMatchesToGiven_read[0]) { // ??? должен выключить режим зарядки
                set_state(Tango::RUNNING);
                set_status("Charging capacitor. Voltage matches to given");
            }
            else {
                set_state(Tango::RUNNING);
                set_status("Charging capacitor");
            }
        }
        else {
            set_state(Tango::ON);
            set_status("Device is ON");
        }
    }
    else
    {
        set_state(Tango::DISABLE);
        set_status("ExternalControl is active");
        return; // ??? throw? FAULT or OFF
    }
}

bool PowerSupply_701C::ifStateIsOnOrMoving()
{
    Tango::DevState Stt = get_state();
    return (Stt == Tango::ON || Stt == Tango::RUNNING) ? true : false;
}

void PowerSupply_701C::chargingOnOrOff(string command)
{
    try { // if isActive || isExternalControl is false ???
        //if (isActive && isExternalControl)
        if (!attr_isExternalControl_read[0]) // attr_isExternalControl_read true если включение заряда через спец.разъём
        {
            string reply;
            reply = tangoSocket->toSocketWriteAndReadBinary(command);
            if (reply==OK) {
                if (command==CHARGINGOFFCOMM) {
                    INFO_STREAM << " Charging OFF " << device_name << endl;
                    set_state(Tango::ON);
                    set_status("Device is ON");
                    attr_isActive_read[0] = false;
                }
                if (command==CHARGINGONCOMM) {
                    INFO_STREAM << " Charging ON " << device_name << endl;
                    set_state(Tango::RUNNING);
                    set_status("Charging capacitor");
                    attr_isActive_read[0] = true;
                }

            }
            else if (reply[0]=='E')
            {
                if (reply.size()==2) errorReply(reply);
                if (reply.size()>2) errorReply(reply.substr(0,2));
                if (reply.size()<2) {
                    set_state(Tango::FAULT);
                    set_status("Incorrect reply of Device");
                }
            }
#ifdef __unix__
            usleep(sleepTime);
#else
            Sleep(sleepTime); // for serialport
#endif
        }
    } catch (Tango::DevFailed &e) {
        Tango::Except::print_exception(e);
        set_state(Tango::FAULT);
        set_status("Can't connect to socket " + socket);
    }
}
#ifndef SUPC11
void PowerSupply_701C::initStringCommand()
{
    string dot2;
    dot2.push_back('#');dot2.push_back(2);

    CHARGINGONCOMM.clear();
    CHARGINGONCOMM = CHARGINGONCOMM + dot2;
    CHARGINGONCOMM.push_back('C');
    CHARGINGONCOMM.push_back(calcCheckSumCommand(CHARGINGONCOMM));

    CHARGINGOFFCOMM.clear();
    CHARGINGOFFCOMM = CHARGINGOFFCOMM + dot2;
    CHARGINGOFFCOMM.push_back('D');
    CHARGINGOFFCOMM.push_back(calcCheckSumCommand(CHARGINGOFFCOMM));

    CHECKPSSTATE.clear();
    CHECKPSSTATE = CHECKPSSTATE + dot2;
    CHECKPSSTATE.push_back('E');
    CHECKPSSTATE.push_back(calcCheckSumCommand(CHECKPSSTATE));

    OUTPUTADC.clear();
    OUTPUTADC = OUTPUTADC + dot2;
    OUTPUTADC.push_back('A');
    OUTPUTADC.push_back(calcCheckSumCommand(OUTPUTADC));

    OK = "OK";
    ERR0 = "E0";
    ERR1 = "E1";
    ERR2 = "E2";
    ERR3 = "E3";
    ERR4 = "E4";
}
#endif


/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::namespace_ending
} //    namespace
