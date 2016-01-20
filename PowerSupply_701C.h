/*----- PROTECTED REGION ID(PowerSupply_701C.h) ENABLED START -----*/
//=============================================================================
//
// file :        PowerSupply_701C.h
//
// description : Include file for the PowerSupply_701C class
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


#ifndef PowerSupply_701C_H
#define PowerSupply_701C_H

#include <tango.h>
#include "tangosocket.h"

#if _MSC_VER > 1700
#define SUPC11
#else
#if __GNUC__ > 3
#if __GNUC_MINOR__ > 6
#define SUPC11
#endif
#endif
#endif

#define TESTING

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C.h

/**
 *  PowerSupply_701C class description:
 *    
 */

namespace PowerSupply_701C_ns
{
/*----- PROTECTED REGION ID(PowerSupply_701C::Additional Class Declarations) ENABLED START -----*/

//    Additional Class Declarations


/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::Additional Class Declarations

class PowerSupply_701C : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(PowerSupply_701C::Data Members) ENABLED START -----*/

//    Add your own data members
public:
    Tango::DevShort attr_Voltage_write;

private:

    // elkin
    TangoSocket *tangoSocket;
    // state bytes
    //bool isExternalControl;
    bool isActive; // if charging on
    bool isVoltageMatchesToGiven;
    bool isVoltageFromOutComp;

    // state Socket
    bool isSocketOn;
	
	unsigned short sleepTime; // in millisecond

    // errors bytes
//    enum class ErrorByte {Overtheat,VoltageBelowNorm,ShortCircuit,BreakLoad};
//    bool isOvertheat;
//    bool isVoltageFromOutComp;
//    bool isVoltage

#ifdef SUPC11
    // const commands
    const string CHARGINGONCOMM = {'#',2,'C',calcCheckSumCommand('#',2,'C')};
    const string CHARGINGOFFCOMM = {'#',2,'D',calcCheckSumCommand('#',2,'D')};
    const string CHECKPSSTATE = {'#',2,'E',calcCheckSumCommand('#',2,'E')};
    const string OUTPUTADC = {'#',2,'A',calcCheckSumCommand('#',2,'A')};
    // const answers
    const string OK = "OK";     // is OK
    const string ERR0 = "E0";   // checksum error
    const string ERR1 = "E1";   // format error. broken command structure
    const string ERR2 = "E2";   // unknown command
    const string ERR3 = "E3";   // exceeding the allowable value for U (500V)
    const string ERR4 = "E4";   // command can not be executed
#else
    // commands
    string CHARGINGONCOMM;
    string CHARGINGOFFCOMM;
    string CHECKPSSTATE;
    string OUTPUTADC;
    // answers
    string OK;     // is OK
    string ERR0;   // checksum error
    string ERR1;   // format error. broken command structure
    string ERR2;   // unknown command
    string ERR3;   // exceeding the allowable value for U (500V)
    string ERR4;   // command can not be executed
#endif

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::Data Members

//    Device property data members
public:
    //    Socket:    Tango device name in format ``domain/family/member``
    string    socket;

    bool    mandatoryNotDefined;

//    Attribute data members
public:
    Tango::DevUShort    *attr_Voltage_read;
    Tango::DevBoolean    *attr_isExternalControl_read;
    Tango::DevBoolean    *attr_isActive_read;
    Tango::DevBoolean    *attr_isVoltageFromOutComp_read;
    Tango::DevBoolean    *attr_isVoltageMatchesToGiven_read;

//    Constructors and destructors
public:
    /**
     * Constructs a newly device object.
     *
     *    @param cl    Class.
     *    @param s     Device Name
     */
    PowerSupply_701C(Tango::DeviceClass *cl,string &s);
    /**
     * Constructs a newly device object.
     *
     *    @param cl    Class.
     *    @param s     Device Name
     */
    PowerSupply_701C(Tango::DeviceClass *cl,const char *s);
    /**
     * Constructs a newly device object.
     *
     *    @param cl    Class.
     *    @param s     Device name
     *    @param d    Device description.
     */
    PowerSupply_701C(Tango::DeviceClass *cl,const char *s,const char *d);
    /**
     * The device object destructor.
     */
    ~PowerSupply_701C() {delete_device();};


//    Miscellaneous methods
public:
    /*
     *    will be called at device destruction or at init command.
     */
    void delete_device();
    /*
     *    Initialize the device
     */
    virtual void init_device();
    /*
     *    Read the device properties from database
     */
    void get_device_property();
    /*
     *    Always executed method before execution command method.
     */
    virtual void always_executed_hook();

