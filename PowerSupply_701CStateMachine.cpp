/*----- PROTECTED REGION ID(PowerSupply_701CStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        PowerSupply_701CStateMachine.cpp
//
// description : State machine file for the PowerSupply_701C class
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

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::PowerSupply_701CStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  ON       |  
//  OFF      |  
//  FAULT    |  
//  DISABLE  |  
//  RUNNING  |  charging capacitor


namespace PowerSupply_701C_ns
{
//=================================================
//        Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_Voltage_allowed()
 *    Description : Execution allowed for Voltage attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_Voltage_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
    //    Not any excluded states for Voltage attribute in Write access.
    /*----- PROTECTED REGION ID(PowerSupply_701C::VoltageStateAllowed_WRITE) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::VoltageStateAllowed_WRITE

    //    Not any excluded states for Voltage attribute in read access.
    /*----- PROTECTED REGION ID(PowerSupply_701C::VoltageStateAllowed_READ) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::VoltageStateAllowed_READ
    return true;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_isExternalControl_allowed()
 *    Description : Execution allowed for isExternalControl attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_isExternalControl_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

    //    Not any excluded states for isExternalControl attribute in read access.
    /*----- PROTECTED REGION ID(PowerSupply_701C::isExternalControlStateAllowed_READ) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::isExternalControlStateAllowed_READ
    return true;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_isActive_allowed()
 *    Description : Execution allowed for isActive attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_isActive_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

    //    Not any excluded states for isActive attribute in read access.
    /*----- PROTECTED REGION ID(PowerSupply_701C::isActiveStateAllowed_READ) ENABLED START -----*/
    
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::isActiveStateAllowed_READ
    return true;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_isVoltageFromOutComp_allowed()
 *    Description : Execution allowed for isVoltageFromOutComp attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_isVoltageFromOutComp_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

    //    Not any excluded states for isVoltageFromOutComp attribute in read access.
    /*----- PROTECTED REGION ID(PowerSupply_701C::isVoltageFromOutCompStateAllowed_READ) ENABLED START -----*/
    
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::isVoltageFromOutCompStateAllowed_READ
    return true;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_isVoltageMatchesToGiven_allowed()
 *    Description : Execution allowed for isVoltageMatchesToGiven attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_isVoltageMatchesToGiven_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

    //    Not any excluded states for isVoltageMatchesToGiven attribute in read access.
    /*----- PROTECTED REGION ID(PowerSupply_701C::isVoltageMatchesToGivenStateAllowed_READ) ENABLED START -----*/
    
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::isVoltageMatchesToGivenStateAllowed_READ
    return true;
}

//=================================================
//        pipe Allowed Methods
//=================================================
//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_PipeAttr_allowed()
 *    Description : Execution allowed for PipeAttr pipe
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_PipeAttr_allowed(TANGO_UNUSED(Tango::PipeReqType type))
{
    //    Not any excluded states for PipeAttr pipe in read access.
    /*----- PROTECTED REGION ID(PowerSupply_701C::PipeAttrStateAllowed_READ) ENABLED START -----*/

    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::PipeAttrStateAllowed_READ
    return true;
}

//=================================================
//        Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_ChargingOn_allowed()
 *    Description : Execution allowed for ChargingOn attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_ChargingOn_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
    //    Not any excluded states for ChargingOn command.
    /*----- PROTECTED REGION ID(PowerSupply_701C::ChargingOnStateAllowed) ENABLED START -----*/
    checkSocketState();
    if (!isSocketOn)  return false;
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::ChargingOnStateAllowed
    return true;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_ChargingOff_allowed()
 *    Description : Execution allowed for ChargingOff attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_ChargingOff_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
    //    Not any excluded states for ChargingOff command.
    /*----- PROTECTED REGION ID(PowerSupply_701C::ChargingOffStateAllowed) ENABLED START -----*/
    checkSocketState();
    if (!isSocketOn)  return false;
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::ChargingOffStateAllowed
    return true;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_CheckAdcOutput_allowed()
 *    Description : Execution allowed for CheckAdcOutput attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_CheckAdcOutput_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
    //    Not any excluded states for CheckAdcOutput command.
    /*----- PROTECTED REGION ID(PowerSupply_701C::CheckAdcOutputStateAllowed) ENABLED START -----*/
    checkSocketState();
    if (!isSocketOn)  return false;
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::CheckAdcOutputStateAllowed
    return true;
}

//--------------------------------------------------------
/**
 *    Method      : PowerSupply_701C::is_CheckPSState_allowed()
 *    Description : Execution allowed for CheckPSState attribute
 */
//--------------------------------------------------------
bool PowerSupply_701C::is_CheckPSState_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
    //    Not any excluded states for CheckPSState command.
    /*----- PROTECTED REGION ID(PowerSupply_701C::CheckPSStateStateAllowed) ENABLED START -----*/
    checkSocketState();
    if (!isSocketOn)  return false;
    /*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::CheckPSStateStateAllowed
    return true;
}


/*----- PROTECTED REGION ID(PowerSupply_701C::PowerSupply_701CStateAllowed.AdditionalMethods) ENABLED START -----*/

//    Additional Methods

/*----- PROTECTED REGION END -----*/    //    PowerSupply_701C::PowerSupply_701CStateAllowed.AdditionalMethods

}    //    End of namespace
