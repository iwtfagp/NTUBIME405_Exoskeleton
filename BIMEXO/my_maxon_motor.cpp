#include "my_maxon_motor.h"
#include <iomanip>
#include <iostream>
my_maxon_motor::my_maxon_motor()
{
    keyHandle = 0;
}


bool my_maxon_motor::initialization()
{
    DWORD ErrorCode = 0;
    __int8 Mode;
    if(keyHandle)
    {
        for(WORD nodeId = 1; nodeId<=MotorNum; nodeId++)
        {
            VCS_SetOperationMode(keyHandle, nodeId, OMD_POSITION_MODE, &ErrorCode);
            VCS_GetOperationMode(keyHandle, nodeId, &Mode, &ErrorCode);
            std::string temp;
            switch(int(Mode))
            {
            case 1:temp = "OMD_PROFILE_POSITION_MODE";break;
            case 3:temp = "OMD_PROFILE_VELOCITY_MODE";break;
            case 6:temp = "OMD_HOMING_MODE";break;
            case 7:temp = "OMD_INTERPOLATED_POSITION_MODE";break;
            case -1:temp = "OMD_POSITION_MODE";break;
            case -2:temp = "OMD_VELOCITY_MODE";break;
            case -3:temp = "OMD_CURRENT_MODE";break;
            case -5:temp = "OMD_MASTER_ENCODER_MODE";break;
            case -6:temp = "OMD_STEP_DIRECTION_MODE";break;
            }
            std::cout<<"Mode("<<nodeId<<") = "<<temp<<std::endl;

            VCS_SetMaxFollowingError(keyHandle, nodeId, 3000, &ErrorCode);
            VCS_SetMaxProfileVelocity(keyHandle, nodeId, 2000, &ErrorCode);
            VCS_SetMaxAcceleration(keyHandle, nodeId, 3000, &ErrorCode);
        }
    }
    return 1;

}


