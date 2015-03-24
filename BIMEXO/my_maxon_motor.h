#ifndef MY_MAXON_MOTOR_H
#define MY_MAXON_MOTOR_H

#include "Definitions.h"

#include <iostream>
#include <string>
#include <vector>


class my_maxon_motor
{
public:
    my_maxon_motor();
    bool openDevice();
    bool openDeviceDlg();
    void closeDevice();
    void onHome(unsigned short nodeId = 1, __int8 limitType = HM_NEGATIVE_LIMIT_SWITCH);
    void onEnableDevice(unsigned short nodeId = 1);
    void onDisableDevice();
    void onMove(unsigned short nodeId, long TargetPosition);
    long GetPosition(unsigned short nodeId = 1);
    bool GetProtocalInformation(std::vector<std::string>*);
    bool SetMaxMinFollowingError(double Max,double Min);
    bool initialization();
    void onDisableDevice(unsigned short nodeId = 1);


    static double Qc2Angle(double qc);
    static double Angle2Qc(double angle);

private:
    void* keyHandle;
    static const int HarmonicDriverRatio = 160;
    static const int MotorNum = 4;


};

#endif // MY_MAXON_MOTOR_H