    /*
     *    Check if mandatory property has been set
     */
     void check_mandatory_property(Tango::DbDatum &class_prop, Tango::DbDatum &dev_prop);

//    Attribute methods
public:
    //--------------------------------------------------------
    /*
     *    Method      : PowerSupply_701C::read_attr_hardware()
     *    Description : Hardware acquisition for attributes.
     */
    //--------------------------------------------------------
    virtual void read_attr_hardware(vector<long> &attr_list);
    //--------------------------------------------------------
    /*
     *    Method      : PowerSupply_701C::write_attr_hardware()
     *    Description : Hardware writing for attributes.
     */
    //--------------------------------------------------------
    virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *    Attribute Voltage related methods
 *    Description: 
 *
 *    Data type:    Tango::DevUShort
 *    Attr type:    Scalar
 */
    virtual void read_Voltage(Tango::Attribute &attr);
    virtual void write_Voltage(Tango::WAttribute &attr);
    virtual bool is_Voltage_allowed(Tango::AttReqType type);
/**
 *    Attribute isExternalControl related methods
 *    Description: 
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
    virtual void read_isExternalControl(Tango::Attribute &attr);
    virtual bool is_isExternalControl_allowed(Tango::AttReqType type);
/**
 *    Attribute isActive related methods
 *    Description: 
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
    virtual void read_isActive(Tango::Attribute &attr);
    virtual bool is_isActive_allowed(Tango::AttReqType type);
/**
 *    Attribute isVoltageFromOutComp related methods
 *    Description: 
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
    virtual void read_isVoltageFromOutComp(Tango::Attribute &attr);
    virtual bool is_isVoltageFromOutComp_allowed(Tango::AttReqType type);
/**
 *    Attribute isVoltageMatchesToGiven related methods
 *    Description: 
 *
 *    Data type:    Tango::DevBoolean
 *    Attr type:    Scalar
 */
    virtual void read_isVoltageMatchesToGiven(Tango::Attribute &attr);
    virtual bool is_isVoltageMatchesToGiven_allowed(Tango::AttReqType type);


    //--------------------------------------------------------
    /**
     *    Method      : PowerSupply_701C::add_dynamic_attributes()
     *    Description : Add dynamic attributes if any.
     */
    //--------------------------------------------------------
    void add_dynamic_attributes();




//    Command related methods
public:
    /**
     *    Command ChargingOn related method
     *    Description: Switch on power supply
     *
     */
    virtual void charging_on();
    virtual bool is_ChargingOn_allowed(const CORBA::Any &any);
    /**
     *    Command ChargingOff related method
     *    Description: Switch off power supply
     *
     */
    virtual void charging_off();
    virtual bool is_ChargingOff_allowed(const CORBA::Any &any);
    /**
     *    Command CheckAdcOutput related method
     *    Description: Checking ADC output.
     *
     *    @returns Voltage on the capacitors
     */
    virtual Tango::DevUShort check_adc_output();
    virtual bool is_CheckAdcOutput_allowed(const CORBA::Any &any);
    /**
     *    Command CheckPSState related method
     *    Description: Check the state of the power supply
     *
     */
    virtual void check_psstate();
    virtual bool is_CheckPSState_allowed(const CORBA::Any &any);


    //--------------------------------------------------------
    /**
     *    Method      : PowerSupply_701C::add_dynamic_commands()
     *    Description : Add dynamic commands if any.
     */
    //--------------------------------------------------------
    void add_dynamic_commands();

/*----- PROTECTED REGION ID(PowerSupply_701C::Additional Method prototypes) ENABLED START -----*/

//    Additional Method prototypes
    //elkin
private:
    Tango::DevState dev_state();

    char calcCheckSum(string bytes);
//    void checkPSState();
    void errorReply(string ERROR);

    void checkSocketState();
    void checkErrorByte(char byte);
    void checkStateByte(char byte);

//    string toSocketWriteAndReadBinary(string command); // send command to socket
    void chargingOnOrOff(string command);
    bool ifStateIsOnOrMoving();
#ifdef SUPC11
    static constexpr char calcCheckSumCommand(char a, unsigned  char b, char c) {return a+b+c;}
#else
    void initStringCommand();
    static char calcCheckSumCommand(string command) {return command[0]+command[1]+command[2];}
#endif
//protected:
    Tango::DevShort voltage;
    Tango::DevShort prevVoltage; // ???????

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::Additional Method prototypes
};

/*----- PROTECTED REGION ID(PowerSupply_701C::Additional Classes Definitions) ENABLED START -----*/

//    Additional Classes Definitions

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::Additional Classes Definitions

}    //    End of namespace

#endif   //    PowerSupply_701C_H