long my_maxon_motor::GetPosition(unsigned short nodeId)
{
    if(keyHandle)
    {

        DWORD ErrorCode = 0;
        long PositionIs = 0;

        if( VCS_GetPositionIs(keyHandle,nodeId,&PositionIs, &ErrorCode) )
        {
            //std::cout<<PositionIs<<std::endl;
        }
        return PositionIs;
        //        if( ui.lineEditPositionStart->text().toULong() == 0 )
        //			ui.lineEditPositionStart->setText(QString("%1").arg(PositionIs));

    }
    return 0;
}
bool my_maxon_motor::SetMaxMinFollowingError(double Max,double Min)
{
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



void my_maxon_motor::onHome(unsigned short nodeId,__int8 limitType)
{
    DWORD ErrorCode = 0;
    DWORD m_HomingAcceleration = 200;
    DWORD m_SpeedSwitch = 150;
    DWORD m_SpeedIndex = 30;
    long m_HomeOffset = 0;
    WORD m_CurrentThreshold = 500;
    long m_HomePosition = 0;


    VCS_SetHomingParameter(keyHandle, nodeId, m_HomingAcceleration,
                           m_SpeedSwitch, m_SpeedIndex, m_HomeOffset,
                           m_CurrentThreshold, m_HomePosition, &ErrorCode);
    VCS_ActivateHomingMode(keyHandle, nodeId, &ErrorCode);
    VCS_FindHome(keyHandle, nodeId, limitType, &ErrorCode);
    VCS_WaitForHomingAttained(keyHandle, nodeId, 20000, &ErrorCode);
    std::cout<<ErrorCode<<std::endl;

}


void my_maxon_motor::closeDevice()
{
    DWORD ErrorCode = 0;
    if(keyHandle != 0)
        VCS_CloseDevice(keyHandle, &ErrorCode);
    VCS_CloseAllDevices(&ErrorCode);
}


bool my_maxon_motor::openDevice()
{
    DWORD ErrorCode = 0;
    closeDevice();
    keyHandle = VCS_OpenDevice("EPOS2","MAXON SERIAL V2","USB","USB0",&ErrorCode);
    if( keyHandle == 0 )
    {
        std::cerr<<"Open device failure, error code=0x"<<std::hex<<ErrorCode<<std::dec<<std::endl;
        return false;
    }
    return true;
}
bool my_maxon_motor::openDeviceDlg()
{
    DWORD ErrorCode = 0;
    closeDevice();
    keyHandle = VCS_OpenDeviceDlg(&ErrorCode);
    if( keyHandle == 0 )
    {
        std::cerr<<"Open device failure, error code=0x"<<std::hex<<ErrorCode<<std::dec<<std::endl;
        return false;
    }
    return true;

}



void my_maxon_motor::onEnableDevice(unsigned short nodeId)
{
    DWORD ErrorCode = 0;

    int IsInFault = FALSE;

    if( VCS_GetFaultState(keyHandle, nodeId, &IsInFault, &ErrorCode) )
    {
        if( IsInFault && !VCS_ClearFault(keyHandle, nodeId, &ErrorCode) )
        {
            //			QString message = QString("Clear fault failed!, error code=0x%1").arg(ErrorCode,0,16);

            //			QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
            //							message);
            return;
        }

        int IsEnabled = FALSE;
        if( VCS_GetEnableState(keyHandle, nodeId, &IsEnabled, &ErrorCode) )
        {
            if( !IsEnabled && !VCS_SetEnableState(keyHandle, nodeId, &ErrorCode) )
            {
                //				QString message = QString("Set enable state failed!, error code=0x%1").arg(ErrorCode,0,16);
                //				QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
                //								message);
            }
            else
            {
                //				ui.pushButtonEnable->setEnabled(false);
                //				ui.pushButtonDisable->setEnabled(true);
                //				ui.pushButtonMove->setEnabled(true);
                //				ui.pushButtonHalt->setEnabled(true);
            }
        }
    }
    else
    {
        //		QString message = QString("Get fault state failed!, error code=0x%1").arg(ErrorCode,0,16);

        //		QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
        //						message);

    }
}

void my_maxon_motor::onDisableDevice(unsigned short nodeId)
{
    DWORD ErrorCode = 0;
    int IsInFault = FALSE;
    if( VCS_GetFaultState(keyHandle, nodeId, &IsInFault, &ErrorCode) )
    {
        if( IsInFault && !VCS_ClearFault(keyHandle, nodeId, &ErrorCode) )
        {
            return;
        }
        int IsEnabled = FALSE;
        if( VCS_GetEnableState(keyHandle, nodeId, &IsEnabled, &ErrorCode) )
        {
            VCS_SetDisableState(keyHandle, nodeId, &ErrorCode);
        }
    }

}

void my_maxon_motor::onDisableDevice()
{
    DWORD ErrorCode = 0;
    unsigned short nodeId = 1;
    int IsInFault = FALSE;

    if( VCS_GetFaultState(keyHandle, nodeId, &IsInFault, &ErrorCode) )
    {
        if( IsInFault && !VCS_ClearFault(keyHandle, nodeId, &ErrorCode) )
        {
            //			QString message = QString("Clear fault failed!, error code=0x%1").arg(ErrorCode,0,16);

            //			QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
            //							message);
            return;
        }

        int IsEnabled = FALSE;
        if( VCS_GetEnableState(keyHandle, nodeId, &IsEnabled, &ErrorCode) )
        {
            if( IsEnabled && !VCS_SetDisableState(keyHandle, nodeId, &ErrorCode) )
            {
                //				QString message = QString("Set enable state failed!, error code=0x%1").arg(ErrorCode,0,16);

                //				QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
                //								message);
            }
            else
            {
                //				ui.pushButtonEnable->setEnabled(true);
                //				ui.pushButtonDisable->setEnabled(false);
                //				ui.pushButtonMove->setEnabled(false);
                //				ui.pushButtonHalt->setEnabled(false);
            }
        }
    }
    else
    {
        //		QString message = QString("Get fault state failed!, error code=0x%1").arg(ErrorCode,0,16);

        //		QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
        //						message);

    }
}

double my_maxon_motor::Qc2Angle(double qc)
{
    return 360.0/(12800*HarmonicDriverRatio)*qc;

}
double my_maxon_motor::Angle2Qc(double angle)
{

    return 12800*HarmonicDriverRatio/360.0*angle;
}

void my_maxon_motor::onMove(unsigned short nodeId = 1, long TargetPosition = 0)
{

    DWORD errorCode = 0;

    if( VCS_ActivateProfilePositionMode(keyHandle, nodeId, &errorCode) )
    {

        int Absolute = true;
        int Immediately = TRUE;

        if( !Absolute )
        {
            //            long PositionIs = 0;

            //if( VCS_GetPositionIs(keyHandle,
            //        nodeId,
            //        &PositionIs, &errorCode) )
            //    ui.lineEditPositionStart->setText(QString("%1").arg(PositionIs));
        }

        if( !VCS_MoveToPosition(keyHandle, nodeId, TargetPosition, Absolute, Immediately, &errorCode) )
        {
            //    		QString message = QString("Move to position failed!, error code=0x%1").arg(errorCode, 0, 16);

            //			QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
            //									message);

        }
    }
    else
    {
        //    	QString message = QString("Activate profile position mode failed!, error code=0x%1").arg(errorCode, 0, 16);

        //    	QMessageBox::critical(this, "QT Demo using EPOS Linux shared library",
        //    							message);
    }
}
