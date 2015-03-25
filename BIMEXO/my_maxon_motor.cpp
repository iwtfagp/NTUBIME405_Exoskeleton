#include "my_maxon_motor.h"
#include <iomanip>
#include <iostream>
#include <QDebug>


my_maxon_motor::my_maxon_motor()
{
    keyHandle = 0;
}
bool my_maxon_motor::openDevice(QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;
    closeALLDevice();
    keyHandle = VCS_OpenDevice("EPOS2","MAXON SERIAL V2","USB","USB0",&ErrorCode);
    if( keyHandle == 0 )
    {
        *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
        //        qDebug()<<*str_ErrorCode;
        return FALSE;
    }
    return OK;
}
bool my_maxon_motor::closeALLDevice()
{
    DWORD ErrorCode = 0;
    if(VCS_CloseAllDevices(&ErrorCode))
    {
        return NO;
    }
    return OK;
}


void my_maxon_motor::setEnabled(QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;

    BOOL IsInFault = FALSE;

    if( VCS_GetFaultState(keyHandle, this->node_Id, &IsInFault, &ErrorCode) )
    {
        if( IsInFault && !VCS_ClearFault(keyHandle, this->node_Id, &ErrorCode) )
        {
            *str_ErrorCode = QString::number(this->node_Id) + QString(" : Clear fault failed!, error code=0x%1").arg(ErrorCode,0,16);

            return;
        }

        BOOL IsEnabled = FALSE;
        if( VCS_GetEnableState(keyHandle, this->node_Id, &IsEnabled, &ErrorCode) )
        {
            if( !IsEnabled && !VCS_SetEnableState(keyHandle, this->node_Id, &ErrorCode) )
            {
                *str_ErrorCode = QString::number(this->node_Id) + QString(" : Set enable state failed!, error code=0x%1").arg(ErrorCode,0,16);
            }
            else
            {
                *str_ErrorCode = QString::number(this->node_Id) + " : enable OK";
            }
        }
    }
    else
    {
        *str_ErrorCode = QString::number(this->node_Id) + QString(" : Get fault state failed!, error code=0x%1").arg(ErrorCode,0,16);
    }
}

void my_maxon_motor::setDisabled(QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;
    BOOL IsInFault = FALSE;

    if( VCS_GetFaultState(keyHandle, this->node_Id, &IsInFault, &ErrorCode) )
    {
        if( IsInFault && !VCS_ClearFault(keyHandle, this->node_Id, &ErrorCode) )
        {
            *str_ErrorCode = QString::number(this->node_Id) + QString(" : Clear fault failed!, error code=0x%1").arg(ErrorCode,0,16);
            return;
        }

        BOOL IsEnabled = FALSE;
        if( VCS_GetEnableState(keyHandle, this->node_Id, &IsEnabled, &ErrorCode) )
        {
            if( IsEnabled && !VCS_SetDisableState(keyHandle, this->node_Id, &ErrorCode) )
            {
                *str_ErrorCode = QString::number(this->node_Id) + QString(" : Set enable state failed!, error code=0x%1").arg(ErrorCode,0,16);
            }
            else
            {
                *str_ErrorCode = QString::number(this->node_Id) + " : DDDDDDDDDDDisable OK";
            }
        }
    }
    else
    {
        *str_ErrorCode = QString::number(this->node_Id) + QString(" : Get fault state failed!, error code=0x%1").arg(ErrorCode,0,16);
    }

}
bool my_maxon_motor::init(int nodeId, double MaxProfileVelocity, double MaxFollowingError, double MaxAcceleration)
{
    DWORD ErrorCode = 0;
    this->node_Id = nodeId;

    if(keyHandle)
    {
        VCS_SetOperationMode(this->keyHandle, this->node_Id, OMD_PROFILE_POSITION_MODE, &ErrorCode);
        VCS_SetMaxProfileVelocity(this->keyHandle, this->node_Id, MaxProfileVelocity, &ErrorCode);
        VCS_SetMaxFollowingError(this->keyHandle, this->node_Id, MaxFollowingError, &ErrorCode);
        VCS_SetMaxAcceleration(this->keyHandle, this->node_Id, MaxAcceleration, &ErrorCode);
    }
    return OK;


    //    __int8 Mode;

    //    if(keyHandle)
    //    {
    //        for(WORD nodeId = 1; nodeId<=MotorNum; nodeId++)
    //        {
    //            VCS_SetOperationMode(keyHandle, nodeId, OMD_PROFILE_POSITION_MODE, &ErrorCode);
    //            VCS_GetOperationMode(keyHandle, nodeId, &Mode, &ErrorCode);
    //            std::string temp;
    //            switch(int(Mode))
    //            {
    //            case 1:temp = "OMD_PROFILE_POSITION_MODE";break;
    //            case 3:temp = "OMD_PROFILE_VELOCITY_MODE";break;
    //            case 6:temp = "OMD_HOMING_MODE";break;
    //            case 7:temp = "OMD_INTERPOLATED_POSITION_MODE";break;
    //            case -1:temp = "OMD_POSITION_MODE";break;
    //            case -2:temp = "OMD_VELOCITY_MODE";break;
    //            case -3:temp = "OMD_CURRENT_MODE";break;
    //            case -5:temp = "OMD_MASTER_ENCODER_MODE";break;
    //            case -6:temp = "OMD_STEP_DIRECTION_MODE";break;
    //            }
    //            std::cout<<"Mode("<<nodeId<<") = "<<temp<<std::endl;

    //            VCS_SetMaxFollowingError(keyHandle, nodeId, 3000, &ErrorCode);
    //            VCS_SetMaxProfileVelocity(keyHandle, nodeId, 2000, &ErrorCode);
    //            VCS_SetMaxAcceleration(keyHandle, nodeId, 3000, &ErrorCode);
    //        }
    //    }
    //    return 1;

}

