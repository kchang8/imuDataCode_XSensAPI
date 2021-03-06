/*	Copyright (c) 2003-2016 Xsens Technologies B.V. or subsidiaries worldwide.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification,
	are permitted provided that the following conditions are met:

	1.	Redistributions of source code must retain the above copyright notice,
		this list of conditions and the following disclaimer.

	2.	Redistributions in binary form must reproduce the above copyright notice,
		this list of conditions and the following disclaimer in the documentation
		and/or other materials provided with the distribution.

	3.	Neither the names of the copyright holders nor the names of their contributors
		may be used to endorse or promote products derived from this software without
		specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
	EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
	MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
	THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
	OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY OR
	TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MYXDA_H
#define MYXDA_H

#include <xsens/xscallback.h>
#include <map>

struct XsControl;
struct XsDevice;

class MyXda : public XsCallback
{
public:
	MyXda();
	virtual ~MyXda();

	void openPorts();

	int getUserUpdateRate();
	void setUpdateRate(int updateRate);

	enum DisplayMode
	{
		DM_None,
		DM_OrientationEuler,
		DM_OrientationQuaternion,
		DM_Sdi,
		DM_OrientationMatrix,
		DM_LatLonAlt,       // ** ADDED THIS DISPLAY MODE TO SHOW LAT LONG ALT
		DM_UtcTime,			// ** ATTEMPTED TO DISPLAY UTC TIME
	};

	void setDisplayMode(DisplayMode displayMode);
	inline XsControl* xsControl() const { return m_xsControl; }

protected:
	virtual void onDataAvailable(XsDevice*, const XsDataPacket* packet);

private:
	void clearMeasurementScreen();
	void printDisplayMode();

	XsControl* m_xsControl;
	int m_connectCount;
	std::map<uint32_t, int> m_connectedDevices;
	volatile bool m_stationReady;
	DisplayMode m_displayMode;
	DisplayMode m_previousDisplayMode;
};

#endif	// MYXDA_H
