# imuDataCode_XSensAPI

*The folder of the files that I have added to this repository is just to show you the changes I have made to each of the files listed down below. You will have to clone this repository and replace the whole folder to get the new changes OR see the changes I have added to these files and add it to your own files.*

# Downloading MT Software Suite
1. Download the application using this link https://www.xsens.com/software-downloads. 
2. You can download the latest stable software under MTi Products Category. This application will allow you to visualize the IMU sensor data and get the code to edit/view to display different data that it provides from the API.

# MT Suite Folder
1. The folder will provide you with all the documentation about the application, the MT Manager interface for you to visualize the sensor data, and example codes in the MT SDK folder.
2. Go to MT SDK -> Examples -> xda_c_cpp -> dll_example_mtix_cpp.vcxproj (you can press any vcxproj file and it will open up the same scripts)
3. When you open the file in visual studio, it will show you 4 different project folders. You can focus on "XSensDeviceAPI Command Line Generic Example". 
4. When you run the code, by default it should let you view 5 different types of data from the sensor: Orientation in Euler Angles (aka pitch, yaw, and roll) , Orientation in Quarternion, Orientation in Matrix, Orientation Sdi, and Raw Data for showing accelerometer, gyroscope, and magnetometer data.
5. As you can see, it does not show timestamps and position data that we need in order to generate point clouds for mapping. Therefore, we need to add those data in using the API provided in the code already.
6. Here are some files that I have changed in order to add the position data for getting latitude, longitude, and altitude:
   
   **Header Files**:
   - xsmtmk4displayer.h  -  this file contains all the functions that are used to set different data. I added comments in where I made changes. For each XDI data, you can right click on any one of them -> go to definition to see all the different kinds of data that the API provides for the sensor. 
   - xsmtixdisplayer.h  -  this file is pretty similar to the xsmtmk4displayer, so you can just follow the same procedures in how the file is written. The only difference is the XOS data. The different XOS data can be viewed the same way as the XDI data, right click on any one of them -> go to definition. This will show you all the differetnt XOS data, you will have to choose the one that matches the data you are trying to get.
   - myxda.h  -  this file lets you add the different display modes from the functions/data that is created. For each new data that you want to show, you will have to just add it to the enum Displaymode. 
   - xmtdisplayer.h  -  this file goes more in depth on the functions/data to be displayed. You will have to add the set functions you made of the new data to be added and create streamer instances of each of them to be defined/formatted later in the next header file. I added comments here too to let you see how they are to be made.
   - xspacketstreamer.h  -  this file lets you format how the data is to be displayed using the API. It uses the streamer instances you made from xmtdisplayer.h and defines them more in this file. I added comments in the sections of where I added/formatted the position data. Here it gets a little tricky in knowing what kind of Xs class you will need to use to show that certain data. You will have to just look around and right click -> go to definition to see the different functions the class provides to see if it has the function that shows your data that you want to add. You can also go to the documentation folder to see what kind of functions each Xs class provides. 
   
    **CPP FILES**:
    - myxda.cpp  -  this file goes more in depth in defining/formatting the display modes that you have created in the myxda.h file. You have to set cases for each display mode added in the printDisplayMode function. In the onDataAvailable function, here is where you use the API functions to format the data to be displayed. I added comments on where I added and formatted the position data.
  
  7. Once you made changes to all the files accordingly, you can try running the code to see if it will display the new added data
  8. Overall, you can look at the documentation for all the classes and functions that the API provides from the documentation folder. Documentation -> MT SDK -> xsensdeviceapi (or xstypes)
  
  **NOTE:** I only got the position data to show and I was still attempting get the UTC time to get the timestamp data. 