void my_maxon_motor::calibration(long m_HomeOffset, __int8 limitType, QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;
    DWORD m_SpeedSwitch = 100;
    DWORD m_SpeedIndex = 10;
    DWORD m_HomingAcceleration = 200;
    WORD m_CurrentThreshold = 500;
    long m_HomePosition = 0;


    if(VCS_SetHomingParameter(keyHandle, this->node_Id, m_HomingAcceleration,
                              m_SpeedSwitch, m_SpeedIndex, m_HomeOffset,
                              m_CurrentThreshold, m_HomePosition, &ErrorCode))
    {
        *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    }
    if(VCS_ActivateHomingMode(keyHandle, this->node_Id, &ErrorCode))
    {
        *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    }
    if(VCS_FindHome(keyHandle, this->node_Id, limitType, &ErrorCode))
    {
        *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    }


}
void my_maxon_motor::WaitForHomingAttained(QString *str_ErrorCode)
{

    DWORD ErrorCode = 0;
    if(VCS_WaitForHomingAttained(keyHandle, this->node_Id, 20000, &ErrorCode))
    {
        *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    }
}

double my_maxon_motor::getPosition(QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;
    long position = 0;
    if( VCS_GetPositionIs(this->keyHandle, this->node_Id, &position, &ErrorCode) )
    {

        return Qc2Angle(position);
    }
    *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    return 0;
}
double my_maxon_motor::getVelocity(QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;
    long velocity = 0;
    if( VCS_GetVelocityIs(this->keyHandle, this->node_Id, &velocity, &ErrorCode) )
    {

        return velocity;
    }
    *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    return 0;
}

double my_maxon_motor::getCurrent(QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;
    short current = 0;
    if( VCS_GetCurrentIs(this->keyHandle, this->node_Id, &current, &ErrorCode) )
    {
        return current;
    }
    *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    return 0;
}
bool my_maxon_motor::getEnableState(QString *str_ErrorCode)
{
    DWORD ErrorCode = 0;
    BOOL EnableState = 0;
    if( VCS_GetEnableState(this->keyHandle, this->node_Id, &EnableState, &ErrorCode) )
    {
        return EnableState;
    }
    *str_ErrorCode = "0x" + QString::number(ErrorCode,16);
    return 0;
}

bool my_maxon_motor::GetProtocalInformation(std::vector<std::string>*)
{
    std::vector<std::string> string_data;
    DWORD ErrorCode = 0;
    DWORD Baudrate = 0;
    DWORD Timeout = 0;
    const WORD MaxStrSize = 100;
    char ErrorInfo[MaxStrSize];
    char LibraryName[MaxStrSize];
    char LibraryVersion[MaxStrSize];
    char portName[MaxStrSize];



    if(keyHandle)
    {
        std::cout<<"successful"<<std::endl;
        if(VCS_GetProtocolStackSettings(keyHandle, &Baudrate, &Timeout, &ErrorCode))
        {

            std::cout<<"Baudrate = "<<Baudrate<<std::endl;
            std::cout<<"Timeout = "<<Timeout<<std::endl;
        }

        VCS_GetDriverInfo(LibraryName, MaxStrSize, LibraryVersion, MaxStrSize,
                          &ErrorCode);

        std::cout<<"LibraryName = "<<LibraryName<<std::endl;
        std::cout<<"LibraryVersion = "<<LibraryVersion<<std::endl;



        VCS_GetPortName(keyHandle, portName, MaxStrSize, &ErrorCode);
        std::cout<<"portName = "<<portName<<std::endl;



        VCS_GetErrorInfo(ErrorCode, ErrorInfo, MaxStrSize);
        if(ErrorCode)
            std::cout<<"ErrorInfo = "<<ErrorInfo<<std::endl;
        else
            std::cout<<"ErrorInfo = No Error"<<std::endl;


        long PositionMust;
        VCS_GetPositionMust(keyHandle, 1, &PositionMust, &ErrorCode);
        std::cout<<"PositionMust = "<<PositionMust<<std::endl;


    }
    return 0;


}

void my_maxon_motor::MoveToPosition(double TargetPosition, bool Absolute, QString *str_ErrorCode)
{

    DWORD ErrorCode = 0;

    TargetPosition = Angle2Qc(TargetPosition);

    if( VCS_ActivateProfilePositionMode(this->keyHandle, this->node_Id, &ErrorCode) )
    {
        int Immediately = true;

        if( !Absolute )
        {
            int PositionIs = 0;
//            if( VCS_GetPositionIs(this->keyHandle, this->node_Id, &PositionIs, &errorCode) )
//                ui.lineEditPositionStart->setText(QString("%1").arg(PositionIs));
        }
        if( !VCS_MoveToPosition(this->keyHandle, this->node_Id, TargetPosition, Absolute, Immediately, &ErrorCode) )
        {
            *str_ErrorCode = QString("Move to position failed!, error code=0x%1").arg(ErrorCode, 0, 16);
        }
    }
    else
    {
        *str_ErrorCode = QString("Activate profile position mode failed!, error code=0x%1").arg(ErrorCode, 0, 16);
    }
}
